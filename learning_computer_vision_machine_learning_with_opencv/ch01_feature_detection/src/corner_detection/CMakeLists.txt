#[[
- reference
  - https://docs.opencv.org/3.4.1/db/df5/tutorial_linux_gcc_cmake.html
]]

cmake_minimum_required(VERSION 3.5)

project( corner_detection )

find_package( OpenCV REQUIRED )

include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable( corner_detection corner_detection.cpp )

target_link_libraries( corner_detection ${OpenCV_LIBS} )

