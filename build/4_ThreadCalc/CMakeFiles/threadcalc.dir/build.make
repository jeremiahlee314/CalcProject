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
CMAKE_SOURCE_DIR = /home/jeremiah/Documents/calcproject

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jeremiah/Documents/calcproject/build

# Include any dependencies generated for this target.
include 4_ThreadCalc/CMakeFiles/threadcalc.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include 4_ThreadCalc/CMakeFiles/threadcalc.dir/compiler_depend.make

# Include the progress variables for this target.
include 4_ThreadCalc/CMakeFiles/threadcalc.dir/progress.make

# Include the compile flags for this target's objects.
include 4_ThreadCalc/CMakeFiles/threadcalc.dir/flags.make

4_ThreadCalc/CMakeFiles/threadcalc.dir/src/threadcalc.c.o: 4_ThreadCalc/CMakeFiles/threadcalc.dir/flags.make
4_ThreadCalc/CMakeFiles/threadcalc.dir/src/threadcalc.c.o: ../4_ThreadCalc/src/threadcalc.c
4_ThreadCalc/CMakeFiles/threadcalc.dir/src/threadcalc.c.o: 4_ThreadCalc/CMakeFiles/threadcalc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jeremiah/Documents/calcproject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object 4_ThreadCalc/CMakeFiles/threadcalc.dir/src/threadcalc.c.o"
	cd /home/jeremiah/Documents/calcproject/build/4_ThreadCalc && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT 4_ThreadCalc/CMakeFiles/threadcalc.dir/src/threadcalc.c.o -MF CMakeFiles/threadcalc.dir/src/threadcalc.c.o.d -o CMakeFiles/threadcalc.dir/src/threadcalc.c.o -c /home/jeremiah/Documents/calcproject/4_ThreadCalc/src/threadcalc.c

4_ThreadCalc/CMakeFiles/threadcalc.dir/src/threadcalc.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/threadcalc.dir/src/threadcalc.c.i"
	cd /home/jeremiah/Documents/calcproject/build/4_ThreadCalc && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/jeremiah/Documents/calcproject/4_ThreadCalc/src/threadcalc.c > CMakeFiles/threadcalc.dir/src/threadcalc.c.i

4_ThreadCalc/CMakeFiles/threadcalc.dir/src/threadcalc.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/threadcalc.dir/src/threadcalc.c.s"
	cd /home/jeremiah/Documents/calcproject/build/4_ThreadCalc && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/jeremiah/Documents/calcproject/4_ThreadCalc/src/threadcalc.c -o CMakeFiles/threadcalc.dir/src/threadcalc.c.s

4_ThreadCalc/CMakeFiles/threadcalc.dir/src/threadpool.c.o: 4_ThreadCalc/CMakeFiles/threadcalc.dir/flags.make
4_ThreadCalc/CMakeFiles/threadcalc.dir/src/threadpool.c.o: ../4_ThreadCalc/src/threadpool.c
4_ThreadCalc/CMakeFiles/threadcalc.dir/src/threadpool.c.o: 4_ThreadCalc/CMakeFiles/threadcalc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jeremiah/Documents/calcproject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object 4_ThreadCalc/CMakeFiles/threadcalc.dir/src/threadpool.c.o"
	cd /home/jeremiah/Documents/calcproject/build/4_ThreadCalc && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT 4_ThreadCalc/CMakeFiles/threadcalc.dir/src/threadpool.c.o -MF CMakeFiles/threadcalc.dir/src/threadpool.c.o.d -o CMakeFiles/threadcalc.dir/src/threadpool.c.o -c /home/jeremiah/Documents/calcproject/4_ThreadCalc/src/threadpool.c

4_ThreadCalc/CMakeFiles/threadcalc.dir/src/threadpool.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/threadcalc.dir/src/threadpool.c.i"
	cd /home/jeremiah/Documents/calcproject/build/4_ThreadCalc && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/jeremiah/Documents/calcproject/4_ThreadCalc/src/threadpool.c > CMakeFiles/threadcalc.dir/src/threadpool.c.i

4_ThreadCalc/CMakeFiles/threadcalc.dir/src/threadpool.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/threadcalc.dir/src/threadpool.c.s"
	cd /home/jeremiah/Documents/calcproject/build/4_ThreadCalc && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/jeremiah/Documents/calcproject/4_ThreadCalc/src/threadpool.c -o CMakeFiles/threadcalc.dir/src/threadpool.c.s

