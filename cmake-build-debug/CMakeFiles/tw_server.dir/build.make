# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/g/FH/WS24/VERTS/tw-mailer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/g/FH/WS24/VERTS/tw-mailer/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/tw_server.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/tw_server.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/tw_server.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tw_server.dir/flags.make

CMakeFiles/tw_server.dir/MailServer.cpp.o: CMakeFiles/tw_server.dir/flags.make
CMakeFiles/tw_server.dir/MailServer.cpp.o: ../MailServer.cpp
CMakeFiles/tw_server.dir/MailServer.cpp.o: CMakeFiles/tw_server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/g/FH/WS24/VERTS/tw-mailer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tw_server.dir/MailServer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tw_server.dir/MailServer.cpp.o -MF CMakeFiles/tw_server.dir/MailServer.cpp.o.d -o CMakeFiles/tw_server.dir/MailServer.cpp.o -c /mnt/g/FH/WS24/VERTS/tw-mailer/MailServer.cpp

CMakeFiles/tw_server.dir/MailServer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tw_server.dir/MailServer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/g/FH/WS24/VERTS/tw-mailer/MailServer.cpp > CMakeFiles/tw_server.dir/MailServer.cpp.i

CMakeFiles/tw_server.dir/MailServer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tw_server.dir/MailServer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/g/FH/WS24/VERTS/tw-mailer/MailServer.cpp -o CMakeFiles/tw_server.dir/MailServer.cpp.s

CMakeFiles/tw_server.dir/src/Server/Server.cpp.o: CMakeFiles/tw_server.dir/flags.make
CMakeFiles/tw_server.dir/src/Server/Server.cpp.o: ../src/Server/Server.cpp
CMakeFiles/tw_server.dir/src/Server/Server.cpp.o: CMakeFiles/tw_server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/g/FH/WS24/VERTS/tw-mailer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/tw_server.dir/src/Server/Server.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tw_server.dir/src/Server/Server.cpp.o -MF CMakeFiles/tw_server.dir/src/Server/Server.cpp.o.d -o CMakeFiles/tw_server.dir/src/Server/Server.cpp.o -c /mnt/g/FH/WS24/VERTS/tw-mailer/src/Server/Server.cpp

CMakeFiles/tw_server.dir/src/Server/Server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tw_server.dir/src/Server/Server.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/g/FH/WS24/VERTS/tw-mailer/src/Server/Server.cpp > CMakeFiles/tw_server.dir/src/Server/Server.cpp.i

CMakeFiles/tw_server.dir/src/Server/Server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tw_server.dir/src/Server/Server.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/g/FH/WS24/VERTS/tw-mailer/src/Server/Server.cpp -o CMakeFiles/tw_server.dir/src/Server/Server.cpp.s

CMakeFiles/tw_server.dir/src/Shared/Message.cpp.o: CMakeFiles/tw_server.dir/flags.make
CMakeFiles/tw_server.dir/src/Shared/Message.cpp.o: ../src/Shared/Message.cpp
CMakeFiles/tw_server.dir/src/Shared/Message.cpp.o: CMakeFiles/tw_server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/g/FH/WS24/VERTS/tw-mailer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/tw_server.dir/src/Shared/Message.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tw_server.dir/src/Shared/Message.cpp.o -MF CMakeFiles/tw_server.dir/src/Shared/Message.cpp.o.d -o CMakeFiles/tw_server.dir/src/Shared/Message.cpp.o -c /mnt/g/FH/WS24/VERTS/tw-mailer/src/Shared/Message.cpp

CMakeFiles/tw_server.dir/src/Shared/Message.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tw_server.dir/src/Shared/Message.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/g/FH/WS24/VERTS/tw-mailer/src/Shared/Message.cpp > CMakeFiles/tw_server.dir/src/Shared/Message.cpp.i

CMakeFiles/tw_server.dir/src/Shared/Message.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tw_server.dir/src/Shared/Message.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/g/FH/WS24/VERTS/tw-mailer/src/Shared/Message.cpp -o CMakeFiles/tw_server.dir/src/Shared/Message.cpp.s

CMakeFiles/tw_server.dir/src/Server/ServerHandler.cpp.o: CMakeFiles/tw_server.dir/flags.make
CMakeFiles/tw_server.dir/src/Server/ServerHandler.cpp.o: ../src/Server/ServerHandler.cpp
CMakeFiles/tw_server.dir/src/Server/ServerHandler.cpp.o: CMakeFiles/tw_server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/g/FH/WS24/VERTS/tw-mailer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/tw_server.dir/src/Server/ServerHandler.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tw_server.dir/src/Server/ServerHandler.cpp.o -MF CMakeFiles/tw_server.dir/src/Server/ServerHandler.cpp.o.d -o CMakeFiles/tw_server.dir/src/Server/ServerHandler.cpp.o -c /mnt/g/FH/WS24/VERTS/tw-mailer/src/Server/ServerHandler.cpp

CMakeFiles/tw_server.dir/src/Server/ServerHandler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tw_server.dir/src/Server/ServerHandler.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/g/FH/WS24/VERTS/tw-mailer/src/Server/ServerHandler.cpp > CMakeFiles/tw_server.dir/src/Server/ServerHandler.cpp.i

CMakeFiles/tw_server.dir/src/Server/ServerHandler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tw_server.dir/src/Server/ServerHandler.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/g/FH/WS24/VERTS/tw-mailer/src/Server/ServerHandler.cpp -o CMakeFiles/tw_server.dir/src/Server/ServerHandler.cpp.s

