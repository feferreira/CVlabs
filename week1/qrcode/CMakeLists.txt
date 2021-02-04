cmake_minimum_required(VERSION 2.8.12)

project(example)

set( CMAKE_EXPORT_COMPILE_COMMANDS ON )

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS})

add_executable(example main.cpp qrdetector.cpp)
target_link_libraries(example ${OpenCV_LIBS})
