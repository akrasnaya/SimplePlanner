cmake_minimum_required(VERSION 3.25)
project(SimplePlanner)

set(CMAKE_CXX_STANDARD 17)

add_executable(SimplePlanner include/CostMatrix.h include/utils.h include/planners.h src/main.cpp)
