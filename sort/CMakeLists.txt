cmake_minimum_required(VERSION 3.12)
project(sort)

set(CMAKE_CXX_STANDARD 11)

add_executable(sort main.cpp InsertSort.h QuickSort.h HeapSort.h MergeSort.h)