# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_BINARY_DIR = /mnt/g/FH/WS24/VERTS/tw-mailer

# Include any dependencies generated for this target.
include CMakeFiles/tw_client2.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/tw_client2.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/tw_client2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tw_client2.dir/flags.make

CMakeFiles/tw_client2.dir/MailClient.cpp.o: CMakeFiles/tw_client2.dir/flags.make
CMakeFiles/tw_client2.dir/MailClient.cpp.o: MailClient.cpp
CMakeFiles/tw_client2.dir/MailClient.cpp.o: CMakeFiles/tw_client2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/g/FH/WS24/VERTS/tw-mailer/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tw_client2.dir/MailClient.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tw_client2.dir/MailClient.cpp.o -MF CMakeFiles/tw_client2.dir/MailClient.cpp.o.d -o CMakeFiles/tw_client2.dir/MailClient.cpp.o -c /mnt/g/FH/WS24/VERTS/tw-mailer/MailClient.cpp

CMakeFiles/tw_client2.dir/MailClient.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/tw_client2.dir/MailClient.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/g/FH/WS24/VERTS/tw-mailer/MailClient.cpp > CMakeFiles/tw_client2.dir/MailClient.cpp.i

CMakeFiles/tw_client2.dir/MailClient.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/tw_client2.dir/MailClient.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/g/FH/WS24/VERTS/tw-mailer/MailClient.cpp -o CMakeFiles/tw_client2.dir/MailClient.cpp.s

CMakeFiles/tw_client2.dir/src/Client/Client.cpp.o: CMakeFiles/tw_client2.dir/flags.make
CMakeFiles/tw_client2.dir/src/Client/Client.cpp.o: src/Client/Client.cpp
CMakeFiles/tw_client2.dir/src/Client/Client.cpp.o: CMakeFiles/tw_client2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/g/FH/WS24/VERTS/tw-mailer/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/tw_client2.dir/src/Client/Client.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tw_client2.dir/src/Client/Client.cpp.o -MF CMakeFiles/tw_client2.dir/src/Client/Client.cpp.o.d -o CMakeFiles/tw_client2.dir/src/Client/Client.cpp.o -c /mnt/g/FH/WS24/VERTS/tw-mailer/src/Client/Client.cpp

CMakeFiles/tw_client2.dir/src/Client/Client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/tw_client2.dir/src/Client/Client.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/g/FH/WS24/VERTS/tw-mailer/src/Client/Client.cpp > CMakeFiles/tw_client2.dir/src/Client/Client.cpp.i

CMakeFiles/tw_client2.dir/src/Client/Client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/tw_client2.dir/src/Client/Client.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/g/FH/WS24/VERTS/tw-mailer/src/Client/Client.cpp -o CMakeFiles/tw_client2.dir/src/Client/Client.cpp.s

CMakeFiles/tw_client2.dir/src/Shared/Message.cpp.o: CMakeFiles/tw_client2.dir/flags.make
CMakeFiles/tw_client2.dir/src/Shared/Message.cpp.o: src/Shared/Message.cpp
CMakeFiles/tw_client2.dir/src/Shared/Message.cpp.o: CMakeFiles/tw_client2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/g/FH/WS24/VERTS/tw-mailer/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/tw_client2.dir/src/Shared/Message.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tw_client2.dir/src/Shared/Message.cpp.o -MF CMakeFiles/tw_client2.dir/src/Shared/Message.cpp.o.d -o CMakeFiles/tw_client2.dir/src/Shared/Message.cpp.o -c /mnt/g/FH/WS24/VERTS/tw-mailer/src/Shared/Message.cpp

CMakeFiles/tw_client2.dir/src/Shared/Message.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/tw_client2.dir/src/Shared/Message.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/g/FH/WS24/VERTS/tw-mailer/src/Shared/Message.cpp > CMakeFiles/tw_client2.dir/src/Shared/Message.cpp.i

CMakeFiles/tw_client2.dir/src/Shared/Message.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/tw_client2.dir/src/Shared/Message.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/g/FH/WS24/VERTS/tw-mailer/src/Shared/Message.cpp -o CMakeFiles/tw_client2.dir/src/Shared/Message.cpp.s

CMakeFiles/tw_client2.dir/src/Shared/NetUtilities.cpp.o: CMakeFiles/tw_client2.dir/flags.make
CMakeFiles/tw_client2.dir/src/Shared/NetUtilities.cpp.o: src/Shared/NetUtilities.cpp
CMakeFiles/tw_client2.dir/src/Shared/NetUtilities.cpp.o: CMakeFiles/tw_client2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/g/FH/WS24/VERTS/tw-mailer/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/tw_client2.dir/src/Shared/NetUtilities.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tw_client2.dir/src/Shared/NetUtilities.cpp.o -MF CMakeFiles/tw_client2.dir/src/Shared/NetUtilities.cpp.o.d -o CMakeFiles/tw_client2.dir/src/Shared/NetUtilities.cpp.o -c /mnt/g/FH/WS24/VERTS/tw-mailer/src/Shared/NetUtilities.cpp

