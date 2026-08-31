#pragma once

#include <iostream>
#include <vector>

namespace math
{
    // Тип для элементов матрицы
    typedef double real;

    class Matrix
    {
    private:
        int cols_;
        int rows_;
        std::vector<real> mvec_;

    public:
        Matrix() {};

        Matrix(int rows, int cols)
            : cols_(cols), rows_(rows), mvec_(std::vector<real>(rows * cols)) {};

        // Доступ к элементу матрицы по индексам (строка, столбец)
        real& operator()(int row, int col);
        real operator()(int row, int col) const;

        void print();

        // Операторы сложения, вычитания и умножения с присваиванием
        Matrix& operator+=(const Matrix& B);
        Matrix& operator-=(const Matrix& B);
        Matrix& operator*=(real scalar);

        // Дружественные функции для бинарных операций
        friend Matrix operator+(const Matrix& A, const Matrix& B);
        friend Matrix operator-(const Matrix& A, const Matrix& B);
        friend Matrix operator*(const Matrix& A, const Matrix& B);

        // Дружественные функции для ввода и вывода в консоль
        friend std::ostream& operator<<(std::ostream& os, const Matrix& m);
        friend std::istream& operator>>(std::istream& is, Matrix& m);
    };
} // namespace math
