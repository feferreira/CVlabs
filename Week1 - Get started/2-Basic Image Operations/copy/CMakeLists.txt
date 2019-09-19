 
cmake_minimum_required(VERSION 2.8.12)

PROJECT(copy)

set (name main)

#SET(OpenCV_DIR Enter-the-path-of-OpenCV-installation-on-your-system)

### UBUNTU : /usr/local/share/OpenCV/

find_package( OpenCV REQUIRED )

include_directories( ${OpenCV_INCLUDE_DIRS})
ADD_EXECUTABLE(${name} ${name}.cpp)
TARGET_LINK_LIBRARIES(${name} ${OpenCV_LIBS} )

