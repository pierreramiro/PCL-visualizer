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
CMAKE_SOURCE_DIR = /home/catolica/Documents/PCLtest/viewer/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/catolica/Documents/PCLtest/viewer/build

# Include any dependencies generated for this target.
include CMakeFiles/pcl_visualizer.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/pcl_visualizer.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/pcl_visualizer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pcl_visualizer.dir/flags.make

CMakeFiles/pcl_visualizer.dir/pcl_visualizer_autogen/mocs_compilation.cpp.o: CMakeFiles/pcl_visualizer.dir/flags.make
CMakeFiles/pcl_visualizer.dir/pcl_visualizer_autogen/mocs_compilation.cpp.o: pcl_visualizer_autogen/mocs_compilation.cpp
CMakeFiles/pcl_visualizer.dir/pcl_visualizer_autogen/mocs_compilation.cpp.o: CMakeFiles/pcl_visualizer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/catolica/Documents/PCLtest/viewer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/pcl_visualizer.dir/pcl_visualizer_autogen/mocs_compilation.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pcl_visualizer.dir/pcl_visualizer_autogen/mocs_compilation.cpp.o -MF CMakeFiles/pcl_visualizer.dir/pcl_visualizer_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/pcl_visualizer.dir/pcl_visualizer_autogen/mocs_compilation.cpp.o -c /home/catolica/Documents/PCLtest/viewer/build/pcl_visualizer_autogen/mocs_compilation.cpp

CMakeFiles/pcl_visualizer.dir/pcl_visualizer_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pcl_visualizer.dir/pcl_visualizer_autogen/mocs_compilation.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/catolica/Documents/PCLtest/viewer/build/pcl_visualizer_autogen/mocs_compilation.cpp > CMakeFiles/pcl_visualizer.dir/pcl_visualizer_autogen/mocs_compilation.cpp.i

CMakeFiles/pcl_visualizer.dir/pcl_visualizer_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pcl_visualizer.dir/pcl_visualizer_autogen/mocs_compilation.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/catolica/Documents/PCLtest/viewer/build/pcl_visualizer_autogen/mocs_compilation.cpp -o CMakeFiles/pcl_visualizer.dir/pcl_visualizer_autogen/mocs_compilation.cpp.s

CMakeFiles/pcl_visualizer.dir/main.cpp.o: CMakeFiles/pcl_visualizer.dir/flags.make
CMakeFiles/pcl_visualizer.dir/main.cpp.o: /home/catolica/Documents/PCLtest/viewer/src/main.cpp
CMakeFiles/pcl_visualizer.dir/main.cpp.o: CMakeFiles/pcl_visualizer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/catolica/Documents/PCLtest/viewer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/pcl_visualizer.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pcl_visualizer.dir/main.cpp.o -MF CMakeFiles/pcl_visualizer.dir/main.cpp.o.d -o CMakeFiles/pcl_visualizer.dir/main.cpp.o -c /home/catolica/Documents/PCLtest/viewer/src/main.cpp

CMakeFiles/pcl_visualizer.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pcl_visualizer.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/catolica/Documents/PCLtest/viewer/src/main.cpp > CMakeFiles/pcl_visualizer.dir/main.cpp.i

CMakeFiles/pcl_visualizer.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pcl_visualizer.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/catolica/Documents/PCLtest/viewer/src/main.cpp -o CMakeFiles/pcl_visualizer.dir/main.cpp.s

CMakeFiles/pcl_visualizer.dir/pclviewer.cpp.o: CMakeFiles/pcl_visualizer.dir/flags.make
CMakeFiles/pcl_visualizer.dir/pclviewer.cpp.o: /home/catolica/Documents/PCLtest/viewer/src/pclviewer.cpp
CMakeFiles/pcl_visualizer.dir/pclviewer.cpp.o: CMakeFiles/pcl_visualizer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/catolica/Documents/PCLtest/viewer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/pcl_visualizer.dir/pclviewer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pcl_visualizer.dir/pclviewer.cpp.o -MF CMakeFiles/pcl_visualizer.dir/pclviewer.cpp.o.d -o CMakeFiles/pcl_visualizer.dir/pclviewer.cpp.o -c /home/catolica/Documents/PCLtest/viewer/src/pclviewer.cpp

