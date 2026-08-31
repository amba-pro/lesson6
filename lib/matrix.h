#pragma once

#include <iostream>
#include <vector>

// Макросы экспорта/импорта для динамической библиотеки
#ifdef _WIN32
  #ifdef MATRIX_EXPORTS
    #define MATRIX_API __declspec(dllexport)
  #else
    #define MATRIX_API __declspec(dllimport)
  #endif
#else
  #define MATRIX_API
#endif

namespace math
{
    // Тип для элементов матрицы
    typedef double real;

    class MATRIX_API Matrix
    {
    private:
        int cols_;
        int rows_;
        std::vector<real> mvec_;

    public:
        Matrix();
        Matrix(int rows, int cols);
        ~Matrix();

        // Доступ к элементу матрицы по индексам (строка, столбец)
        real& operator()(int row, int col);
        real operator()(int row, int col) const;

        void print();

        // Операторы сложения, вычитания и умножения с присваиванием
        Matrix& operator+=(const Matrix& B);
        Matrix& operator-=(const Matrix& B);
        Matrix& operator*=(real scalar);

        // Дружественные функции для бинарных операций
        friend MATRIX_API Matrix operator+(const Matrix& A, const Matrix& B);
        friend MATRIX_API Matrix operator-(const Matrix& A, const Matrix& B);
        friend MATRIX_API Matrix operator*(const Matrix& A, const Matrix& B);

        // Дружественные функции для ввода и вывода
        friend MATRIX_API std::ostream& operator<<(std::ostream& os, const Matrix& m);
        friend MATRIX_API std::istream& operator>>(std::istream& is, Matrix& m);
    };
} // namespace math
