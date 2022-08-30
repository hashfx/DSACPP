cmake_minimum_required(VERSION 3.17)
project(DSACPP)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(DSACPP
        linear_search.cpp)
