cmake_minimum_required(VERSION 2.8.12)

PROJECT(Main)
SET(name main)
SET(CMAKE_CXX_STANDARD 11)

find_package( OpenCV REQUIRED )

include_directories( ${OpenCV_INCLUDE_DIRS})

ADD_EXECUTABLE(${name} ${name}.cpp)
TARGET_LINK_LIBRARIES(${name} ${OpenCV_LIBS} )

