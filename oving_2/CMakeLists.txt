cmake_minimum_required(VERSION 3.10)

project(exercise_2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_compile_options(-Wall -Wextra)

add_executable(Exercise2_Task1_PartA Task1A.cpp)
add_executable(Exercise2_Task1_PartB Task1B.cpp)
add_executable(Exercise2_Task4 Task4.cpp)
add_executable(Exercise2_Task5 Task5.cpp)
add_executable(Exercise2_Task6 Task6.cpp)
