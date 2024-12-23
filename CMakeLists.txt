cmake_minimum_required(VERSION 3.10)

project(LR7)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_FLAGS "-fsanitize=address")


add_executable(LR6 ${SOURCES}
        Lab_7.cpp
        global_utils.cpp

        Task_1/Task_1.cpp
        Task_1/utils_1.cpp

        Task_2/Task_2.cpp
        Task_2/utils_2.cpp

        Task_3/Task_3.cpp
        Task_3/utils_3.cpp

        Task_4/Task_4.cpp
        Task_4/utils_4.cpp

        Task_5/src/Task_5.cpp
        Task_5/src/utils_5.cpp
        Task_5/src/structure_utils.cpp
)
