#include <stdio.h>
#include <math.h>



int main(){
    // Matrix Computaion
    int A[3][3] = {{1, 2, 2}, {0, 2, 0}, {0, 0, 0}};
    int v[3] = {4, 0, 1};
    int result[3] = {0, 0, 0};

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result[i] += A[i][j] * v[j];
        }
    }

    printf("Result of matrix-vector multiplication:\n");
    for (int i = 0; i < 3; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    return 0;
}