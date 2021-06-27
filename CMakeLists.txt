cmake_minimum_required(VERSION 3.19)
project(thread)

set(CMAKE_CXX_STANDARD 11)

add_executable(thread main.cpp)
target_link_libraries(thread
        pthread)

add_executable(thread_pc main_pc.cpp)
target_link_libraries(thread_pc
        pthread)
