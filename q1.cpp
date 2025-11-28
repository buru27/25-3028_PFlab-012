#include <stdio.h>
#include <stdlib.h>

int main() {
    int m, n, p;
    printf("Enter m, n, p: ");
    scanf("%d %d %d", &m, &n, &p);

    // A (m x n)
    int **A = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++)
        A[i] = (int *)malloc(n * sizeof(int));

    // B (n x p)
    int **B = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
        B[i] = (int *)malloc(p * sizeof(int));

    // C (m x p)
    int **C = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++)
        C[i] = (int *)malloc(p * sizeof(int));

    printf("\nEnter values for Matrix A:\n");
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &A[i][j]);

    printf("\nEnter values for Matrix B:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < p; j++)
            scanf("%d", &B[i][j]);

    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
    }

    printf("\nResult Matrix C (m x p):\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++)
            printf("%d ", C[i][j]);
        printf("\n");
    }

    
    for (int i = 0; i < m; i++) free(A[i]);
    for (int i = 0; i < n; i++) free(B[i]);
    for (int i = 0; i < m; i++) free(C[i]);
    free(A); free(B); free(C);

    return 0;
}

