#include <iostream>
using namespace std;

int main() {
    int c1, c2, r1, r2;

    cout << "Enter r1 and c1: ";
    cin >> r1 >> c1;
    int m1[r1][c1];
    cout << "Enter elements of first matrix: ";
    for (int i = 0; i < r1 * c1; i++) {
        int row = i / c1, column = i % c1;
        cin >> m1[row][column];
    }

    cout << "Enter r2 and c2: ";
    cin >> r2 >> c2;
    int m2[r2][c2];
    cout << "Enter elements of second matrix: ";
    for (int i = 0; i < r2 * c2; i++) {
        int row = i / c2, column = i % c2;
        cin >> m2[row][column];
    }

    if (c1 != r2) {
        cout << "These matrices can't be multiplied!" << endl;
        return -1;
    }

    cout << "m1: " << endl;
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            cout << m1[i][j] << " ";
        }
        cout << endl;
    }

    cout << "m2: " << endl;
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            cout << m2[i][j] << " ";
        }
        cout << endl;
    }

    int res[r1][c2];

    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            res[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                res[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }

    cout << "Result: " << endl;

    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}
