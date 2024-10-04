cmake_minimum_required(VERSION 3.10)

project(exercise_3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_compile_options(-Wall -Wextra)

add_executable(Exercise3_Task1_2 Circle.cpp Circle.h)
add_executable(Exercise3_Task3 Commodity.cpp Commodity.h)
add_executable(Exercise3_Task4 Main.cpp)
