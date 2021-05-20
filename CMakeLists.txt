# cmake_minimum_required(VERSION <specify CMake version here>)
project(cpplox)

set(CMAKE_CXX_STANDARD 17)

add_executable(cpplox main.cpp chunk.h debug.h)