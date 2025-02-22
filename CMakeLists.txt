cmake_minimum_required(VERSION 3.25)
project(SimplePlanner)

include_directories(include)    

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Укажите путь к заголовочным файлам Eigen
# Предполагается, что вы распаковали Eigen в папку "eigen" в корне вашего проекта
find_package(Eigen3 REQUIRED)
find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(Boost REQUIRED COMPONENTS unit_test_framework)

# Добавьте путь к заголовочным файлам
include_directories(${EIGEN3_INCLUDE_DIR})

# Добавьте все необходимые исходные файлы
add_executable(SimplePlanner 
    src/main.cpp 
    src/CostMatrix.cpp 
    src/utils.cpp 
    src/planners.cpp
)

add_executable(SimplePlannerTests 
    tests/tests.cpp
    src/CostMatrix.cpp 
    src/utils.cpp 
    src/planners.cpp
)


target_link_libraries(SimplePlanner Qt5::Widgets)
target_link_libraries(SimplePlannerTests Boost::unit_test_framework)