# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/shuochen/学习/编程/Design-Pattern

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/shuochen/学习/编程/Design-Pattern/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/main9.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/main9.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main9.dir/flags.make

CMakeFiles/main9.dir/Template/Template_Pattern_Test.cpp.o: CMakeFiles/main9.dir/flags.make
CMakeFiles/main9.dir/Template/Template_Pattern_Test.cpp.o: ../Template/Template\ Pattern\ Test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/shuochen/学习/编程/Design-Pattern/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/main9.dir/Template/Template_Pattern_Test.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main9.dir/Template/Template_Pattern_Test.cpp.o -c "/Users/shuochen/学习/编程/Design-Pattern/Template/Template Pattern Test.cpp"

CMakeFiles/main9.dir/Template/Template_Pattern_Test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main9.dir/Template/Template_Pattern_Test.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/shuochen/学习/编程/Design-Pattern/Template/Template Pattern Test.cpp" > CMakeFiles/main9.dir/Template/Template_Pattern_Test.cpp.i

CMakeFiles/main9.dir/Template/Template_Pattern_Test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main9.dir/Template/Template_Pattern_Test.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/shuochen/学习/编程/Design-Pattern/Template/Template Pattern Test.cpp" -o CMakeFiles/main9.dir/Template/Template_Pattern_Test.cpp.s

# Object files for target main9
main9_OBJECTS = \
"CMakeFiles/main9.dir/Template/Template_Pattern_Test.cpp.o"

# External object files for target main9
main9_EXTERNAL_OBJECTS =

main9: CMakeFiles/main9.dir/Template/Template_Pattern_Test.cpp.o
main9: CMakeFiles/main9.dir/build.make
main9: CMakeFiles/main9.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/shuochen/学习/编程/Design-Pattern/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable main9"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main9.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main9.dir/build: main9

.PHONY : CMakeFiles/main9.dir/build

CMakeFiles/main9.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/main9.dir/cmake_clean.cmake
.PHONY : CMakeFiles/main9.dir/clean

CMakeFiles/main9.dir/depend:
	cd /Users/shuochen/学习/编程/Design-Pattern/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/shuochen/学习/编程/Design-Pattern /Users/shuochen/学习/编程/Design-Pattern /Users/shuochen/学习/编程/Design-Pattern/cmake-build-debug /Users/shuochen/学习/编程/Design-Pattern/cmake-build-debug /Users/shuochen/学习/编程/Design-Pattern/cmake-build-debug/CMakeFiles/main9.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/main9.dir/depend

