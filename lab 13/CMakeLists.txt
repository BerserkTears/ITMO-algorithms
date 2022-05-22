project(algo_lab13)

add_executable(algo_lab13_task1 task1.cpp)
add_executable(algo_lab12_task2 task2.cpp)
#add_executable(algo_lab12_task3 task3.cpp)
#add_executable(algo_lab13_task4 task4.cpp)

add_library(algo_lab13 SHARED task1.cpp)
