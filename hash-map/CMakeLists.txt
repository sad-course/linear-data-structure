cmake_minimum_required(VERSION 3.29)
project(hash_map)

set(CMAKE_CXX_STANDARD 14)

add_executable(hash_map
    main.cpp
        headers/hash_table.h
        hash_table.cpp
        challenge.cpp)