4_ThreadCalc/CMakeFiles/threadcalc.dir/__/0_Common/src/s_calc.c.o: 4_ThreadCalc/CMakeFiles/threadcalc.dir/flags.make
4_ThreadCalc/CMakeFiles/threadcalc.dir/__/0_Common/src/s_calc.c.o: ../0_Common/src/s_calc.c
4_ThreadCalc/CMakeFiles/threadcalc.dir/__/0_Common/src/s_calc.c.o: 4_ThreadCalc/CMakeFiles/threadcalc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jeremiah/Documents/calcproject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object 4_ThreadCalc/CMakeFiles/threadcalc.dir/__/0_Common/src/s_calc.c.o"
	cd /home/jeremiah/Documents/calcproject/build/4_ThreadCalc && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT 4_ThreadCalc/CMakeFiles/threadcalc.dir/__/0_Common/src/s_calc.c.o -MF CMakeFiles/threadcalc.dir/__/0_Common/src/s_calc.c.o.d -o CMakeFiles/threadcalc.dir/__/0_Common/src/s_calc.c.o -c /home/jeremiah/Documents/calcproject/0_Common/src/s_calc.c

4_ThreadCalc/CMakeFiles/threadcalc.dir/__/0_Common/src/s_calc.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/threadcalc.dir/__/0_Common/src/s_calc.c.i"
	cd /home/jeremiah/Documents/calcproject/build/4_ThreadCalc && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/jeremiah/Documents/calcproject/0_Common/src/s_calc.c > CMakeFiles/threadcalc.dir/__/0_Common/src/s_calc.c.i

4_ThreadCalc/CMakeFiles/threadcalc.dir/__/0_Common/src/s_calc.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/threadcalc.dir/__/0_Common/src/s_calc.c.s"
	cd /home/jeremiah/Documents/calcproject/build/4_ThreadCalc && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/jeremiah/Documents/calcproject/0_Common/src/s_calc.c -o CMakeFiles/threadcalc.dir/__/0_Common/src/s_calc.c.s

4_ThreadCalc/CMakeFiles/threadcalc.dir/src/f_calc.c.o: 4_ThreadCalc/CMakeFiles/threadcalc.dir/flags.make
4_ThreadCalc/CMakeFiles/threadcalc.dir/src/f_calc.c.o: ../4_ThreadCalc/src/f_calc.c
4_ThreadCalc/CMakeFiles/threadcalc.dir/src/f_calc.c.o: 4_ThreadCalc/CMakeFiles/threadcalc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jeremiah/Documents/calcproject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object 4_ThreadCalc/CMakeFiles/threadcalc.dir/src/f_calc.c.o"
	cd /home/jeremiah/Documents/calcproject/build/4_ThreadCalc && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT 4_ThreadCalc/CMakeFiles/threadcalc.dir/src/f_calc.c.o -MF CMakeFiles/threadcalc.dir/src/f_calc.c.o.d -o CMakeFiles/threadcalc.dir/src/f_calc.c.o -c /home/jeremiah/Documents/calcproject/4_ThreadCalc/src/f_calc.c

4_ThreadCalc/CMakeFiles/threadcalc.dir/src/f_calc.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/threadcalc.dir/src/f_calc.c.i"
	cd /home/jeremiah/Documents/calcproject/build/4_ThreadCalc && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/jeremiah/Documents/calcproject/4_ThreadCalc/src/f_calc.c > CMakeFiles/threadcalc.dir/src/f_calc.c.i

4_ThreadCalc/CMakeFiles/threadcalc.dir/src/f_calc.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/threadcalc.dir/src/f_calc.c.s"
	cd /home/jeremiah/Documents/calcproject/build/4_ThreadCalc && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/jeremiah/Documents/calcproject/4_ThreadCalc/src/f_calc.c -o CMakeFiles/threadcalc.dir/src/f_calc.c.s

