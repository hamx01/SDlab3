cmake_minimum_required(VERSION 3.28)
project(SDlab3)

set(CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc -static")

add_executable(SDlab3 main.cpp)
