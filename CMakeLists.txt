cmake_minimum_required(VERSION 3.25)
project(SimplePlanner)

set(CMAKE_CXX_STANDARD 17)

add_executable(SimplePlanner src/CostMatrix.cpp include/CostMatrix.h src/utils.cpp include/utils.h src/planners.cpp include/planners.h src/main.cpp)
