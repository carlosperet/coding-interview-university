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
CMAKE_SOURCE_DIR = /home/carlosperet_/projects/learning/coding-interview-university/practice-c/BSTree

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/carlosperet_/projects/learning/coding-interview-university/practice-c/BSTree/build

# Include any dependencies generated for this target.
include CMakeFiles/bstree.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/bstree.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/bstree.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/bstree.dir/flags.make

CMakeFiles/bstree.dir/main.c.o: CMakeFiles/bstree.dir/flags.make
CMakeFiles/bstree.dir/main.c.o: ../main.c
CMakeFiles/bstree.dir/main.c.o: CMakeFiles/bstree.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/carlosperet_/projects/learning/coding-interview-university/practice-c/BSTree/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/bstree.dir/main.c.o"
	clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/bstree.dir/main.c.o -MF CMakeFiles/bstree.dir/main.c.o.d -o CMakeFiles/bstree.dir/main.c.o -c /home/carlosperet_/projects/learning/coding-interview-university/practice-c/BSTree/main.c

CMakeFiles/bstree.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/bstree.dir/main.c.i"
	clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/carlosperet_/projects/learning/coding-interview-university/practice-c/BSTree/main.c > CMakeFiles/bstree.dir/main.c.i

CMakeFiles/bstree.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/bstree.dir/main.c.s"
	clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/carlosperet_/projects/learning/coding-interview-university/practice-c/BSTree/main.c -o CMakeFiles/bstree.dir/main.c.s

CMakeFiles/bstree.dir/bstree.c.o: CMakeFiles/bstree.dir/flags.make
CMakeFiles/bstree.dir/bstree.c.o: ../bstree.c
CMakeFiles/bstree.dir/bstree.c.o: CMakeFiles/bstree.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/carlosperet_/projects/learning/coding-interview-university/practice-c/BSTree/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/bstree.dir/bstree.c.o"
	clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/bstree.dir/bstree.c.o -MF CMakeFiles/bstree.dir/bstree.c.o.d -o CMakeFiles/bstree.dir/bstree.c.o -c /home/carlosperet_/projects/learning/coding-interview-university/practice-c/BSTree/bstree.c

CMakeFiles/bstree.dir/bstree.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/bstree.dir/bstree.c.i"
	clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/carlosperet_/projects/learning/coding-interview-university/practice-c/BSTree/bstree.c > CMakeFiles/bstree.dir/bstree.c.i

CMakeFiles/bstree.dir/bstree.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/bstree.dir/bstree.c.s"
	clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/carlosperet_/projects/learning/coding-interview-university/practice-c/BSTree/bstree.c -o CMakeFiles/bstree.dir/bstree.c.s

CMakeFiles/bstree.dir/bst_test.c.o: CMakeFiles/bstree.dir/flags.make
CMakeFiles/bstree.dir/bst_test.c.o: ../bst_test.c
CMakeFiles/bstree.dir/bst_test.c.o: CMakeFiles/bstree.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/carlosperet_/projects/learning/coding-interview-university/practice-c/BSTree/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/bstree.dir/bst_test.c.o"
	clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/bstree.dir/bst_test.c.o -MF CMakeFiles/bstree.dir/bst_test.c.o.d -o CMakeFiles/bstree.dir/bst_test.c.o -c /home/carlosperet_/projects/learning/coding-interview-university/practice-c/BSTree/bst_test.c

CMakeFiles/bstree.dir/bst_test.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/bstree.dir/bst_test.c.i"
	clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/carlosperet_/projects/learning/coding-interview-university/practice-c/BSTree/bst_test.c > CMakeFiles/bstree.dir/bst_test.c.i

CMakeFiles/bstree.dir/bst_test.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/bstree.dir/bst_test.c.s"
	clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/carlosperet_/projects/learning/coding-interview-university/practice-c/BSTree/bst_test.c -o CMakeFiles/bstree.dir/bst_test.c.s

# Object files for target bstree
bstree_OBJECTS = \
"CMakeFiles/bstree.dir/main.c.o" \
"CMakeFiles/bstree.dir/bstree.c.o" \
"CMakeFiles/bstree.dir/bst_test.c.o"

# External object files for target bstree
bstree_EXTERNAL_OBJECTS =

bstree: CMakeFiles/bstree.dir/main.c.o
bstree: CMakeFiles/bstree.dir/bstree.c.o
bstree: CMakeFiles/bstree.dir/bst_test.c.o
bstree: CMakeFiles/bstree.dir/build.make
bstree: CMakeFiles/bstree.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/carlosperet_/projects/learning/coding-interview-university/practice-c/BSTree/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable bstree"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/bstree.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/bstree.dir/build: bstree
.PHONY : CMakeFiles/bstree.dir/build

CMakeFiles/bstree.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/bstree.dir/cmake_clean.cmake
.PHONY : CMakeFiles/bstree.dir/clean

CMakeFiles/bstree.dir/depend:
	cd /home/carlosperet_/projects/learning/coding-interview-university/practice-c/BSTree/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/carlosperet_/projects/learning/coding-interview-university/practice-c/BSTree /home/carlosperet_/projects/learning/coding-interview-university/practice-c/BSTree /home/carlosperet_/projects/learning/coding-interview-university/practice-c/BSTree/build /home/carlosperet_/projects/learning/coding-interview-university/practice-c/BSTree/build /home/carlosperet_/projects/learning/coding-interview-university/practice-c/BSTree/build/CMakeFiles/bstree.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/bstree.dir/depend

