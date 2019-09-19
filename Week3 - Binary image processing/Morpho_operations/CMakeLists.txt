cmake_minimum_required(VERSION 2.8)

project(Morpho_operations)
add_executable(${PROJECT_NAME} "main.cpp")

find_package( OpenCV REQUIRED )
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${OpenCV_LIBS} )
