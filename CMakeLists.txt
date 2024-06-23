cmake_minimum_required(VERSION 3.25)
project(SimplePlanner)

set(CMAKE_CXX_STANDARD 17)

add_executable(SimplePlanner main1.cpp CostMatrix.cpp CostMatrix.h utils.cpp utils.h planners.cpp planners.h main.cpp PFPF.h tests.cpp)
