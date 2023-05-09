#include <stdio.h>

void strassen(int n, int A[][n], int B[][n], int C[][n])
{
    if (n == 1)
    {
        // C = A * B;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                C[i][j] = 0;
                for (int k = 0; k < n; k++)
                {
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }
        return;
    }

    int i, j;
    int k = n / 2;

    int A11[k][k], A12[k][k], A21[k][k], A22[k][k];
    int B11[k][k], B12[k][k], B21[k][k], B22[k][k];
    int C11[k][k], C12[k][k], C21[k][k], C22[k][k];
    int P1[k][k], P2[k][k], P3[k][k], P4[k][k], P5[k][k], P6[k][k], P7[k][k];

    // Divide A and B into 4 submatrices
    for (i = 0; i < k; i++)
    {
        for (j = 0; j < k; j++)
        {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + k];
            A21[i][j] = A[i + k][j];
            A22[i][j] = A[i + k][j + k];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + k];
            B21[i][j] = B[i + k][j];
            B22[i][j] = B[i + k][j + k];
        }
    }

    // Compute the 7 products
    strassen(k, A11, B11, P1);
    strassen(k, A12, B21, P2);
    strassen(k, A11, B12, P3);
    strassen(k, A12, B22, P4);
    strassen(k, A21, B11, P5);
    strassen(k, A22, B21, P6);
    strassen(k, A21, B12, P7);
    strassen(k, A22, B22, C22);

    // Compute the 4 quadrants of the result matrix
    for (i = 0; i < k; i++)
    {
        for (j = 0; j < k; j++)
        {
            C11[i][j] = P1[i][j] + P2[i][j];
            C12[i][j] = P3[i][j] + P4[i][j];
            C21[i][j] = P5[i][j] + P6[i][j];
            C22[i][j] = P7[i][j] + C22[i][j];
        }
    }

    // Combine the 4 quadrants into the result matrix
    for (i = 0; i < k; i++)
    {
        for (j = 0; j < k; j++)
        {
            C[i][j] = C11[i][j];
            C[i][j + k] = C12[i][j];
            C[i + k][j] = C21[i][j];
            C[i + k][j + k] = C22[i][j];
        }
    }
}

int main()
{
    int n, i, j;

    printf("Enter the size of the matrices: ");
    scanf("%d", &n);

    int A[n][n], B[n][n], C[n][n];

    printf("Enter the elements of matrix A:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter the elements of matrix B:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &B[i][j]);
        }
    }

    strassen(n, A, B, C);

    printf("The product of the matrices is:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}