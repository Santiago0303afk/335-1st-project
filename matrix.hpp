#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <vector>
#include <iostream>

class Matrix {
private:
    int rows, cols;
    std::vector<std::vector<double>> matrix;

public:
    Matrix(int r, int c);

    void input();
    std::vector<double> multiply(const std::vector<double>& vec) const;
    void print() const;
};

#endif