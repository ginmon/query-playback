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
#include <algorithm> 

#include <percona_playback/percona_playback.h>
#include <percona_playback/plugin.h>

#include <percona_playback/audit_log/audit_log_entry.h>
#include <percona_playback/query_result.h>

#include <boost/foreach.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/regex.hpp>
#include <boost/tokenizer.hpp>
#include <boost/algorithm/string.hpp>


void AuditLogEntry::execute(DBThread *t)
{
  std::vector<std::string>::iterator it;
  QueryResult r;

  QueryResult expected_result;
  expected_result.setRowsSent(rows_sent);
  expected_result.setRowsExamined(rows_examined);
  expected_result.setError(0);

  boost::posix_time::time_duration expected_duration = boost::posix_time::microseconds(long(query_time * 1000000));
  expected_result.setDuration(expected_duration);

  boost::posix_time::ptime start_time;
  start_time= boost::posix_time::microsec_clock::universal_time();

  t->execute_query(query, &r, expected_result);

  boost::posix_time::ptime end_time;
  end_time= boost::posix_time::microsec_clock::universal_time();

  boost::posix_time::time_period duration(start_time, end_time);
  r.setDuration(duration.length());

  BOOST_FOREACH(const percona_playback::PluginRegistry::ReportPluginPair pp, percona_playback::PluginRegistry::singleton().report_plugins)
  {
    if (pp.second->active)
      pp.second->query_execution(getThreadId(), query, expected_result, r);
  }
}

void AuditLogEntry::add_query_line(const std::string &s, const std::string &schema_name)
{
    typedef boost::tokenizer<boost::escaped_list_separator<char> > Tokenizer;
    
    std::vector<std::string> vec;
    
    Tokenizer tok(s, boost::escaped_list_separator<char>('\\', ',', '\''));
    vec.assign(tok.begin(),tok.end());

    if (vec.size() < 10) return;

    std::string buf = vec[0];
    std::vector<std::string> dataTime;
    boost::trim_if(buf, boost::is_any_of("\t ")); // could also use plain boost::trim
    boost::split(dataTime, buf, boost::is_any_of("\t "), boost::token_compress_on);

    if(boost::iequals(vec[6], "QUERY") && !boost::iequals(vec[7], schema_name)){
        //std::cout << "LINE [ at: " << dataTime[1] << " - Query: " << vec[8] << "]" << std::endl;

        set_timestamp_query.append(dataTime[1]);

        query.append(vec[8]);
        query.append(" ");
    }
    
         
/*
    boost::regex re("\\s+(\\d+)\\s+Query\\s+(.+)");
    boost::smatch fields;

    //std::cout << "LINE [" << s << "]" << std::endl;

    if (boost::regex_search(s, fields, re))
    {
        //0 whole string
        //1 Thread id
        //2 query
        std::string ns = fields[2].str();
        std::string::const_iterator begin = ns.begin();
        std::string::const_iterator end = ns.end() - 1;
        if (ns.length() >= 2 && *(ns.end() - 2) == '\r')
            --end;

        //std::cout << "MATCHING THREADID [" << fields[1] << "] QUERY [" << fields[2] << "]" << std::endl;
        thread_id = strtoull(fields[1].str().c_str(), NULL, 10);
        query.append(begin, end);
        query.append(" ");
    }*/
}


