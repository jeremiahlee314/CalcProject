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
CMAKE_SOURCE_DIR = /home/jeremiah/Documents/calcproject/3_DataStructures1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jeremiah/Documents/calcproject/3_DataStructures1/build

# Include any dependencies generated for this target.
include CMakeFiles/stack.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/stack.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/stack.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/stack.dir/flags.make

CMakeFiles/stack.dir/src/stack.c.o: CMakeFiles/stack.dir/flags.make
CMakeFiles/stack.dir/src/stack.c.o: ../src/stack.c
CMakeFiles/stack.dir/src/stack.c.o: CMakeFiles/stack.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jeremiah/Documents/calcproject/3_DataStructures1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/stack.dir/src/stack.c.o"
	$(CMAKE_COMMAND) -E __run_co_compile --tidy="/usr/bin/clang-tidy;--checks=* -llvm-include-order, -cppcoreguidelines-*, -readability-magic-numbers, -clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling, -hiccp-no-assembler;--extra-arg-before=--driver-mode=gcc" --source=/home/jeremiah/Documents/calcproject/3_DataStructures1/src/stack.c -- /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/stack.dir/src/stack.c.o -MF CMakeFiles/stack.dir/src/stack.c.o.d -o CMakeFiles/stack.dir/src/stack.c.o -c /home/jeremiah/Documents/calcproject/3_DataStructures1/src/stack.c

CMakeFiles/stack.dir/src/stack.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/stack.dir/src/stack.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/jeremiah/Documents/calcproject/3_DataStructures1/src/stack.c > CMakeFiles/stack.dir/src/stack.c.i

CMakeFiles/stack.dir/src/stack.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/stack.dir/src/stack.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/jeremiah/Documents/calcproject/3_DataStructures1/src/stack.c -o CMakeFiles/stack.dir/src/stack.c.s

# Object files for target stack
stack_OBJECTS = \
"CMakeFiles/stack.dir/src/stack.c.o"

# External object files for target stack
stack_EXTERNAL_OBJECTS =

libstack.so: CMakeFiles/stack.dir/src/stack.c.o
libstack.so: CMakeFiles/stack.dir/build.make
libstack.so: CMakeFiles/stack.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jeremiah/Documents/calcproject/3_DataStructures1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C shared library libstack.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/stack.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/stack.dir/build: libstack.so
.PHONY : CMakeFiles/stack.dir/build

CMakeFiles/stack.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/stack.dir/cmake_clean.cmake
.PHONY : CMakeFiles/stack.dir/clean

CMakeFiles/stack.dir/depend:
	cd /home/jeremiah/Documents/calcproject/3_DataStructures1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jeremiah/Documents/calcproject/3_DataStructures1 /home/jeremiah/Documents/calcproject/3_DataStructures1 /home/jeremiah/Documents/calcproject/3_DataStructures1/build /home/jeremiah/Documents/calcproject/3_DataStructures1/build /home/jeremiah/Documents/calcproject/3_DataStructures1/build/CMakeFiles/stack.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/stack.dir/depend

