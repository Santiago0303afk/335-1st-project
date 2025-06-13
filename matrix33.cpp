#include "matrix33.hpp"
#include <iostream>
#include <stdexcept>
using namespace std;

Matrix33::Matrix33() {}

Matrix33::Matrix33(bool initializeMemory) {
    matrix = new double*[3];
    for (int i = 0; i < 3; ++i) {
        matrix[i] = new double[3];
        for (int j = 0; j < 3; ++j) {
            matrix[i][j] = 0.0;
        }
    }
}

Matrix33::Matrix33(double input[3][3]) {
    matrix = new double*[3];
    for (int i = 0; i < 3; ++i) {
        matrix[i] = new double[3];
        for (int j = 0; j < 3; ++j) {
            matrix[i][j] = input[i][j];
        }
    }
}

double Matrix33::operator()(int row, int col) const {
    return matrix[row][col];
}

double& Matrix33::operator()(int row, int col) {
    return matrix[row][col];
}

Matrix33::Matrix33(const Matrix33& other) {
    matrix = new double*[3];
    for (int i = 0; i < 3; ++i) {
        matrix[i] = new double[3];
        for (int j = 0; j < 3; ++j) {
            matrix[i][j] = other.matrix[i][j];
        }
    }
}

Matrix33::Matrix33(Matrix33&& other) noexcept {
    matrix = other.matrix;
    other.matrix = nullptr;
}

Matrix33& Matrix33::operator=(const Matrix33& other) {
    if (this != &other) {
        if (matrix) {
            for (int i = 0; i < 3; ++i) delete[] matrix[i];
            delete[] matrix;
        }
        matrix = new double*[3];
        for (int i = 0; i < 3; ++i) {
            matrix[i] = new double[3];
            for (int j = 0; j < 3; ++j) {
                matrix[i][j] = other.matrix[i][j];
            }
        }
    }
    return *this;
}

Matrix33& Matrix33::operator=(Matrix33&& other) noexcept {
    if (this != &other) {
        if (matrix) {
            for (int i = 0; i < 3; ++i) delete[] matrix[i];
            delete[] matrix;
        }
        matrix = other.matrix;
        other.matrix = nullptr;
    }
    return *this;
}

Matrix33::~Matrix33() {
    if (matrix) {
        for (int i = 0; i < 3; ++i) delete[] matrix[i];
        delete[] matrix;
    }
}

Matrix33 Matrix33::operator*(const Matrix33& other) const {
    Matrix33 result(true);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            result.matrix[i][j] = 0;
            for (int k = 0; k < 3; ++k) {
                result.matrix[i][j] += matrix[i][k] * other.matrix[k][j];
            }
        }
    }
    return result;
}

Matrix33 Matrix33::operator*(double scalar) const {
    Matrix33 result(true);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            result.matrix[i][j] = matrix[i][j] * scalar;
        }
    }
    return result;
}

Matrix33 Matrix33::operator+(const Matrix33& other) const {
    Matrix33 result(true);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            result.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
        }
    }
    return result;
}

double Matrix33::determinant() const {
    double a = matrix[0][0], b = matrix[0][1], c = matrix[0][2];
    double d = matrix[1][0], e = matrix[1][1], f = matrix[1][2];
    double g = matrix[2][0], h = matrix[2][1], i = matrix[2][2];
    return a * (e * i - f * h) - b * (d * i - f * g) + c * (d * h - e * g);
}

istream& operator>>(istream& in, Matrix33& mat) {
    if (!mat.matrix) {
        mat.matrix = new double*[3];
        for (int i = 0; i < 3; ++i) mat.matrix[i] = new double[3];
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            in >> mat.matrix[i][j];
        }
    }
    return in;
}

ostream& operator<<(ostream& out, const Matrix33& mat) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            out << mat.matrix[i][j] << " ";
        }
        out << endl;
    }
    return out;
}
