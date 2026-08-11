#include <stdio.h>

void display_array(int arr[], int len) {
    printf("[");
    for (int i = 0; i < len; i++) {
        printf("%d", arr[i]);
        if (i != len - 1) printf(", ");
    }
    printf("]\n");
}

int main() {
    // 1D ARRAY
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr1[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr1[i]);
    }
    printf("Your array: ");
    display_array(arr1, n);
    for (int i = 0; i < n / 2; i++) {
        int temp = arr1[i];
        arr1[i] = arr1[n - i - 1];
        arr1[n - i - 1] = temp;
    }
    printf("Reversed array: ");
    display_array(arr1, n);

    // 2D ARRAY
    int row, col;
    printf("Enter the dimensions of 2D array: ");
    scanf("%d %d", &row, &col);
    int arr2[row][col];
    printf("Enter the elements in your 2D array: ");
    for (int i = 0; i < row * col; i ++) {
        int current_row = i / col, current_col = i % col;
        scanf("%d", &arr2[current_row][current_col]);
    }
    printf("Your 2D array:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", arr2[i][j]);
        }
        printf("\n");
    }

    // MATRIX ADDITION
    printf("Enter the dimensions of the matrices you want to add: ");
    scanf("%d %d", &row, &col);
    int matrix1[row][col], matrix2[row][col], res[row][col];
    printf("Enter the elements of the first matrix: ");
    for (int i = 0; i < row * col; i ++) {
        int current_row = i / col, current_col = i % col;
        scanf("%d", &matrix1[current_row][current_col]);
    }
    printf("Enter the elements of the second matrix: ");
    for (int i = 0; i < row * col; i ++) {
        int current_row = i / col, current_col = i % col;
        scanf("%d", &matrix2[current_row][current_col]);
    }
    printf("Matrix 1:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", matrix1[i][j]);
        }
        printf("\n");
    }
    printf("Matrix 2:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", matrix2[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            res[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    printf("Result:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }
}
