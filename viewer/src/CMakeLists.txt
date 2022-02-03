cmake_minimum_required(VERSION 3.5)

project(pcl_visualizer LANGUAGES CXX CUDA)

# init_qt: Let's do the CMake job for us
set(CMAKE_AUTOMOC ON) # For meta object compiler
set(CMAKE_AUTORCC ON) # Resource files
set(CMAKE_AUTOUIC ON) # UI files

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Find the QtWidgets library
find_package(Qt6 QUIET COMPONENTS Concurrent OpenGL Widgets)
if (NOT Qt6_FOUND)
  find_package(Qt5 COMPONENTS Concurrent OpenGL Widgets REQUIRED)
  set(QTX Qt5)
else()
  set(QTX Qt6)
endif()

find_package(VTK REQUIRED)
find_package(PCL 1.7.1 REQUIRED)

add_library(surface STATIC
  src/surface_reconstruction.cpp
  src/voxel_structure.cu
  src/overlap.h
  )

# Request that surface be built with -std=c++11
# As this is a public compile feature anything that links to surface
# will also build with -std=c++11
target_compile_features(surface PUBLIC cxx_std_11)

# We need to explicitly state that we need all CUDA files in the particle
# library to be built with -dc as the member functions could be called by
# other libraries and executables
set_target_properties( surface
                       PROPERTIES CUDA_SEPARABLE_COMPILATION ON
                      )

include_directories("/usr/local/cuda-11.6/samples/Common") # CUDA 11.6
include_directories("/usr/local/cuda-11.6/include/")

# Fix a compilation bug under ubuntu 16.04 (Xenial)
list(REMOVE_ITEM PCL_LIBRARIES "vtkproj4")

include_directories(${PCL_INCLUDE_DIRS})
add_definitions(${PCL_DEFINITIONS})

set(project_SOURCES src/main.cpp src/pclviewer.cpp src/surface_reconstruction.cpp)

add_executable(${PROJECT_NAME} ${project_SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE ${PCL_LIBRARIES} ${QTX}::Widgets surface)

set_target_properties(${PROJECT_NAME} PROPERTIES CUDA_SEPARABLE_COMPILATION ON)

add_test(NAME surface_reconstruction COMMAND surface_test)

if(APPLE)
  # We need to add the default path to the driver (libcuda.dylib) as an rpath,
  # so that the static cuda runtime can find it at runtime.
  set_property(TARGET ${PROJECT_NAME} PROPERTY BUILD_RPATH ${CMAKE_CUDA_IMPLICIT_LINK_DIRECTORIES})
endif()