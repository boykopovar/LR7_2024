cmake_minimum_required(VERSION 3.10)

project(LR6)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_COMPILER g++)
# set(CMAKE_CXX_FLAGS "-fsanitize=address")


add_executable(LR6 ${SOURCES}
        Lab_7.cpp
        global_utils.cpp
        global_utils.h
        Task_1/Task_1.cpp
        Task_1/task_1.h
        Task_1/utils_1.cpp
        Task_2/Task_2.cpp
        Task_2/task_2.h
        Task_2/utils_2.cpp
        Task_3/Task_3.cpp
        Task_3/task_3.h
        Task_3/utils_3.cpp)
