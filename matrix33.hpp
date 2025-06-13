#ifndef MATRIX_33_HPP
#define MATRIX_33_HPP

#include <iostream>

class Matrix33 {
private:
    double** matrix;

public:
    Matrix33();                         
    Matrix33(bool initializeMemory);     
    Matrix33(double input[3][3]);


    double& operator()(int row, int col);
    double operator()(int row, int col) const;

    Matrix33(const Matrix33& other);
    Matrix33(Matrix33&& other) noexcept;
    Matrix33& operator=(const Matrix33& other);
    Matrix33& operator=(Matrix33&& other) noexcept;

    Matrix33 operator*(const Matrix33& other) const;
    Matrix33 operator*(double scalar) const;
    Matrix33 operator+(const Matrix33& other) const;

    double determinant() const;
    ~Matrix33();

    friend std::ostream& operator<<(std::ostream& out, const Matrix33& mat);
    friend std::istream& operator>>(std::istream& in, Matrix33& mat);
};

#endif // MATRIX_33_HPP
