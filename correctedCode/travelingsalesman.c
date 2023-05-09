#include <stdio.h>
#include <limits.h>

#define V 4

int tsp(int graph[][V], int mask, int pos, int n, int dp[][1 << V]) {
    if (mask == (1 << n) - 1) {
        return graph[pos][0];
    }

    if (dp[pos][mask] != -1) {
        return dp[pos][mask];
    }

    int ans = INT_MAX;
    for (int city = 0; city < n; city++) {
        if ((mask & (1 << city)) == 0) {
            int newAns = graph[pos][city] + tsp(graph, mask | (1 << city), city, n, dp);
            if (newAns < ans) {
                ans = newAns;
            }
        }
    }

    dp[pos][mask] = ans;
    return ans;
}

int main() {
    int graph[V][V] = {{0, 10, 15, 20},
                       {10, 0, 35, 25},
                       {15, 35, 0, 30},
                       {20, 25, 30, 0}};

    int dp[V][1 << V];
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < (1 << V); j++) {
            dp[i][j] = -1;
        }
    }

    int minCost = tsp(graph, 1, 0, V, dp);

    printf("Minimum cost of traveling salesman: %d\n", minCost);

    return 0;
}
