 
cmake_minimum_required(VERSION 2.8.12)

PROJECT(QrCode)

set (name main)

#
#SET(OpenCV_DIR /usr/include/o)

### UBUNTU : /usr/local/share/OpenCV/

find_package( OpenCV REQUIRED )

include_directories( ${OpenCV_INCLUDE_DIRS})
ADD_EXECUTABLE(${name} ${name}.cpp)
TARGET_LINK_LIBRARIES(${name} ${OpenCV_LIBS} )

