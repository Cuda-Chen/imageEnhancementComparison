# CMake minimum version requirement
cmake_minimum_required(VERSION 2.8)

# executable name
project(imageEnhancementComparison)

# set executable output path
set(EXECUTABLE_OUTPUT_PATH "..")
set(CMAKE_BUILD_TYPE Debug)

# find OpenCV
find_package(OpenCV REQUIRED)

add_executable(imageEnhancementComparison main.cpp)

target_link_libraries(imageEnhancementComparison ${OpenCV_LIBS})