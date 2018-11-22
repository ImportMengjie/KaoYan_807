cmake_minimum_required(VERSION 3.12)
project(demo)

set(CMAKE_CXX_STANDARD 11)

add_executable(List main.cpp List.h LinkedList.h CircularQueue.h)