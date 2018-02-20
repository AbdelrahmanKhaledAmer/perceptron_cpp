cmake_minimum_required(VERSION 3.5)

file(GLOB SRCS 
    "src/*.c"
    "src/*.cpp"
    "src/*.h"
    "src/*.hpp"
)

if(UNIX)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
endif()

add_executable(prog ${SRCS})
