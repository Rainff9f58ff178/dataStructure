cmake_minimum_required(VERSION 3.16)
project(alg)

set(CMAKE_CXX_STANDARD 20)
include_directories(include)
add_executable(alg src/main.cpp include/BST.hpp include/dataSruct.h include/alg.h)