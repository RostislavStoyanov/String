cmake_minimum_required(VERSION 3.7)
project(string)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp String.cpp String.h)
add_executable(string ${SOURCE_FILES})