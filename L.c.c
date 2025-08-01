#include <stdio.h>

#define SIZE 3  // You can change this for larger matrices

void printMatrix(float mat[SIZE][SIZE], char name) {
    printf("\nMatrix %c:\n", name);
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%8.4f ", mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    float A[SIZE][SIZE], L[SIZE][SIZE] = {0}, U[SIZE][SIZE] = {0};
    int i, j, k;

    // Input the matrix A
    printf("Enter the elements of matrix A (%dx%d):\n", SIZE, SIZE);
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            scanf("%f", &A[i][j]);
        }
    }

    // LU Decomposition
    for (i = 0; i < SIZE; i++) {
        // Upper Triangular
        for (k = i; k < SIZE; k++) {
            float sum = 0;
            for (j = 0; j < i; j++)
                sum += (L[i][j] * U[j][k]);

            U[i][k] = A[i][k] - sum;
        }

        // Lower Triangular
        for (k = i; k < SIZE; k++) {
            if (i == k)
                L[i][i] = 1; // Diagonal as 1
            else {
                float sum = 0;
                for (j = 0; j < i; j++)
                    sum += (L[k][j] * U[j][i]);

                L[k][i] = (A[k][i] - sum) / U[i][i];
            }
        }
    }

    printMatrix(L, 'L');
    printMatrix(U, 'U');

    return 0;
}
