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
include CMakeFiles/test_queue_p.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/test_queue_p.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/test_queue_p.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_queue_p.dir/flags.make

CMakeFiles/test_queue_p.dir/tests/queue_p_tests.c.o: CMakeFiles/test_queue_p.dir/flags.make
CMakeFiles/test_queue_p.dir/tests/queue_p_tests.c.o: ../tests/queue_p_tests.c
CMakeFiles/test_queue_p.dir/tests/queue_p_tests.c.o: CMakeFiles/test_queue_p.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jeremiah/Documents/calcproject/3_DataStructures1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/test_queue_p.dir/tests/queue_p_tests.c.o"
	$(CMAKE_COMMAND) -E __run_co_compile --tidy="/usr/bin/clang-tidy;--checks=* -llvm-include-order, -cppcoreguidelines-*, -readability-magic-numbers, -clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling, -hiccp-no-assembler;--extra-arg-before=--driver-mode=gcc" --source=/home/jeremiah/Documents/calcproject/3_DataStructures1/tests/queue_p_tests.c -- /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/test_queue_p.dir/tests/queue_p_tests.c.o -MF CMakeFiles/test_queue_p.dir/tests/queue_p_tests.c.o.d -o CMakeFiles/test_queue_p.dir/tests/queue_p_tests.c.o -c /home/jeremiah/Documents/calcproject/3_DataStructures1/tests/queue_p_tests.c

CMakeFiles/test_queue_p.dir/tests/queue_p_tests.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test_queue_p.dir/tests/queue_p_tests.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/jeremiah/Documents/calcproject/3_DataStructures1/tests/queue_p_tests.c > CMakeFiles/test_queue_p.dir/tests/queue_p_tests.c.i

CMakeFiles/test_queue_p.dir/tests/queue_p_tests.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test_queue_p.dir/tests/queue_p_tests.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/jeremiah/Documents/calcproject/3_DataStructures1/tests/queue_p_tests.c -o CMakeFiles/test_queue_p.dir/tests/queue_p_tests.c.s

# Object files for target test_queue_p
test_queue_p_OBJECTS = \
"CMakeFiles/test_queue_p.dir/tests/queue_p_tests.c.o"

# External object files for target test_queue_p
test_queue_p_EXTERNAL_OBJECTS =

test_queue_p: CMakeFiles/test_queue_p.dir/tests/queue_p_tests.c.o
test_queue_p: CMakeFiles/test_queue_p.dir/build.make
test_queue_p: libqueue_p.so
test_queue_p: CMakeFiles/test_queue_p.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jeremiah/Documents/calcproject/3_DataStructures1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable test_queue_p"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_queue_p.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_queue_p.dir/build: test_queue_p
.PHONY : CMakeFiles/test_queue_p.dir/build

CMakeFiles/test_queue_p.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_queue_p.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_queue_p.dir/clean

CMakeFiles/test_queue_p.dir/depend:
	cd /home/jeremiah/Documents/calcproject/3_DataStructures1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jeremiah/Documents/calcproject/3_DataStructures1 /home/jeremiah/Documents/calcproject/3_DataStructures1 /home/jeremiah/Documents/calcproject/3_DataStructures1/build /home/jeremiah/Documents/calcproject/3_DataStructures1/build /home/jeremiah/Documents/calcproject/3_DataStructures1/build/CMakeFiles/test_queue_p.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test_queue_p.dir/depend

