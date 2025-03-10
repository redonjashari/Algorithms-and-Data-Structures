/*
    CH-231-A
    hw5
    Redon Jashari
    RJASHARI@constructor.university
*/

#include <iostream>
#include <chrono>
#include <vector>
#include <cmath>

using namespace std;
using namespace chrono;

int nthnFibonacciRecursion(int n) {
    if (n <= 1)
    {
        return n;
    }
    
    return nthnFibonacciRecursion(n - 1) + nthnFibonacciRecursion(n - 2);
}

int nthnFibonacciBottomup(int n) {
    if (n <= 1)
    {
        return n;
    }
    
    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; ++i)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int fibonacci_closed_form(int n) {
    const double sqrt5 = sqrt(5);
    const double phi = (1 + sqrt5) / 2;
    const double psi = (1 - sqrt5) / 2;

    return round((pow(phi, n) - pow(psi, n)) / sqrt5);
}

void multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
    int x = mat1[0][0] * mat2[0][0] + mat1[0][1] * mat2[1][0];
    int y = mat1[0][0] * mat2[0][1] + mat1[0][1] * mat2[1][1];
    int z = mat1[1][0] * mat2[0][0] + mat1[1][1] * mat2[1][0];
    int w = mat1[1][0] * mat2[0][1] + mat1[1][1] * mat2[1][1];

    mat1[0][0] = x;
    mat1[0][1] = y;
    mat1[1][0] = z;
    mat1[1][1] = w;
}

void matrixPower(vector<vector<int>>& mat1, int n) {
    if (n == 0 || n == 1) return;

    vector<vector<int>> mat2 = {{1, 1}, {1, 0}};

    matrixPower(mat1, n / 2);

    multiply(mat1, mat1);

    if (n % 2 != 0) {
        multiply(mat1, mat2);
    }
}

int nthFibonacciMatrix(int n) {
    if (n <= 1) return n;

    vector<vector<int>> mat1 = {{1, 1}, {1, 0}};

    matrixPower(mat1, n - 1);

    return mat1[0][0];
}

void measure_runtime() {
    int test_values[] = {0, 1, 2, 3, 4, 5, 6, 8, 10, 13, 16, 20, 25, 32, 40};

    cout << "n\tRecursive\tBottom-Up\tClosed-Form\tMatrix" << endl;
    for (int n : test_values) {
        auto start = high_resolution_clock::now();
        nthnFibonacciRecursion(n);
        auto end = high_resolution_clock::now();
        auto time1 = duration_cast<microseconds>(end - start).count();

        start = high_resolution_clock::now();
        nthnFibonacciBottomup(n);
        end = high_resolution_clock::now();
        auto time2 = duration_cast<microseconds>(end - start).count();

        start = high_resolution_clock::now();
        fibonacci_closed_form(n);
        end = high_resolution_clock::now();
        auto time3 = duration_cast<microseconds>(end - start).count();

        start = high_resolution_clock::now();
        nthFibonacciMatrix(n);
        end = high_resolution_clock::now();
        auto time4 = duration_cast<microseconds>(end - start).count();

        cout << n << "\t" << time1 << "us\t" << time2 << "us\t" << time3 << "us\t" << time4 << "us" << endl;
    }
}

int main() {
    measure_runtime();
    return 0;
}





