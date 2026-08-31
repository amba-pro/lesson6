cmake_minimum_required(VERSION 3.10)
project(matrixlib)

set(CMAKE_CXX_STANDARD 17)

# Динамическая библиотека matrix
add_library(matrix SHARED matrix.cpp)

# При сборке DLL включаем экспорт символов
target_compile_definitions(matrix PRIVATE MATRIX_EXPORTS)

# Заголовок matrix.h лежит рядом с исходником
target_include_directories(matrix PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
