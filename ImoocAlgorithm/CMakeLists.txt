cmake_minimum_required(VERSION 3.7)
project(ImoocAlgorithm)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp sortAlgorithm.h sortAlgorithm.cpp SortTestHelper.h)
add_executable(ImoocAlgorithm ${SOURCE_FILES})