4_ThreadCalc/CMakeFiles/threadcalc.dir/__/3_DataStructures1/src/queue.c.o: 4_ThreadCalc/CMakeFiles/threadcalc.dir/flags.make
4_ThreadCalc/CMakeFiles/threadcalc.dir/__/3_DataStructures1/src/queue.c.o: ../3_DataStructures1/src/queue.c
4_ThreadCalc/CMakeFiles/threadcalc.dir/__/3_DataStructures1/src/queue.c.o: 4_ThreadCalc/CMakeFiles/threadcalc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jeremiah/Documents/calcproject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object 4_ThreadCalc/CMakeFiles/threadcalc.dir/__/3_DataStructures1/src/queue.c.o"
	cd /home/jeremiah/Documents/calcproject/build/4_ThreadCalc && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT 4_ThreadCalc/CMakeFiles/threadcalc.dir/__/3_DataStructures1/src/queue.c.o -MF CMakeFiles/threadcalc.dir/__/3_DataStructures1/src/queue.c.o.d -o CMakeFiles/threadcalc.dir/__/3_DataStructures1/src/queue.c.o -c /home/jeremiah/Documents/calcproject/3_DataStructures1/src/queue.c

4_ThreadCalc/CMakeFiles/threadcalc.dir/__/3_DataStructures1/src/queue.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/threadcalc.dir/__/3_DataStructures1/src/queue.c.i"
	cd /home/jeremiah/Documents/calcproject/build/4_ThreadCalc && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/jeremiah/Documents/calcproject/3_DataStructures1/src/queue.c > CMakeFiles/threadcalc.dir/__/3_DataStructures1/src/queue.c.i

4_ThreadCalc/CMakeFiles/threadcalc.dir/__/3_DataStructures1/src/queue.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/threadcalc.dir/__/3_DataStructures1/src/queue.c.s"
	cd /home/jeremiah/Documents/calcproject/build/4_ThreadCalc && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/jeremiah/Documents/calcproject/3_DataStructures1/src/queue.c -o CMakeFiles/threadcalc.dir/__/3_DataStructures1/src/queue.c.s

# Object files for target threadcalc
threadcalc_OBJECTS = \
"CMakeFiles/threadcalc.dir/src/threadcalc.c.o" \
"CMakeFiles/threadcalc.dir/src/threadpool.c.o" \
"CMakeFiles/threadcalc.dir/__/0_Common/src/s_calc.c.o" \
"CMakeFiles/threadcalc.dir/src/f_calc.c.o" \
"CMakeFiles/threadcalc.dir/__/3_DataStructures1/src/queue.c.o"

# External object files for target threadcalc
threadcalc_EXTERNAL_OBJECTS =

4_ThreadCalc/threadcalc: 4_ThreadCalc/CMakeFiles/threadcalc.dir/src/threadcalc.c.o
4_ThreadCalc/threadcalc: 4_ThreadCalc/CMakeFiles/threadcalc.dir/src/threadpool.c.o
4_ThreadCalc/threadcalc: 4_ThreadCalc/CMakeFiles/threadcalc.dir/__/0_Common/src/s_calc.c.o
4_ThreadCalc/threadcalc: 4_ThreadCalc/CMakeFiles/threadcalc.dir/src/f_calc.c.o
4_ThreadCalc/threadcalc: 4_ThreadCalc/CMakeFiles/threadcalc.dir/__/3_DataStructures1/src/queue.c.o
4_ThreadCalc/threadcalc: 4_ThreadCalc/CMakeFiles/threadcalc.dir/build.make
4_ThreadCalc/threadcalc: 4_ThreadCalc/CMakeFiles/threadcalc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jeremiah/Documents/calcproject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking C executable threadcalc"
	cd /home/jeremiah/Documents/calcproject/build/4_ThreadCalc && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/threadcalc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
4_ThreadCalc/CMakeFiles/threadcalc.dir/build: 4_ThreadCalc/threadcalc
.PHONY : 4_ThreadCalc/CMakeFiles/threadcalc.dir/build

4_ThreadCalc/CMakeFiles/threadcalc.dir/clean:
	cd /home/jeremiah/Documents/calcproject/build/4_ThreadCalc && $(CMAKE_COMMAND) -P CMakeFiles/threadcalc.dir/cmake_clean.cmake
.PHONY : 4_ThreadCalc/CMakeFiles/threadcalc.dir/clean

4_ThreadCalc/CMakeFiles/threadcalc.dir/depend:
	cd /home/jeremiah/Documents/calcproject/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jeremiah/Documents/calcproject /home/jeremiah/Documents/calcproject/4_ThreadCalc /home/jeremiah/Documents/calcproject/build /home/jeremiah/Documents/calcproject/build/4_ThreadCalc /home/jeremiah/Documents/calcproject/build/4_ThreadCalc/CMakeFiles/threadcalc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : 4_ThreadCalc/CMakeFiles/threadcalc.dir/depend
