cmake_minimum_required(VERSION 3.29)
project(review_exam)

set(CMAKE_CXX_STANDARD 20)

include_directories(headers)

add_executable(review_exam main.cpp
        headers/linked_list.h
        headers/doubly_linked_list.h
        headers/circular_linked_list.h
        headers/stack.h
)
