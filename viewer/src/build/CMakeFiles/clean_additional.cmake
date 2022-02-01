# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/pcl_visualizer_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/pcl_visualizer_autogen.dir/ParseCache.txt"
  "pcl_visualizer_autogen"
  )
endif()