CMakeFiles/tw_server.dir/src/Shared/NetUtilities.cpp.o: CMakeFiles/tw_server.dir/flags.make
CMakeFiles/tw_server.dir/src/Shared/NetUtilities.cpp.o: ../src/Shared/NetUtilities.cpp
CMakeFiles/tw_server.dir/src/Shared/NetUtilities.cpp.o: CMakeFiles/tw_server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/g/FH/WS24/VERTS/tw-mailer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/tw_server.dir/src/Shared/NetUtilities.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tw_server.dir/src/Shared/NetUtilities.cpp.o -MF CMakeFiles/tw_server.dir/src/Shared/NetUtilities.cpp.o.d -o CMakeFiles/tw_server.dir/src/Shared/NetUtilities.cpp.o -c /mnt/g/FH/WS24/VERTS/tw-mailer/src/Shared/NetUtilities.cpp

CMakeFiles/tw_server.dir/src/Shared/NetUtilities.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tw_server.dir/src/Shared/NetUtilities.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/g/FH/WS24/VERTS/tw-mailer/src/Shared/NetUtilities.cpp > CMakeFiles/tw_server.dir/src/Shared/NetUtilities.cpp.i

CMakeFiles/tw_server.dir/src/Shared/NetUtilities.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tw_server.dir/src/Shared/NetUtilities.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/g/FH/WS24/VERTS/tw-mailer/src/Shared/NetUtilities.cpp -o CMakeFiles/tw_server.dir/src/Shared/NetUtilities.cpp.s

CMakeFiles/tw_server.dir/src/Server/MailManager/MailManager.cpp.o: CMakeFiles/tw_server.dir/flags.make
CMakeFiles/tw_server.dir/src/Server/MailManager/MailManager.cpp.o: ../src/Server/MailManager/MailManager.cpp
CMakeFiles/tw_server.dir/src/Server/MailManager/MailManager.cpp.o: CMakeFiles/tw_server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/g/FH/WS24/VERTS/tw-mailer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/tw_server.dir/src/Server/MailManager/MailManager.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tw_server.dir/src/Server/MailManager/MailManager.cpp.o -MF CMakeFiles/tw_server.dir/src/Server/MailManager/MailManager.cpp.o.d -o CMakeFiles/tw_server.dir/src/Server/MailManager/MailManager.cpp.o -c /mnt/g/FH/WS24/VERTS/tw-mailer/src/Server/MailManager/MailManager.cpp

CMakeFiles/tw_server.dir/src/Server/MailManager/MailManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tw_server.dir/src/Server/MailManager/MailManager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/g/FH/WS24/VERTS/tw-mailer/src/Server/MailManager/MailManager.cpp > CMakeFiles/tw_server.dir/src/Server/MailManager/MailManager.cpp.i

CMakeFiles/tw_server.dir/src/Server/MailManager/MailManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tw_server.dir/src/Server/MailManager/MailManager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/g/FH/WS24/VERTS/tw-mailer/src/Server/MailManager/MailManager.cpp -o CMakeFiles/tw_server.dir/src/Server/MailManager/MailManager.cpp.s

# Object files for target tw_server
tw_server_OBJECTS = \
"CMakeFiles/tw_server.dir/MailServer.cpp.o" \
"CMakeFiles/tw_server.dir/src/Server/Server.cpp.o" \
"CMakeFiles/tw_server.dir/src/Shared/Message.cpp.o" \
"CMakeFiles/tw_server.dir/src/Server/ServerHandler.cpp.o" \
"CMakeFiles/tw_server.dir/src/Shared/NetUtilities.cpp.o" \
"CMakeFiles/tw_server.dir/src/Server/MailManager/MailManager.cpp.o"

# External object files for target tw_server
tw_server_EXTERNAL_OBJECTS =

tw_server: CMakeFiles/tw_server.dir/MailServer.cpp.o
tw_server: CMakeFiles/tw_server.dir/src/Server/Server.cpp.o
tw_server: CMakeFiles/tw_server.dir/src/Shared/Message.cpp.o
tw_server: CMakeFiles/tw_server.dir/src/Server/ServerHandler.cpp.o
tw_server: CMakeFiles/tw_server.dir/src/Shared/NetUtilities.cpp.o
tw_server: CMakeFiles/tw_server.dir/src/Server/MailManager/MailManager.cpp.o
tw_server: CMakeFiles/tw_server.dir/build.make
tw_server: CMakeFiles/tw_server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/g/FH/WS24/VERTS/tw-mailer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable tw_server"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tw_server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tw_server.dir/build: tw_server
.PHONY : CMakeFiles/tw_server.dir/build

CMakeFiles/tw_server.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tw_server.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tw_server.dir/clean

CMakeFiles/tw_server.dir/depend:
	cd /mnt/g/FH/WS24/VERTS/tw-mailer/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/g/FH/WS24/VERTS/tw-mailer /mnt/g/FH/WS24/VERTS/tw-mailer /mnt/g/FH/WS24/VERTS/tw-mailer/cmake-build-debug /mnt/g/FH/WS24/VERTS/tw-mailer/cmake-build-debug /mnt/g/FH/WS24/VERTS/tw-mailer/cmake-build-debug/CMakeFiles/tw_server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tw_server.dir/depend

