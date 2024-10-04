cmake_minimum_required(VERSION 3.10)

project(exercise_4)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM gtkmm-3.0 REQUIRED)

include_directories(${GTKMM_INCLUDE_DIRS})
link_directories(${GTKMM_LIBRARY_DIRS})

add_executable(Exercise4_Task1 Task1.cpp)

add_executable(Exercise4_Task2 Task2.cpp)

target_link_libraries(Exercise4_Task2 ${GTKMM_LIBRARIES})
