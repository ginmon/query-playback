#ifndef PERCONA_PLAYBACK_AUDIT_LOG_H
#define PERCONA_PLAYBACK_AUDIT_LOG_H

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

#include <boost/program_options.hpp>
#include <boost/thread.hpp>

#ifdef __cplusplus
extern "C"
{
#endif

namespace po= boost::program_options;

class AuditLogPlugin : public percona_playback::InputPlugin
{
    private:
        po::options_description     options;
        std::string                 file_name;
        std::string                 schema_name;
        unsigned int                read_count;
        bool			            std_in;

    public:
        AuditLogPlugin(const std::string &_name);

        boost::program_options::options_description* getProgramOptions();

        int processOptions(boost::program_options::variables_map &vm);

        void run(percona_playback_run_result &result);
};


#ifdef __cplusplus
}
#endif

#endif /* PERCONA_PLAYBACK_AUDIT_LOG_H */
