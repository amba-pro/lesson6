cmake_minimum_required(VERSION 3.10)
project(matrix_exe)

set(CMAKE_CXX_STANDARD 17)

# Исполняемый файл — независимый от проекта библиотеки
add_executable(matrix_app main.cpp)

# Подключаем библиотеку импорта из libs/matrixlib
# (на Windows: matrix.lib, на Linux: libmatrix.so / .a)
target_link_directories(matrix_app PRIVATE ${CMAKE_SOURCE_DIR}/libs/matrixlib)
target_link_libraries(matrix_app PRIVATE matrix)

# Копируем DLL рядом с исполняемым файлом при сборке (для запуска)
add_custom_command(TARGET matrix_app POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_SOURCE_DIR}/libs/matrixlib/$<IF:$<BOOL:${WIN32}>,matrix.dll,libmatrix.so>"
        "$<TARGET_FILE_DIR:matrix_app>"
)
