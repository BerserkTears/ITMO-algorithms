cmake_minimum_required(VERSION 3.20)
project(algo)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory("lab 8")
add_subdirectory("lab 9")
add_subdirectory("lab 10")
add_subdirectory("lab 12")
add_subdirectory("lab 13")

add_subdirectory(testing)
target_include_directories(testing PUBLIC "lab 13")
