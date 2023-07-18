#include <stdio.h>
#include <limits.h>

#define N 6

// Function to find the optimal merge patterns using dynamic programming
void optimalMergePatterns(int arr[], int n)
{
    // Initialize the cost and DP arrays
    int cost[N][N], DP[N][N];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cost[i][j] = 0;
            DP[i][j] = 0;
        }
    }

    // Fill the cost and DP arrays

    for (int l = 2; l <= n; l++)
    {
        for (int i = 0; i <= n - l; i++)
        {
            int j = i + l - 1;
            cost[i][j] = INT_MAX;
            // Find the minimum cost of merging the subarrays between i and j
            for (int k = i; k < j; k++)
            {
                printf("\n\n\n\n\n\n\n\n\n**************************** START     (l:%d,i:%d, j:%d,k:%d,)*******************************", l, i, j, k);
                int c = (cost[i][k] + cost[k + 1][j]) + (arr[i] * arr[k + 1] * arr[j + 1]);
                printf("arr[i:%d] = %d\n\n", i, arr[i]);
                printf("arr[k+1:%d] = %d\n\n", k + 1, arr[k + 1]);
                printf("arr[j+1:%d] = %d\n\n", j + 1, arr[j + 1]);

                printf("cost[i:%d][k:%d] = %d\n\n", i, k, c);
                printf("cost[(k+1):%d][j:%d] = %d\n\n", k + 1, j, c);

                printf("cost[(k+1):%d][j:%d] = %d\n\n", k + 1, j, c);

                printf("cost[i:%d][j:%d] = %d\n\n", i, j, c);
                printf("(arr[i:%d] * arr[(k + 1):%d] * arr[(j + 1]):%d)=:%d", i, k + 1, j, (arr[i] * arr[k + 1] * arr[j + 1]));
                if (c < cost[i][j])
                {

                    printf("\n\n\n\nif condition met-------------");
                    printf("\n(before) cost[i:%d][j:%d] = %d\n\n", i, j, c);
                    printf("(before) DP[i:%d][j:%d] = %d\n\n", i, j, k);
                    cost[i][j] = c;
                    DP[i][j] = k;
                    printf("(after) cost[i:%d][j:%d] = %d\n\n", i, j, c);
                    printf("(after) DP[i:%d][j:%d] = %d\n\n", i, j, k);
                }
                printf("\n##########################  END   (l:%d,i:%d, j:%d,k:%d) #######################", l, i, j, k);
            }
        }
    }

    // Print the optimal merge patterns
    printf("Optimal Merge Patterns:\n");
    int i = 0, j = n - 1;
    while (i < j)
    {
        printf("(A%d", i);
        printf(" A%d)", DP[i][j] + 1);
        i = DP[i][j] + 1;
    }
    printf("\nMinimum Cost: %d\n", cost[0][n - 1]);
}

// Main function
int main()
{
    int arr[] = {30, 35, 15, 5, 10, 20, 25};
    int n = sizeof(arr) / sizeof(arr[0]);

    optimalMergePatterns(arr, n);

    return 0;
}
