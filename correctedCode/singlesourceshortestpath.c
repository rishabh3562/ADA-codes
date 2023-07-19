#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 9 // number of vertices in the graph

// function to find the vertex with minimum distance value
int minDistance(int dist[], int sptSet[])
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == 0 && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

// function to print the shortest path from the source vertex to all other vertices
void printSolution(int dist[], int n)
{
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t %d\n", i, dist[i]);
}

// function to implement Dijkstra's algorithm for a graph represented using adjacency matrix
void dijkstra(int graph[V][V], int src)
{
    int dist[V]; // array to store the shortest distance from source vertex to i-th vertex
    int sptSet[V]; // to represent set of vertices included in shortest path tree

    // initialize all distances as INFINITE and sptSet[] as 0
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = 0;

    // distance of source vertex from itself is always 0
    dist[src] = 0;

    // find shortest path for all vertices
    for (int count = 0; count < V - 1; count++)
    {
        // pick the minimum distance vertex from the set of vertices not yet processed
        int u = minDistance(dist, sptSet);

        // mark the picked vertex as processed
        sptSet[u] = 1;

        // update dist value of the adjacent vertices of the picked vertex
        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];

                
    }

    // print the shortest path from the source vertex to all other vertices
    printSolution(dist, V);
}

int main()
{
    int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                       {4, 0, 8, 0, 0, 0, 0, 11, 0},
                       {0, 8, 0, 7, 0, 4, 0, 0, 2},
                       {0, 0, 7, 0, 9, 14, 0, 0, 0},
                       {0, 0, 0, 9, 0, 10, 0, 0, 0},
                       {0, 0, 4, 14, 10, 0, 2, 0, 0},
                       {0, 0, 0, 0, 0, 2, 0, 1, 6},
                       {8, 11, 0, 0, 0, 0, 1, 0, 7},
                       {0, 0, 2, 0, 7, 0, 6, 7, 0}};

    dijkstra(graph, 0);

    return 0;
}

/*
output:-
Vertex   Distance from Source
0        0
1        4
2        12
3        19
4        21
5        11
6        9
7        8
8        14

*/