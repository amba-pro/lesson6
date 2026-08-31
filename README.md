# lesson6 — динамическая библиотека Matrix

## Структура

```
lib/                    — CMake-проект динамической библиотеки
  matrix.h / matrix.cpp
  CMakeLists.txt

exe/                    — независимый CMake-проект исполняемого файла
  main.cpp              — импорт через __declspec(dllimport)
  CMakeLists.txt
  libs/matrixlib/       — matrix.dll + matrix.lib
```

## Сборка библиотеки

```bat
cd lib
mkdir build
cd build
cmake ..
cmake --build . --config Debug
```

Скопируйте `Debug\matrix.dll` и `Debug\matrix.lib` в `exe\libs\matrixlib\`.

## Сборка и запуск exe

```bat
cd exe
mkdir build
cd build
cmake ..
cmake --build . --config Debug
Debug\matrix_app.exe
```
