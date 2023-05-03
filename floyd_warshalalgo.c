#include <stdio.h>
#include <limits.h>

#define V 4

void floydWarshall(int graph[V][V]) {
    int dist[V][V];
    int i, j, k;

    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    printf("Shortest distance between all pairs of vertices:\n");
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            if (dist[i][j] == INT_MAX) {
                printf("INF ");
            } else {
                printf("%d ", dist[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    int graph[V][V] = {{0, 5, INT_MAX, 10},
                       {INT_MAX, 0, 3, INT_MAX},
                       {INT_MAX, INT_MAX, 0, 1},
                       {INT_MAX, INT_MAX, INT_MAX, 0}};

    floydWarshall(graph);

    return 0;
}
