#include <stdio.h>
#include <limits.h>

#define N 6

// Function to find the optimal merge patterns using dynamic programming
void optimalMergePatterns(int arr[], int n) {
    // Initialize the cost and DP arrays
    int cost[N][N], DP[N][N];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cost[i][j] = 0;
            DP[i][j] = 0;
        }
    }

    // Fill the cost and DP arrays
    for (int l = 2; l <= n; l++) {
        for (int i = 0; i <= n - l; i++) {
            int j = i + l - 1;
            cost[i][j] = INT_MAX;

            // Find the minimum cost of merging the subarrays between i and j
            for (int k = i; k < j; k++) {
                int c = cost[i][k] + cost[k + 1][j] + arr[i] * arr[k + 1] * arr[j + 1];
                if (c < cost[i][j]) {
                    cost[i][j] = c;
                    DP[i][j] = k;
                }
            }
        }
    }

    // Print the optimal merge patterns
    printf("Optimal Merge Patterns:\n");
    int i = 0, j = n - 1;
    while (i < j) {
        printf("(A%d", i);
        printf(" A%d)", DP[i][j] + 1);
        i = DP[i][j] + 1;
    }
    printf("\nMinimum Cost: %d\n", cost[0][n - 1]);
}

// Main function
int main() {
    int arr[] = {30, 35, 15, 5, 10, 20, 25};
    int n = sizeof(arr) / sizeof(arr[0]);

    optimalMergePatterns(arr, n);

    return 0;
}
