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

# Utility rule file for pclviewer.cpp_autogen.

# Include the progress variables for this target.
include CMakeFiles/pclviewer.cpp_autogen.dir/progress.make

CMakeFiles/pclviewer.cpp_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/catolica/Documents/PCLtest/viewer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC, UIC and RCC for target pclviewer.cpp"
	/usr/bin/cmake -E cmake_autogen /home/catolica/Documents/PCLtest/viewer/build/CMakeFiles/pclviewer.cpp_autogen.dir ""

pclviewer.cpp_autogen: CMakeFiles/pclviewer.cpp_autogen
pclviewer.cpp_autogen: CMakeFiles/pclviewer.cpp_autogen.dir/build.make

.PHONY : pclviewer.cpp_autogen

# Rule to build all files generated by this target.
CMakeFiles/pclviewer.cpp_autogen.dir/build: pclviewer.cpp_autogen

.PHONY : CMakeFiles/pclviewer.cpp_autogen.dir/build

CMakeFiles/pclviewer.cpp_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/pclviewer.cpp_autogen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/pclviewer.cpp_autogen.dir/clean

CMakeFiles/pclviewer.cpp_autogen.dir/depend:
	cd /home/catolica/Documents/PCLtest/viewer/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/catolica/Documents/PCLtest/viewer/src /home/catolica/Documents/PCLtest/viewer/src /home/catolica/Documents/PCLtest/viewer/build /home/catolica/Documents/PCLtest/viewer/build /home/catolica/Documents/PCLtest/viewer/build/CMakeFiles/pclviewer.cpp_autogen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/pclviewer.cpp_autogen.dir/depend

