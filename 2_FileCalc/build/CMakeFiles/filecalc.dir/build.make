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
CMAKE_SOURCE_DIR = /home/jeremiah/Documents/calcproject/2_FileCalc

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jeremiah/Documents/calcproject/2_FileCalc/build

# Include any dependencies generated for this target.
include CMakeFiles/filecalc.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/filecalc.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/filecalc.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/filecalc.dir/flags.make

CMakeFiles/filecalc.dir/src/filecalc.c.o: CMakeFiles/filecalc.dir/flags.make
CMakeFiles/filecalc.dir/src/filecalc.c.o: ../src/filecalc.c
CMakeFiles/filecalc.dir/src/filecalc.c.o: CMakeFiles/filecalc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jeremiah/Documents/calcproject/2_FileCalc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/filecalc.dir/src/filecalc.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/filecalc.dir/src/filecalc.c.o -MF CMakeFiles/filecalc.dir/src/filecalc.c.o.d -o CMakeFiles/filecalc.dir/src/filecalc.c.o -c /home/jeremiah/Documents/calcproject/2_FileCalc/src/filecalc.c

CMakeFiles/filecalc.dir/src/filecalc.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/filecalc.dir/src/filecalc.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/jeremiah/Documents/calcproject/2_FileCalc/src/filecalc.c > CMakeFiles/filecalc.dir/src/filecalc.c.i

CMakeFiles/filecalc.dir/src/filecalc.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/filecalc.dir/src/filecalc.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/jeremiah/Documents/calcproject/2_FileCalc/src/filecalc.c -o CMakeFiles/filecalc.dir/src/filecalc.c.s

CMakeFiles/filecalc.dir/src/s_calc_file.c.o: CMakeFiles/filecalc.dir/flags.make
CMakeFiles/filecalc.dir/src/s_calc_file.c.o: ../src/s_calc_file.c
CMakeFiles/filecalc.dir/src/s_calc_file.c.o: CMakeFiles/filecalc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jeremiah/Documents/calcproject/2_FileCalc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/filecalc.dir/src/s_calc_file.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/filecalc.dir/src/s_calc_file.c.o -MF CMakeFiles/filecalc.dir/src/s_calc_file.c.o.d -o CMakeFiles/filecalc.dir/src/s_calc_file.c.o -c /home/jeremiah/Documents/calcproject/2_FileCalc/src/s_calc_file.c

CMakeFiles/filecalc.dir/src/s_calc_file.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/filecalc.dir/src/s_calc_file.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/jeremiah/Documents/calcproject/2_FileCalc/src/s_calc_file.c > CMakeFiles/filecalc.dir/src/s_calc_file.c.i

CMakeFiles/filecalc.dir/src/s_calc_file.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/filecalc.dir/src/s_calc_file.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/jeremiah/Documents/calcproject/2_FileCalc/src/s_calc_file.c -o CMakeFiles/filecalc.dir/src/s_calc_file.c.s

# Object files for target filecalc
filecalc_OBJECTS = \
"CMakeFiles/filecalc.dir/src/filecalc.c.o" \
"CMakeFiles/filecalc.dir/src/s_calc_file.c.o"

# External object files for target filecalc
filecalc_EXTERNAL_OBJECTS =

filecalc: CMakeFiles/filecalc.dir/src/filecalc.c.o
filecalc: CMakeFiles/filecalc.dir/src/s_calc_file.c.o
filecalc: CMakeFiles/filecalc.dir/build.make
filecalc: CMakeFiles/filecalc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jeremiah/Documents/calcproject/2_FileCalc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable filecalc"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/filecalc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/filecalc.dir/build: filecalc
.PHONY : CMakeFiles/filecalc.dir/build

CMakeFiles/filecalc.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/filecalc.dir/cmake_clean.cmake
.PHONY : CMakeFiles/filecalc.dir/clean

CMakeFiles/filecalc.dir/depend:
	cd /home/jeremiah/Documents/calcproject/2_FileCalc/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jeremiah/Documents/calcproject/2_FileCalc /home/jeremiah/Documents/calcproject/2_FileCalc /home/jeremiah/Documents/calcproject/2_FileCalc/build /home/jeremiah/Documents/calcproject/2_FileCalc/build /home/jeremiah/Documents/calcproject/2_FileCalc/build/CMakeFiles/filecalc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/filecalc.dir/depend
