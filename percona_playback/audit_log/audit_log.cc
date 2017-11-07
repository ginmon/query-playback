#include "config.h"

#include <stdlib.h>
#include <string>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <stdint.h>
#include <assert.h>
#include <unistd.h>
#include <vector>

#include <percona_playback/visibility.h>
#include <percona_playback/percona_playback.h>
#include <percona_playback/plugin.h>
#include <percona_playback/audit_log/audit_log.h>
#include <percona_playback/audit_log/audit_log_entry.h>
#include <percona_playback/audit_log/parse_audit_log.h>

#include <boost/program_options.hpp>
#include <boost/thread.hpp>

#include <tbb/atomic.h>

extern percona_playback::DBClientPlugin *g_dbclient_plugin;
extern percona_playback::DispatcherPlugin *g_dispatcher_plugin;

static void AuditLogReaderThread(FILE *input_file, const std::string &schema_name, unsigned int run_count, struct percona_playback_run_result *r)
{
  boost::shared_ptr<QueryEntries> entry_vec = ParseAuditLog(input_file, schema_name, run_count).getEntries();
  g_dispatcher_plugin->dispatch(entry_vec);

  g_dispatcher_plugin->finish_all_and_wait();

  r->n_log_entries = entry_vec->getNumEntries();
  r->n_queries = entry_vec->getNumQueries();
}

PERCONA_PLAYBACK_API
int run_query_log(const std::string &log_file, unsigned int read_count, struct percona_playback_run_result *r);

AuditLogPlugin::AuditLogPlugin(const std::string &_name) : InputPlugin(_name),
                                                           options(_("Audit Log Options")),
                                                           read_count(1),
                                                           std_in(false){};

boost::program_options::options_description *AuditLogPlugin::getProgramOptions()
{
  options.add_options()("audit-log-file", po::value<std::string>(), _("Audit log file"))
                       ("audit-log-stdin", po::value<bool>()->default_value(false)->zero_tokens(), _("Read audit log from stdin"))
                       ("audit-log-schema", po::value<std::string>(), _("Read audit log from schema"));

  return &options;
}

int AuditLogPlugin::processOptions(boost::program_options::variables_map &vm)
{
  if (!active && (vm.count("audit-log-file") || !vm["audit-log-stdin"].defaulted()))
  {
    fprintf(stderr, _(("audit-log plugin is not selected, you shouldn't use this plugin-related command line options\n")));
    return -1;
  }

  if (!active)
    return 0;

  if (vm.count("audit-log-file") && vm["audit-log-stdin"].as<bool>())
  {
    fprintf(stderr, _(("The options --audit-log-file and --audit-log-stdin can not be used together\n")));
    return -1;
  }

  if (vm.count("audit-log-file"))
    file_name = vm["audit-log-file"].as<std::string>();
  else if (vm["audit-log-stdin"].as<bool>())
  {
    std_in = true;
  }
  else
  {
    fprintf(stderr, _("ERROR: --audit-log-file is a required option.\n"));
    return -1;
  }

  if (vm.count("audit-log-schema"))
    schema_name = vm["audit-log-schema"].as<std::string>();
  else
  {
    schema_name = "";
  }

  return 0;
}

void AuditLogPlugin::run(percona_playback_run_result &result)
{
  FILE *input_file;

  if (std_in)
  {
    input_file = stdin;
  }
  else
  {
    input_file = fopen(file_name.c_str(), "r");
    if (input_file == NULL)
    {
      fprintf(stderr,
              _("ERROR: Error opening file '%s': %s"),
              file_name.c_str(), strerror(errno));
      return;
    }
  }

  boost::thread log_reader_thread(AuditLogReaderThread, input_file, schema_name, read_count, &result);

  log_reader_thread.join();
  fclose(input_file);
}

static void init(percona_playback::PluginRegistry &r)
{
  r.add("audit-log", new AuditLogPlugin("audit-log"));
}

PERCONA_PLAYBACK_PLUGIN(init);
