cmake_minimum_required(VERSION 3.10)

project(exercise_6)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_compile_options(-Wall -Wextra)

add_executable(Exercise6TaskA Chess.cpp)
add_executable(Exercise6TaskB HTTPServer.cpp)
