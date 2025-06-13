#include "matrix33.hpp"
#include "vector3.hpp"
#include "Matrix.hpp"
#include <iostream>
#include <vector>
#include <limits>
using namespace std;

Vector3 multiply(const Matrix33& A, Vector3& x) {
    Vector3 b;
    for (int i = 0; i < 3; ++i) {
        double sum = 0;
        for (int j = 0; j < 3; ++j) {
            sum += A(i, j) * x(j);
        }
        b(i) = sum;
    }
    return b;
}

void runProblem1() {
    Matrix33 A(true);
    Vector3 x;

    cout << "Problem 1: Multiply a 3x3 matrix by a 3-element vector\n";
    cout << "Enter 3x3 matrix values (row-wise): ";
    cin >> A;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter a Point(x, y, z): ";
    cin >> x;

    Vector3 result = multiply(A, x);
    cout << "\nResult vector b = A * x:\n" << result;
}

void runProblem3() {
    int n, m;
    cout << "Problem 3: Multiply n x m matrix by m-element vector\n";
    cout << "Enter number of rows (n): ";
    cin >> n;
    cout << "Enter number of columns (m): ";
    cin >> m;

    Matrix A(n, m);
    A.input();

    cout << "Enter a Point(x1, x2, ..., xm):\n";
    vector<double> x(m);
    for (int i = 0; i < m; ++i) {
        cin >> x[i];
    }

    vector<double> result = A.multiply(x);
    cout << "\nResult vector b = A * x:\n(";
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i];
        if (i < result.size() - 1) cout << ", ";
    }
    cout << ")\n";
}

int main() {
    int choice;

    cout << "Select which problem to run:\n";
    cout << "1. Problem 1 (Fixed 3x3 matrix)\n";
    cout << "2. Problem 3 (Dynamic n x m matrix using vector)\n";
    cout << "Enter choice: ";
    cin >> choice;

    cout << endl;

    if (choice == 1)
        runProblem1();
    else if (choice == 2)
        runProblem3();
    else
        cout << "Invalid choice.\n";

    return 0;
}