CMakeFiles/tw_client2.dir/src/Shared/NetUtilities.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/tw_client2.dir/src/Shared/NetUtilities.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/g/FH/WS24/VERTS/tw-mailer/src/Shared/NetUtilities.cpp > CMakeFiles/tw_client2.dir/src/Shared/NetUtilities.cpp.i

CMakeFiles/tw_client2.dir/src/Shared/NetUtilities.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/tw_client2.dir/src/Shared/NetUtilities.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/g/FH/WS24/VERTS/tw-mailer/src/Shared/NetUtilities.cpp -o CMakeFiles/tw_client2.dir/src/Shared/NetUtilities.cpp.s

CMakeFiles/tw_client2.dir/src/Client/ClientHandlers.cpp.o: CMakeFiles/tw_client2.dir/flags.make
CMakeFiles/tw_client2.dir/src/Client/ClientHandlers.cpp.o: src/Client/ClientHandlers.cpp
CMakeFiles/tw_client2.dir/src/Client/ClientHandlers.cpp.o: CMakeFiles/tw_client2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/g/FH/WS24/VERTS/tw-mailer/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/tw_client2.dir/src/Client/ClientHandlers.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tw_client2.dir/src/Client/ClientHandlers.cpp.o -MF CMakeFiles/tw_client2.dir/src/Client/ClientHandlers.cpp.o.d -o CMakeFiles/tw_client2.dir/src/Client/ClientHandlers.cpp.o -c /mnt/g/FH/WS24/VERTS/tw-mailer/src/Client/ClientHandlers.cpp

CMakeFiles/tw_client2.dir/src/Client/ClientHandlers.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/tw_client2.dir/src/Client/ClientHandlers.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/g/FH/WS24/VERTS/tw-mailer/src/Client/ClientHandlers.cpp > CMakeFiles/tw_client2.dir/src/Client/ClientHandlers.cpp.i

CMakeFiles/tw_client2.dir/src/Client/ClientHandlers.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/tw_client2.dir/src/Client/ClientHandlers.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/g/FH/WS24/VERTS/tw-mailer/src/Client/ClientHandlers.cpp -o CMakeFiles/tw_client2.dir/src/Client/ClientHandlers.cpp.s

# Object files for target tw_client2
tw_client2_OBJECTS = \
"CMakeFiles/tw_client2.dir/MailClient.cpp.o" \
"CMakeFiles/tw_client2.dir/src/Client/Client.cpp.o" \
"CMakeFiles/tw_client2.dir/src/Shared/Message.cpp.o" \
"CMakeFiles/tw_client2.dir/src/Shared/NetUtilities.cpp.o" \
"CMakeFiles/tw_client2.dir/src/Client/ClientHandlers.cpp.o"

# External object files for target tw_client2
tw_client2_EXTERNAL_OBJECTS =

tw_client2: CMakeFiles/tw_client2.dir/MailClient.cpp.o
tw_client2: CMakeFiles/tw_client2.dir/src/Client/Client.cpp.o
tw_client2: CMakeFiles/tw_client2.dir/src/Shared/Message.cpp.o
tw_client2: CMakeFiles/tw_client2.dir/src/Shared/NetUtilities.cpp.o
tw_client2: CMakeFiles/tw_client2.dir/src/Client/ClientHandlers.cpp.o
tw_client2: CMakeFiles/tw_client2.dir/build.make
tw_client2: CMakeFiles/tw_client2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/mnt/g/FH/WS24/VERTS/tw-mailer/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable tw_client2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tw_client2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tw_client2.dir/build: tw_client2
.PHONY : CMakeFiles/tw_client2.dir/build

CMakeFiles/tw_client2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tw_client2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tw_client2.dir/clean

CMakeFiles/tw_client2.dir/depend:
	cd /mnt/g/FH/WS24/VERTS/tw-mailer && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/g/FH/WS24/VERTS/tw-mailer /mnt/g/FH/WS24/VERTS/tw-mailer /mnt/g/FH/WS24/VERTS/tw-mailer /mnt/g/FH/WS24/VERTS/tw-mailer /mnt/g/FH/WS24/VERTS/tw-mailer/CMakeFiles/tw_client2.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/tw_client2.dir/depend

