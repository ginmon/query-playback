# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/usman/dev/query-playback

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/usman/dev/query-playback/build_dir

# Include any dependencies generated for this target.
include percona_playback/test/CMakeFiles/test-basic-stdin.dir/depend.make

# Include the progress variables for this target.
include percona_playback/test/CMakeFiles/test-basic-stdin.dir/progress.make

# Include the compile flags for this target's objects.
include percona_playback/test/CMakeFiles/test-basic-stdin.dir/flags.make

percona_playback/test/CMakeFiles/test-basic-stdin.dir/basic-stdin.cc.o: percona_playback/test/CMakeFiles/test-basic-stdin.dir/flags.make
percona_playback/test/CMakeFiles/test-basic-stdin.dir/basic-stdin.cc.o: ../percona_playback/test/basic-stdin.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/usman/dev/query-playback/build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object percona_playback/test/CMakeFiles/test-basic-stdin.dir/basic-stdin.cc.o"
	cd /home/usman/dev/query-playback/build_dir/percona_playback/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test-basic-stdin.dir/basic-stdin.cc.o -c /home/usman/dev/query-playback/percona_playback/test/basic-stdin.cc

percona_playback/test/CMakeFiles/test-basic-stdin.dir/basic-stdin.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test-basic-stdin.dir/basic-stdin.cc.i"
	cd /home/usman/dev/query-playback/build_dir/percona_playback/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/usman/dev/query-playback/percona_playback/test/basic-stdin.cc > CMakeFiles/test-basic-stdin.dir/basic-stdin.cc.i

percona_playback/test/CMakeFiles/test-basic-stdin.dir/basic-stdin.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test-basic-stdin.dir/basic-stdin.cc.s"
	cd /home/usman/dev/query-playback/build_dir/percona_playback/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/usman/dev/query-playback/percona_playback/test/basic-stdin.cc -o CMakeFiles/test-basic-stdin.dir/basic-stdin.cc.s

percona_playback/test/CMakeFiles/test-basic-stdin.dir/basic-stdin.cc.o.requires:

.PHONY : percona_playback/test/CMakeFiles/test-basic-stdin.dir/basic-stdin.cc.o.requires

percona_playback/test/CMakeFiles/test-basic-stdin.dir/basic-stdin.cc.o.provides: percona_playback/test/CMakeFiles/test-basic-stdin.dir/basic-stdin.cc.o.requires
	$(MAKE) -f percona_playback/test/CMakeFiles/test-basic-stdin.dir/build.make percona_playback/test/CMakeFiles/test-basic-stdin.dir/basic-stdin.cc.o.provides.build
.PHONY : percona_playback/test/CMakeFiles/test-basic-stdin.dir/basic-stdin.cc.o.provides

percona_playback/test/CMakeFiles/test-basic-stdin.dir/basic-stdin.cc.o.provides.build: percona_playback/test/CMakeFiles/test-basic-stdin.dir/basic-stdin.cc.o


# Object files for target test-basic-stdin
test__basic__stdin_OBJECTS = \
"CMakeFiles/test-basic-stdin.dir/basic-stdin.cc.o"

# External object files for target test-basic-stdin
test__basic__stdin_EXTERNAL_OBJECTS =

percona_playback/test/test-basic-stdin: percona_playback/test/CMakeFiles/test-basic-stdin.dir/basic-stdin.cc.o
percona_playback/test/test-basic-stdin: percona_playback/test/CMakeFiles/test-basic-stdin.dir/build.make
percona_playback/test/test-basic-stdin: percona_playback/liblibpercona-playback.a
percona_playback/test/test-basic-stdin: percona_playback/audit_log/libaudit_log.a
percona_playback/test/test-basic-stdin: percona_playback/error_report/liberror_report.a
percona_playback/test/test-basic-stdin: percona_playback/full_report/libfull_report.a
percona_playback/test/test-basic-stdin: percona_playback/general_log/libgeneral_log.a
percona_playback/test/test-basic-stdin: percona_playback/mysql_client/libmysql_client.a
percona_playback/test/test-basic-stdin: /usr/lib/x86_64-linux-gnu/libmysqlclient.so
percona_playback/test/test-basic-stdin: percona_playback/null_dbclient/libnull_dbclient.a
percona_playback/test/test-basic-stdin: percona_playback/query_log/libquery_log.a
percona_playback/test/test-basic-stdin: percona_playback/simple_report/libsimple_report.a
percona_playback/test/test-basic-stdin: percona_playback/thread_per_connection/libthread_per_connection.a
percona_playback/test/test-basic-stdin: percona_playback/thread_pool/libthread_pool.a
percona_playback/test/test-basic-stdin: percona_playback/libdb_thread.a
percona_playback/test/test-basic-stdin: /usr/lib/x86_64-linux-gnu/libboost_system.so
percona_playback/test/test-basic-stdin: /usr/lib/x86_64-linux-gnu/libboost_thread.so
percona_playback/test/test-basic-stdin: /usr/lib/x86_64-linux-gnu/libboost_regex.so
percona_playback/test/test-basic-stdin: /usr/lib/x86_64-linux-gnu/libboost_program_options.so
percona_playback/test/test-basic-stdin: /usr/lib/x86_64-linux-gnu/libboost_chrono.so
percona_playback/test/test-basic-stdin: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
percona_playback/test/test-basic-stdin: /usr/lib/x86_64-linux-gnu/libboost_atomic.so
percona_playback/test/test-basic-stdin: /usr/lib/x86_64-linux-gnu/libpthread.so
percona_playback/test/test-basic-stdin: percona_playback/test/CMakeFiles/test-basic-stdin.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/usman/dev/query-playback/build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test-basic-stdin"
	cd /home/usman/dev/query-playback/build_dir/percona_playback/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test-basic-stdin.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
percona_playback/test/CMakeFiles/test-basic-stdin.dir/build: percona_playback/test/test-basic-stdin

.PHONY : percona_playback/test/CMakeFiles/test-basic-stdin.dir/build

percona_playback/test/CMakeFiles/test-basic-stdin.dir/requires: percona_playback/test/CMakeFiles/test-basic-stdin.dir/basic-stdin.cc.o.requires

.PHONY : percona_playback/test/CMakeFiles/test-basic-stdin.dir/requires

percona_playback/test/CMakeFiles/test-basic-stdin.dir/clean:
	cd /home/usman/dev/query-playback/build_dir/percona_playback/test && $(CMAKE_COMMAND) -P CMakeFiles/test-basic-stdin.dir/cmake_clean.cmake
.PHONY : percona_playback/test/CMakeFiles/test-basic-stdin.dir/clean

percona_playback/test/CMakeFiles/test-basic-stdin.dir/depend:
	cd /home/usman/dev/query-playback/build_dir && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/usman/dev/query-playback /home/usman/dev/query-playback/percona_playback/test /home/usman/dev/query-playback/build_dir /home/usman/dev/query-playback/build_dir/percona_playback/test /home/usman/dev/query-playback/build_dir/percona_playback/test/CMakeFiles/test-basic-stdin.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : percona_playback/test/CMakeFiles/test-basic-stdin.dir/depend

