#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <boost/smart_ptr.hpp>
#include <boost/unordered_set.hpp>

#include <percona_playback/audit_log/audit_log_entry.h>

#include <percona_playback/audit_log/parse_audit_log.h>

class AuditLogQueryEntries : public QueryEntries {
public:
  typedef std::vector<boost::shared_ptr<AuditLogEntry> > Entries;
  Entries entries;
  Entries::size_type pos;

  AuditLogQueryEntries() : pos(0) {}

  virtual boost::shared_ptr<QueryEntry> popEntry() {
    boost::shared_ptr<QueryEntry> entry;
    if (pos < entries.size()) {
      entry = entries[pos++];
    }
    return entry;
  }

  virtual void setShutdownOnLastQueryOfConn() {
    // automatically close threads after last request
    boost::unordered_set<uint64_t> thread_ids;
    for (Entries::reverse_iterator it = entries.rbegin(), end = entries.rend(); it != end; ++it) {
      if (thread_ids.insert((*it)->getThreadId()).second)
        (*it)->set_shutdown();
    }
  }
};

boost::shared_ptr<QueryEntries> ParseAuditLog::getEntries()
{
    boost::shared_ptr<AuditLogQueryEntries> entries = boost::make_shared<AuditLogQueryEntries>();
    boost::shared_ptr<AuditLogEntry> tmp_entry = boost::make_shared<AuditLogEntry>();

    char *line= NULL;
    size_t buflen = 0;
    ssize_t len;

    if (next_line)
    {
        line = next_line;
        len = next_len;
        next_line = NULL;
        next_len = 0;
    }
    else if ((len = getline(&line, &buflen, input_file)) == -1)
    {
        return entries;
    }

    char *p = line;
    char *q;
    bool ignoreLine = false;

    do
    {
        q = line + len;
        ignoreLine = false;

        if ( p[0] == '#' ||
            (p[0] != '#' && (
                (( (q - p) >= (ssize_t)strlen("started with:\n")) && strncmp(q - strlen("started with:\n"), "started with:", strlen("started with:")) == 0) ||
                (strncmp(p, "Tcp port: ", strlen("Tcp port: ")) == 0) ||
                (strncmp(p, "Time Id Command Argument", strlen("Time Id Command Argument")) == 0)
            )))
        {
            ignoreLine = true;
        }

        if (!ignoreLine)
        {
            tmp_entry->add_query_line(std::string(line), schema_name);
            if (!tmp_entry->getQuery().empty())
            {
                entries->entries.push_back(tmp_entry);
                tmp_entry.reset(new AuditLogEntry());
            }
        }

        if (!next_line && ((len = getline(&line, &buflen, input_file)) == -1))
        {
            break;
        }

        next_line = NULL;
        p = line;
    } while(true);

    free(line);

    entries->setNumEntries(entries->entries.size());
    entries->setNumQueries(entries->entries.size());

    return entries;
}
