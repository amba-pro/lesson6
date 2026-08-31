cmake_minimum_required(VERSION 3.10)
project(MATRIX)

set(CMAKE_CXX_STANDARD 17)

add_executable(matrix
    src/main.cpp
    src/matrix.cpp
)

target_include_directories(matrix PRIVATE ${CMAKE_SOURCE_DIR})
