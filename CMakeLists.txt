cmake_minimum_required(VERSION 3.0.0)
project(priority_queue VERSION 0.1.0
        DESCRIPTION "header only generic priority queue"
        )

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()
add_subdirectory(test)