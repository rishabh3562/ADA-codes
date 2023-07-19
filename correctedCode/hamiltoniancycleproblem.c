#include <stdio.h>
#define V 5 // Number of vertices in the graph

void printSolution(int path[]);

/* A utility function to check if the vertex v can be added at index 'pos'
   in the Hamiltonian Cycle constructed so far (stored in 'path[]') */
int isSafe(int v, int graph[V][V], int path[], int pos)
{
    printf("isSafe(v:%d, graph, path[pos-1]:%d,pos: %d)\n", v,path[pos-1], pos);
    // Check if this vertex is an adjacent vertex of the previously added vertex
    if (graph[path[pos - 1]][v] == 0)
        return 0;

    // Check if the vertex has already been included
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return 0;

    return 1;
}

/* A recursive function to solve the Hamiltonian cycle problem */
int hamCycleUtil(int graph[V][V], int path[], int pos)
{
    // Base case: If all vertices are included in the path
    if (pos == V)
    {
        // Check if there is an edge from the last vertex to the first vertex
        if (graph[path[pos - 1]][path[0]] == 1)
            return 1;
        else
            return 0;
    }

    // Try different vertices as the next candidate in the path
    for (int v = 1; v < V; v++)
    {
        if (isSafe(v, graph, path, pos))
        {
            path[pos] = v;

            if (hamCycleUtil(graph, path, pos + 1) == 1)
                return 1;

            // If adding vertex v doesn't lead to a solution, remove it
            path[pos] = -1;
        }
    }

    return 0;
}

/* Function to solve the Hamiltonian cycle problem */
void hamCycle(int graph[V][V])
{
    int path[V];
    for (int i = 0; i < V; i++)
        path[i] = -1;

    // Start from vertex 0 as the first vertex in the path
    path[0] = 0;

    if (hamCycleUtil(graph, path, 1) == 0)
        printf("Solution does not exist");
    else
        printSolution(path);
}

/* A utility function to print the solution */
void printSolution(int path[])
{
    printf("Hamiltonian Cycle found: ");
    for (int i = 0; i < V; i++)
        printf("%d ", path[i]);
    printf("%d ", path[0]);
    printf("\n");
}

/* The main function */
int main()
{
    int graph[V][V] = {{0, 1, 0, 1, 0},
                       {1, 0, 1, 1, 1},
                       {0, 1, 0, 0, 1},
                       {1, 1, 0, 0, 1},
                       {0, 1, 1, 1, 0}};

    hamCycle(graph);

    return 0;
}

/*
output:-Hamiltonian Cycle found: 0 1 2 4 3 0

*/