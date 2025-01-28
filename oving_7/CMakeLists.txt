cmake_minimum_required(VERSION 3.10)

project(exercise_7)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_compile_options(-Wall -Wextra)

add_executable(exercise7 main.cpp fraction.cpp set.cpp)
