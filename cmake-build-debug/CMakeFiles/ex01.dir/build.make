# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/bar/CLionProjects/ex1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/bar/CLionProjects/ex1/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ex01.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/ex01.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ex01.dir/flags.make

CMakeFiles/ex01.dir/src/main.cpp.o: CMakeFiles/ex01.dir/flags.make
CMakeFiles/ex01.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bar/CLionProjects/ex1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ex01.dir/src/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ex01.dir/src/main.cpp.o -c /Users/bar/CLionProjects/ex1/src/main.cpp

CMakeFiles/ex01.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ex01.dir/src/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bar/CLionProjects/ex1/src/main.cpp > CMakeFiles/ex01.dir/src/main.cpp.i

CMakeFiles/ex01.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ex01.dir/src/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bar/CLionProjects/ex1/src/main.cpp -o CMakeFiles/ex01.dir/src/main.cpp.s

CMakeFiles/ex01.dir/src/Vertex.cpp.o: CMakeFiles/ex01.dir/flags.make
CMakeFiles/ex01.dir/src/Vertex.cpp.o: ../src/Vertex.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bar/CLionProjects/ex1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ex01.dir/src/Vertex.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ex01.dir/src/Vertex.cpp.o -c /Users/bar/CLionProjects/ex1/src/Vertex.cpp

CMakeFiles/ex01.dir/src/Vertex.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ex01.dir/src/Vertex.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bar/CLionProjects/ex1/src/Vertex.cpp > CMakeFiles/ex01.dir/src/Vertex.cpp.i

CMakeFiles/ex01.dir/src/Vertex.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ex01.dir/src/Vertex.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bar/CLionProjects/ex1/src/Vertex.cpp -o CMakeFiles/ex01.dir/src/Vertex.cpp.s

CMakeFiles/ex01.dir/src/Utilities.cpp.o: CMakeFiles/ex01.dir/flags.make
CMakeFiles/ex01.dir/src/Utilities.cpp.o: ../src/Utilities.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bar/CLionProjects/ex1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/ex01.dir/src/Utilities.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ex01.dir/src/Utilities.cpp.o -c /Users/bar/CLionProjects/ex1/src/Utilities.cpp

CMakeFiles/ex01.dir/src/Utilities.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ex01.dir/src/Utilities.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bar/CLionProjects/ex1/src/Utilities.cpp > CMakeFiles/ex01.dir/src/Utilities.cpp.i

CMakeFiles/ex01.dir/src/Utilities.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ex01.dir/src/Utilities.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bar/CLionProjects/ex1/src/Utilities.cpp -o CMakeFiles/ex01.dir/src/Utilities.cpp.s

CMakeFiles/ex01.dir/src/Board.cpp.o: CMakeFiles/ex01.dir/flags.make
CMakeFiles/ex01.dir/src/Board.cpp.o: ../src/Board.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bar/CLionProjects/ex1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/ex01.dir/src/Board.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ex01.dir/src/Board.cpp.o -c /Users/bar/CLionProjects/ex1/src/Board.cpp

CMakeFiles/ex01.dir/src/Board.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ex01.dir/src/Board.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bar/CLionProjects/ex1/src/Board.cpp > CMakeFiles/ex01.dir/src/Board.cpp.i

CMakeFiles/ex01.dir/src/Board.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ex01.dir/src/Board.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bar/CLionProjects/ex1/src/Board.cpp -o CMakeFiles/ex01.dir/src/Board.cpp.s

CMakeFiles/ex01.dir/src/Rectangle.cpp.o: CMakeFiles/ex01.dir/flags.make
CMakeFiles/ex01.dir/src/Rectangle.cpp.o: ../src/Rectangle.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bar/CLionProjects/ex1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/ex01.dir/src/Rectangle.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ex01.dir/src/Rectangle.cpp.o -c /Users/bar/CLionProjects/ex1/src/Rectangle.cpp

CMakeFiles/ex01.dir/src/Rectangle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ex01.dir/src/Rectangle.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bar/CLionProjects/ex1/src/Rectangle.cpp > CMakeFiles/ex01.dir/src/Rectangle.cpp.i

CMakeFiles/ex01.dir/src/Rectangle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ex01.dir/src/Rectangle.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bar/CLionProjects/ex1/src/Rectangle.cpp -o CMakeFiles/ex01.dir/src/Rectangle.cpp.s

CMakeFiles/ex01.dir/src/Square.cpp.o: CMakeFiles/ex01.dir/flags.make
CMakeFiles/ex01.dir/src/Square.cpp.o: ../src/Square.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bar/CLionProjects/ex1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/ex01.dir/src/Square.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ex01.dir/src/Square.cpp.o -c /Users/bar/CLionProjects/ex1/src/Square.cpp

CMakeFiles/ex01.dir/src/Square.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ex01.dir/src/Square.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bar/CLionProjects/ex1/src/Square.cpp > CMakeFiles/ex01.dir/src/Square.cpp.i

CMakeFiles/ex01.dir/src/Square.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ex01.dir/src/Square.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bar/CLionProjects/ex1/src/Square.cpp -o CMakeFiles/ex01.dir/src/Square.cpp.s

# Object files for target ex01
ex01_OBJECTS = \
"CMakeFiles/ex01.dir/src/main.cpp.o" \
"CMakeFiles/ex01.dir/src/Vertex.cpp.o" \
"CMakeFiles/ex01.dir/src/Utilities.cpp.o" \
"CMakeFiles/ex01.dir/src/Board.cpp.o" \
"CMakeFiles/ex01.dir/src/Rectangle.cpp.o" \
"CMakeFiles/ex01.dir/src/Square.cpp.o"

# External object files for target ex01
ex01_EXTERNAL_OBJECTS =

ex01: CMakeFiles/ex01.dir/src/main.cpp.o
ex01: CMakeFiles/ex01.dir/src/Vertex.cpp.o
ex01: CMakeFiles/ex01.dir/src/Utilities.cpp.o
ex01: CMakeFiles/ex01.dir/src/Board.cpp.o
ex01: CMakeFiles/ex01.dir/src/Rectangle.cpp.o
ex01: CMakeFiles/ex01.dir/src/Square.cpp.o
ex01: CMakeFiles/ex01.dir/build.make
ex01: CMakeFiles/ex01.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/bar/CLionProjects/ex1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable ex01"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ex01.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ex01.dir/build: ex01
.PHONY : CMakeFiles/ex01.dir/build

CMakeFiles/ex01.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ex01.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ex01.dir/clean

CMakeFiles/ex01.dir/depend:
	cd /Users/bar/CLionProjects/ex1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/bar/CLionProjects/ex1 /Users/bar/CLionProjects/ex1 /Users/bar/CLionProjects/ex1/cmake-build-debug /Users/bar/CLionProjects/ex1/cmake-build-debug /Users/bar/CLionProjects/ex1/cmake-build-debug/CMakeFiles/ex01.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ex01.dir/depend