CMakeFiles/pcl_visualizer.dir/pclviewer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pcl_visualizer.dir/pclviewer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/catolica/Documents/PCLtest/viewer/src/pclviewer.cpp > CMakeFiles/pcl_visualizer.dir/pclviewer.cpp.i

CMakeFiles/pcl_visualizer.dir/pclviewer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pcl_visualizer.dir/pclviewer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/catolica/Documents/PCLtest/viewer/src/pclviewer.cpp -o CMakeFiles/pcl_visualizer.dir/pclviewer.cpp.s

# Object files for target pcl_visualizer
pcl_visualizer_OBJECTS = \
"CMakeFiles/pcl_visualizer.dir/pcl_visualizer_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/pcl_visualizer.dir/main.cpp.o" \
"CMakeFiles/pcl_visualizer.dir/pclviewer.cpp.o"

# External object files for target pcl_visualizer
pcl_visualizer_EXTERNAL_OBJECTS =

pcl_visualizer: CMakeFiles/pcl_visualizer.dir/pcl_visualizer_autogen/mocs_compilation.cpp.o
pcl_visualizer: CMakeFiles/pcl_visualizer.dir/main.cpp.o
pcl_visualizer: CMakeFiles/pcl_visualizer.dir/pclviewer.cpp.o
pcl_visualizer: CMakeFiles/pcl_visualizer.dir/build.make
pcl_visualizer: /usr/local/lib/libpcl_surface.so
pcl_visualizer: /usr/local/lib/libpcl_keypoints.so
pcl_visualizer: /usr/local/lib/libpcl_tracking.so
pcl_visualizer: /usr/local/lib/libpcl_recognition.so
pcl_visualizer: /usr/local/lib/libpcl_stereo.so
pcl_visualizer: /usr/local/lib/libpcl_outofcore.so
pcl_visualizer: /usr/local/lib/libpcl_people.so
pcl_visualizer: /usr/lib/x86_64-linux-gnu/libboost_system.so
pcl_visualizer: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
pcl_visualizer: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
pcl_visualizer: /usr/lib/x86_64-linux-gnu/libboost_iostreams.so
pcl_visualizer: /usr/lib/x86_64-linux-gnu/libboost_serialization.so
pcl_visualizer: /usr/lib/x86_64-linux-gnu/libboost_regex.so
pcl_visualizer: /usr/lib/x86_64-linux-gnu/libqhull_r.so
pcl_visualizer: /usr/lib/libOpenNI.so
pcl_visualizer: /usr/lib/libOpenNI2.so
pcl_visualizer: /usr/lib/x86_64-linux-gnu/libvtkChartsCore-6.3.so.6.3.0
pcl_visualizer: /usr/lib/x86_64-linux-gnu/libvtkInfovisCore-6.3.so.6.3.0
pcl_visualizer: /usr/lib/x86_64-linux-gnu/libfreetype.so
pcl_visualizer: /usr/lib/x86_64-linux-gnu/libz.so
pcl_visualizer: /usr/lib/x86_64-linux-gnu/libjpeg.so
pcl_visualizer: /usr/lib/x86_64-linux-gnu/libpng.so
pcl_visualizer: /usr/lib/x86_64-linux-gnu/libtiff.so
pcl_visualizer: /usr/lib/x86_64-linux-gnu/libvtkIOLegacy-6.3.so.6.3.0
pcl_visualizer: /usr/lib/x86_64-linux-gnu/libvtkIOPLY-6.3.so.6.3.0
pcl_visualizer: /usr/lib/x86_64-linux-gnu/libvtkRenderingLOD-6.3.so.6.3.0
pcl_visualizer: /usr/lib/x86_64-linux-gnu/libvtkViewsContext2D-6.3.so.6.3.0
pcl_visualizer: /usr/lib/x86_64-linux-gnu/libvtkRenderingQt-6.3.so.6.3.0
pcl_visualizer: /usr/lib/x86_64-linux-gnu/libvtkFiltersTexture-6.3.so.6.3.0
pcl_visualizer: /usr/lib/x86_64-linux-gnu/libvtkGUISupportQt-6.3.so.6.3.0
pcl_visualizer: /usr/lib/x86_64-linux-gnu/libvtkRenderingLabel-6.3.so.6.3.0
pcl_visualizer: /usr/lib/x86_64-linux-gnu/libflann_cpp_s.a
pcl_visualizer: /usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5.9.5
pcl_visualizer: /usr/local/lib/libpcl_registration.so
pcl_visualizer: /usr/local/lib/libpcl_segmentation.so
pcl_visualizer: /usr/local/lib/libpcl_features.so
pcl_visualizer: /usr/local/lib/libpcl_filters.so
pcl_visualizer: /usr/local/lib/libpcl_sample_consensus.so
pcl_visualizer: /usr/local/lib/libpcl_ml.so
pcl_visualizer: /usr/local/lib/libpcl_visualization.so
pcl_visualizer: /usr/local/lib/libpcl_search.so
pcl_visualizer: /usr/local/lib/libpcl_kdtree.so
pcl_visualizer: /usr/local/lib/libpcl_io.so
pcl_visualizer: /usr/local/lib/libpcl_octree.so
pcl_visualizer: /usr/local/lib/libpcl_common.so
pcl_visualizer: /usr/lib/x86_64-linux-gnu/libvtkIOGeometry-6.3.so.6.3.0
pcl_visualizer: /usr/lib/x86_64-linux-gnu/libvtkRenderingContext2D-6.3.so.6.3.0
pcl_visualizer: /usr/lib/x86_64-linux-gnu/libvtkViewsCore-6.3.so.6.3.0
pcl_visualizer: /usr/lib/x86_64-linux-gnu/libvtkInteractionWidgets-6.3.so.6.3.0
pcl_visualizer: /usr/lib/x86_64-linux-gnu/libvtkFiltersModeling-6.3.so.6.3.0
pcl_visualizer: /usr/lib/x86_64-linux-gnu/libvtkFiltersHybrid-6.3.so.6.3.0
pcl_visualizer: /usr/lib/x86_64-linux-gnu/libvtkImagingGeneral-6.3.so.6.3.0
pcl_visualizer: /usr/lib/x86_64-linux-gnu/libvtkImagingSources-6.3.so.6.3.0
pcl_visualizer: /usr/lib/x86_64-linux-gnu/libvtkRenderingAnnotation-6.3.so.6.3.0
pcl_visualizer: /usr/lib/x86_64-linux-gnu/libvtkImagingColor-6.3.so.6.3.0
pcl_visualizer: /usr/lib/x86_64-linux-gnu/libvtkRenderingVolume-6.3.so.6.3.0
pcl_visualizer: /usr/lib/x86_64-linux-gnu/libvtkInteractionStyle-6.3.so.6.3.0
pcl_visualizer: /usr/lib/x86_64-linux-gnu/libvtkRenderingOpenGL-6.3.so.6.3.0
pcl_visualizer: /usr/lib/x86_64-linux-gnu/libvtkImagingHybrid-6.3.so.6.3.0
pcl_visualizer: /usr/lib/x86_64-linux-gnu/libvtkIOImage-6.3.so.6.3.0
pcl_visualizer: /usr/lib/x86_64-linux-gnu/libvtkDICOMParser-6.3.so.6.3.0
pcl_visualizer: /usr/lib/x86_64-linux-gnu/libvtkIOCore-6.3.so.6.3.0
pcl_visualizer: /usr/lib/x86_64-linux-gnu/libvtkmetaio-6.3.so.6.3.0
pcl_visualizer: /usr/lib/x86_64-linux-gnu/libz.so
pcl_visualizer: /usr/lib/x86_64-linux-gnu/libGLU.so
pcl_visualizer: /usr/lib/x86_64-linux-gnu/libSM.so
pcl_visualizer: /usr/lib/x86_64-linux-gnu/libICE.so
pcl_visualizer: /usr/lib/x86_64-linux-gnu/libX11.so
pcl_visualizer: /usr/lib/x86_64-linux-gnu/libXext.so
pcl_visualizer: /usr/lib/x86_64-linux-gnu/libXt.so
pcl_visualizer: /usr/lib/x86_64-linux-gnu/libvtkRenderingFreeType-6.3.so.6.3.0
pcl_visualizer: /usr/lib/x86_64-linux-gnu/libvtkRenderingCore-6.3.so.6.3.0
pcl_visualizer: /usr/lib/x86_64-linux-gnu/libvtkCommonColor-6.3.so.6.3.0
pcl_visualizer: /usr/lib/x86_64-linux-gnu/libvtkFiltersExtraction-6.3.so.6.3.0
pcl_visualizer: /usr/lib/x86_64-linux-gnu/libvtkFiltersStatistics-6.3.so.6.3.0
pcl_visualizer: /usr/lib/x86_64-linux-gnu/libvtkImagingFourier-6.3.so.6.3.0
pcl_visualizer: /usr/lib/x86_64-linux-gnu/libvtkImagingCore-6.3.so.6.3.0
pcl_visualizer: /usr/lib/x86_64-linux-gnu/libvtkalglib-6.3.so.6.3.0
pcl_visualizer: /usr/lib/x86_64-linux-gnu/libvtkFiltersGeometry-6.3.so.6.3.0
pcl_visualizer: /usr/lib/x86_64-linux-gnu/libvtkFiltersSources-6.3.so.6.3.0
pcl_visualizer: /usr/lib/x86_64-linux-gnu/libvtkFiltersGeneral-6.3.so.6.3.0
pcl_visualizer: /usr/lib/x86_64-linux-gnu/libvtkFiltersCore-6.3.so.6.3.0
pcl_visualizer: /usr/lib/x86_64-linux-gnu/libvtkCommonExecutionModel-6.3.so.6.3.0
pcl_visualizer: /usr/lib/x86_64-linux-gnu/libvtkCommonComputationalGeometry-6.3.so.6.3.0
pcl_visualizer: /usr/lib/x86_64-linux-gnu/libvtkCommonDataModel-6.3.so.6.3.0
pcl_visualizer: /usr/lib/x86_64-linux-gnu/libvtkCommonMisc-6.3.so.6.3.0
pcl_visualizer: /usr/lib/x86_64-linux-gnu/libvtkCommonTransforms-6.3.so.6.3.0
pcl_visualizer: /usr/lib/x86_64-linux-gnu/libvtkCommonMath-6.3.so.6.3.0
pcl_visualizer: /usr/lib/x86_64-linux-gnu/libvtkCommonSystem-6.3.so.6.3.0
pcl_visualizer: /usr/lib/x86_64-linux-gnu/libvtkCommonCore-6.3.so.6.3.0
pcl_visualizer: /usr/lib/x86_64-linux-gnu/libvtksys-6.3.so.6.3.0
pcl_visualizer: /usr/lib/x86_64-linux-gnu/libvtkftgl-6.3.so.6.3.0
pcl_visualizer: /usr/lib/x86_64-linux-gnu/libfreetype.so
pcl_visualizer: /usr/lib/x86_64-linux-gnu/libGL.so
pcl_visualizer: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.9.5
pcl_visualizer: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.9.5
pcl_visualizer: CMakeFiles/pcl_visualizer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/catolica/Documents/PCLtest/viewer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable pcl_visualizer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pcl_visualizer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pcl_visualizer.dir/build: pcl_visualizer
.PHONY : CMakeFiles/pcl_visualizer.dir/build

CMakeFiles/pcl_visualizer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/pcl_visualizer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/pcl_visualizer.dir/clean

CMakeFiles/pcl_visualizer.dir/depend:
	cd /home/catolica/Documents/PCLtest/viewer/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/catolica/Documents/PCLtest/viewer/src /home/catolica/Documents/PCLtest/viewer/src /home/catolica/Documents/PCLtest/viewer/build /home/catolica/Documents/PCLtest/viewer/build /home/catolica/Documents/PCLtest/viewer/build/CMakeFiles/pcl_visualizer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/pcl_visualizer.dir/depend

