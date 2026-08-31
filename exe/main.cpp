#include <iostream>
#include <vector>

// Импорт символов из динамической библиотеки (без исходных заголовков lib/)
#ifdef _WIN32
  #define MATRIX_API __declspec(dllimport)
#else
  #define MATRIX_API
#endif

namespace math
{
    typedef double real;

    // Объявления класса и методов — известны только сигнатуры
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

        real& operator()(int row, int col);
        real operator()(int row, int col) const;

        void print();

        Matrix& operator+=(const Matrix& B);
        Matrix& operator-=(const Matrix& B);
        Matrix& operator*=(real scalar);

        friend MATRIX_API Matrix operator+(const Matrix& A, const Matrix& B);
        friend MATRIX_API Matrix operator-(const Matrix& A, const Matrix& B);
        friend MATRIX_API Matrix operator*(const Matrix& A, const Matrix& B);

        friend MATRIX_API std::ostream& operator<<(std::ostream& os, const Matrix& m);
        friend MATRIX_API std::istream& operator>>(std::istream& is, Matrix& m);
    };
}

int main()
{
    // Создание матриц через конструктор из DLL
    math::Matrix m(3, 3);
    m(0, 0) = 1.;
    m(1, 1) = 2.;
    m(2, 2) = 3.;

    math::Matrix m1(3, 3);
    m1(0, 0) = -5.;
    m1(1, 1) = 5.;

    std::cout << "m =" << std::endl;
    std::cout << m;

    std::cout << "m1 =" << std::endl;
    std::cout << m1;

    std::cout << "m + m1 =" << std::endl;
    math::Matrix m2 = m + m1;
    std::cout << m2;

    std::cout << "m - m1 =" << std::endl;
    math::Matrix m3 = m - m1;
    std::cout << m3;

    std::cout << "m += m1 =" << std::endl;
    m += m1;
    std::cout << m;

    std::cout << "m -= m1 =" << std::endl;
    m -= m1;
    std::cout << m;

    std::cout << "m1 *= 2 =" << std::endl;
    m1 *= 2.;
    std::cout << m1;

    std::cout << "m * m1 =" << std::endl;
    math::Matrix m4 = m * m1;
    std::cout << m4;

    return 0;
}
