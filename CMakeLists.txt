cmake_minimum_required(VERSION 3.29)
project(tubes)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(tubes
    main.cpp
        MLL.h
)
