#include <iostream>
#include <vector>

using namespace std;

int determinant2x2(const vector<vector<int>>& mat) {
    return mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
}

int determinant3x3(const vector<vector<int>>& mat) {
    return mat[0][0] * (mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1])
         - mat[0][1] * (mat[1][0] * mat[2][2] - mat[1][2] * mat[2][0])
         + mat[0][2] * (mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0]);
}

int determinant(const vector<vector<int>>& mat) {
    int n = mat.size();
    if (n == 2) {
        return determinant2x2(mat);
    } else if (n == 3) {
        return determinant3x3(mat);
    } else {
        cout << "Determinant calculation for matrices larger than 3x3 is not implemented." << endl;
        return 0;
    }
}

int main() {
    int n;
    cout << "Enter the size of the matrix (n x n): ";
    cin >> n;

    if (n < 2 || n > 3) {
        cout << "This program only supports 2x2 and 3x3 matrices." << endl;
        return 1;
    }

    vector<vector<int>> matrix(n, vector<int>(n));

    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    int det = determinant(matrix);
    cout << "The determinant of the matrix is: " << det << endl;

    return 0;
}

