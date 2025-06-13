#include "Matrix.hpp"
#include <iostream>

using namespace std;

Matrix::Matrix(int r, int c) : rows(r), cols(c) {
    matrix.resize(rows, std::vector<double>(cols, 0.0));
}

void Matrix::input() {
    cout << "Enter " << rows * cols << " values for the matrix (row-wise):\n";
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            cin >> matrix[i][j];
}

std::vector<double> Matrix::multiply(const std::vector<double>& vec) const {
    std::vector<double> result(rows, 0.0);
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            result[i] += matrix[i][j] * vec[j];
    return result;
}

void Matrix::print() const {
    for (const auto& row : matrix) {
        for (double val : row)
            cout << val << " ";
        cout << endl;
    }
}
