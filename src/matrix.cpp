#include <src/matrix.h>

#include <cmath>
#include <iostream>

namespace math
{

// Неконстантный оператор доступа к элементу — возвращает ссылку для изменения
real& Matrix::operator()(int row, int col)
{
    if (row >= this->rows_ || col >= this->cols_)
    {
        std::cerr << "Matrix: row/col number out of bounds" << std::endl;
    }
    int pos = cols_ * row + col;
    return this->mvec_.at(pos);
}

// Константный оператор доступа — только чтение элемента
real Matrix::operator()(int row, int col) const
{
    if (row >= this->rows_ || col >= this->cols_)
    {
        std::cerr << "Matrix: row/col number out of bounds" << std::endl;
        return 0.;
    }
    int pos = cols_ * row + col;
    return this->mvec_.at(pos);
}

// Вывод матрицы в консоль через метод print
void Matrix::print()
{
    for (int i = 0; i < this->rows_; ++i)
    {
        for (int j = 0; j < this->cols_; ++j)
        {
            std::cout << this->mvec_.at(cols_ * i + j) << " ";
        }
        std::cout << std::endl;
    }
}

// Сложение матриц с присваиванием: this += B
Matrix& Matrix::operator+=(const Matrix& B)
{
    if ((this->cols_ != B.cols_) || (this->rows_ != B.rows_))
    {
        std::cerr << "Matrix: Matrices can't be added!" << std::endl;
        return *this;
    }
    for (int pos = 0; pos < this->mvec_.size(); ++pos)
    {
        this->mvec_.at(pos) += B.mvec_.at(pos);
    }
    return *this;
}

// Вычитание матриц с присваиванием: this -= B
Matrix& Matrix::operator-=(const Matrix& B)
{
    if ((this->cols_ != B.cols_) || (this->rows_ != B.rows_))
    {
        std::cerr << "Matrix: Matrices can't be subtracted!" << std::endl;
        return *this;
    }
    for (int pos = 0; pos < this->mvec_.size(); ++pos)
    {
        this->mvec_.at(pos) -= B.mvec_.at(pos);
    }
    return *this;
}

// Умножение матрицы на число с присваиванием: this *= scalar
Matrix& Matrix::operator*=(real scalar)
{
    for (int pos = 0; pos < this->mvec_.size(); ++pos)
    {
        this->mvec_.at(pos) *= scalar;
    }
    return *this;
}

// Сложение двух матриц (дружественная функция)
Matrix operator+(const Matrix& A, const Matrix& B)
{
    if ((A.cols_ != B.cols_) || (A.rows_ != B.rows_))
    {
        std::cerr << "Matrix: Matrices can't be added!" << std::endl;
        return Matrix(0, 0);
    }
    Matrix M(A.rows_, A.cols_);
    for (int pos = 0; pos < A.mvec_.size(); ++pos)
    {
        M.mvec_.at(pos) = A.mvec_.at(pos) + B.mvec_.at(pos);
    }
    return M;
}

// Вычитание двух матриц (дружественная функция)
Matrix operator-(const Matrix& A, const Matrix& B)
{
    if ((A.cols_ != B.cols_) || (A.rows_ != B.rows_))
    {
        std::cerr << "Matrix: Matrices can't be subtracted!" << std::endl;
        return Matrix(0, 0);
    }
    Matrix M(A.rows_, A.cols_);
    for (int pos = 0; pos < A.mvec_.size(); ++pos)
    {
        M.mvec_.at(pos) = A.mvec_.at(pos) - B.mvec_.at(pos);
    }
    return M;
}

// Умножение двух матриц (дружественная функция)
Matrix operator*(const Matrix& A, const Matrix& B)
{
    if (A.cols_ != B.rows_)
    {
        std::cerr << "Matrix: Matrices can't be multiplied!" << std::endl;
        return Matrix(0, 0);
    }

    Matrix M(A.rows_, B.cols_);

    for (int pos = 0; pos < M.mvec_.size(); ++pos)
    {
        int row = (int)std::floor(pos / M.cols_);
        int col = pos - row * M.cols_;

        for (int k = 0; k < A.cols_; ++k)
        {
            M.mvec_.at(pos) += A(row, k) * B(k, col);
        }
    }
    return M;
}

// Оператор вывода матрицы в поток (дружественная функция)
std::ostream& operator<<(std::ostream& os, const Matrix& m)
{
    for (int i = 0; i < m.rows_; ++i)
    {
        for (int j = 0; j < m.cols_; ++j)
        {
            os << m(i, j) << " ";
        }
        os << std::endl;
    }
    return os;
}

// Оператор ввода матрицы из потока (дружественная функция)
std::istream& operator>>(std::istream& is, Matrix& m)
{
    for (int i = 0; i < m.rows_; ++i)
    {
        for (int j = 0; j < m.cols_; ++j)
        {
            is >> m(i, j);
        }
    }
    return is;
}

} // namespace math
