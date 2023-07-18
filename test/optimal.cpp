#include <iostream>
#include <limits>
using namespace std;
#define N 6

void displayMatrix(int **matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void optimalMergePatterns(int arr[], int n)
{
    int cost[N][N], DP[N][N];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cost[i][j] = 0;
            DP[i][j] = 0;
        }
    }

    cout << "cost matrix before:" << endl;
    for (int i = 0; i < N; i++)
    {
        cout << endl;
        for (int j = 0; j < N; j++)
        {
            cout << cost[i][j] << " ";
        }
    }
    cout << endl;
    for (int l = 2; l <= n; l++)
    {
        for (int i = 0; i <= n - l; i++)
        {
            int j = i + l - 1;
            cost[i][j] = std::numeric_limits<int>::max();

            for (int k = i; k < j; k++)
            {
                int c = (cost[i][k] + cost[k + 1][j]) + (arr[i] * arr[k + 1] * arr[j + 1]);
                if (c < cost[i][j])
                {
                    cost[i][j] = c;
                    DP[i][j] = k;
                }
            }
        }
    }

    std::cout << "Optimal Merge Patterns:\n";
    int i = 0, j = n - 1;
    while (i < j)
    {
        std::cout << "(A" << i;
        std::cout << " A" << DP[i][j] + 1 << ")";
        i = DP[i][j] + 1;
    }
    std::cout << "\nMinimum Cost: " << cost[0][n - 1] << std::endl;
}

int main()
{
    int arr[] = {30, 35, 15, 5, 10, 20, 25};
    int n = sizeof(arr) / sizeof(arr[0]);

    optimalMergePatterns(arr, n);

    return 0;
}
