cmake_minimum_required(VERSION 3.29)
project(linked_list_polynomials)

set(CMAKE_CXX_STANDARD 14)

include_directories(headers)

add_executable(linked_list_polynomials
    headers/linked_list.h
    src/linked_list.cpp
        headers/node.h
        src/node.cpp
        headers/linked_list_polynomial.h)
