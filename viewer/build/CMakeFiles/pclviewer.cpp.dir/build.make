# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/catolica/Documents/PCLtest/viewer/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/catolica/Documents/PCLtest/viewer/build

# Include any dependencies generated for this target.
include CMakeFiles/pclviewer.cpp.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/pclviewer.cpp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pclviewer.cpp.dir/flags.make

CMakeFiles/pclviewer.cpp.dir/pclviewer.cpp_autogen/mocs_compilation.cpp.o: CMakeFiles/pclviewer.cpp.dir/flags.make
CMakeFiles/pclviewer.cpp.dir/pclviewer.cpp_autogen/mocs_compilation.cpp.o: pclviewer.cpp_autogen/mocs_compilation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/catolica/Documents/PCLtest/viewer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/pclviewer.cpp.dir/pclviewer.cpp_autogen/mocs_compilation.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pclviewer.cpp.dir/pclviewer.cpp_autogen/mocs_compilation.cpp.o -c /home/catolica/Documents/PCLtest/viewer/build/pclviewer.cpp_autogen/mocs_compilation.cpp

CMakeFiles/pclviewer.cpp.dir/pclviewer.cpp_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pclviewer.cpp.dir/pclviewer.cpp_autogen/mocs_compilation.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/catolica/Documents/PCLtest/viewer/build/pclviewer.cpp_autogen/mocs_compilation.cpp > CMakeFiles/pclviewer.cpp.dir/pclviewer.cpp_autogen/mocs_compilation.cpp.i

CMakeFiles/pclviewer.cpp.dir/pclviewer.cpp_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pclviewer.cpp.dir/pclviewer.cpp_autogen/mocs_compilation.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/catolica/Documents/PCLtest/viewer/build/pclviewer.cpp_autogen/mocs_compilation.cpp -o CMakeFiles/pclviewer.cpp.dir/pclviewer.cpp_autogen/mocs_compilation.cpp.s

CMakeFiles/pclviewer.cpp.dir/pclviewer.cpp_autogen/mocs_compilation.cpp.o.requires:

.PHONY : CMakeFiles/pclviewer.cpp.dir/pclviewer.cpp_autogen/mocs_compilation.cpp.o.requires

CMakeFiles/pclviewer.cpp.dir/pclviewer.cpp_autogen/mocs_compilation.cpp.o.provides: CMakeFiles/pclviewer.cpp.dir/pclviewer.cpp_autogen/mocs_compilation.cpp.o.requires
	$(MAKE) -f CMakeFiles/pclviewer.cpp.dir/build.make CMakeFiles/pclviewer.cpp.dir/pclviewer.cpp_autogen/mocs_compilation.cpp.o.provides.build
.PHONY : CMakeFiles/pclviewer.cpp.dir/pclviewer.cpp_autogen/mocs_compilation.cpp.o.provides

CMakeFiles/pclviewer.cpp.dir/pclviewer.cpp_autogen/mocs_compilation.cpp.o.provides.build: CMakeFiles/pclviewer.cpp.dir/pclviewer.cpp_autogen/mocs_compilation.cpp.o


# Object files for target pclviewer.cpp
pclviewer_cpp_OBJECTS = \
"CMakeFiles/pclviewer.cpp.dir/pclviewer.cpp_autogen/mocs_compilation.cpp.o"

# External object files for target pclviewer.cpp
pclviewer_cpp_EXTERNAL_OBJECTS =

libpclviewer.cpp.a: CMakeFiles/pclviewer.cpp.dir/pclviewer.cpp_autogen/mocs_compilation.cpp.o
libpclviewer.cpp.a: CMakeFiles/pclviewer.cpp.dir/build.make
libpclviewer.cpp.a: CMakeFiles/pclviewer.cpp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/catolica/Documents/PCLtest/viewer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libpclviewer.cpp.a"
	$(CMAKE_COMMAND) -P CMakeFiles/pclviewer.cpp.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pclviewer.cpp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pclviewer.cpp.dir/build: libpclviewer.cpp.a

.PHONY : CMakeFiles/pclviewer.cpp.dir/build

CMakeFiles/pclviewer.cpp.dir/requires: CMakeFiles/pclviewer.cpp.dir/pclviewer.cpp_autogen/mocs_compilation.cpp.o.requires

.PHONY : CMakeFiles/pclviewer.cpp.dir/requires

CMakeFiles/pclviewer.cpp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/pclviewer.cpp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/pclviewer.cpp.dir/clean

CMakeFiles/pclviewer.cpp.dir/depend:
	cd /home/catolica/Documents/PCLtest/viewer/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/catolica/Documents/PCLtest/viewer/src /home/catolica/Documents/PCLtest/viewer/src /home/catolica/Documents/PCLtest/viewer/build /home/catolica/Documents/PCLtest/viewer/build /home/catolica/Documents/PCLtest/viewer/build/CMakeFiles/pclviewer.cpp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/pclviewer.cpp.dir/depend

