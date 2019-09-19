 
cmake_minimum_required(VERSION 2.8.12)

PROJECT(Read_Video)

set (name main)

find_package( OpenCV REQUIRED )

ADD_EXECUTABLE(${name} ${name}.cpp)
TARGET_LINK_LIBRARIES(${name} ${OpenCV_LIBS} )

