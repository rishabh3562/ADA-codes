#include <stdio.h>
#include <stdlib.h>

#define MAX_EDGES 1000

struct Edge {
  int src, dest, weight;
};

struct Graph {
  int V, E;
  struct Edge edges[MAX_EDGES];
};

struct Subset {
  int parent;
  int rank;
};

int find(struct Subset subsets[], int i) {
  if (subsets[i].parent != i) {
    subsets[i].parent = find(subsets, subsets[i].parent);
  }
  return subsets[i].parent;
}

void Union(struct Subset subsets[], int x, int y) {
  int xroot = find(subsets, x);
  int yroot = find(subsets, y);

  if (subsets[xroot].rank < subsets[yroot].rank) {
    subsets[xroot].parent = yroot;
  } else if (subsets[xroot].rank > subsets[yroot].rank) {
    subsets[yroot].parent = xroot;
  } else {
    subsets[yroot].parent = xroot;
    subsets[xroot].rank++;
  }
}

int compare(const void* a, const void* b) {
  struct Edge* a1 = (struct Edge*)a;
  struct Edge* b1 = (struct Edge*)b;
  return a1->weight - b1->weight;
}

void Kruskal(struct Graph* graph) {
  int V = graph->V;
  struct Edge result[V];
  int e = 0;
  int i = 0;

  qsort(graph->edges, graph->E, sizeof(graph->edges), compare);

  struct Subset subsets[V];
  for (int v = 0; v < V; v++) {
    subsets[v].parent = v;
    subsets[v].rank = 0;
  }

  while (e < V - 1 && i < graph->E) {
    struct Edge next_edge = graph->edges[i++];

    int x = find(subsets, next_edge.src);
    int y = find(subsets, next_edge.dest);

    if (x != y) {
      result[e++] = next_edge;
      Union(subsets, x, y);
    }
  }

  printf("Minimum Spanning Tree:\n");
  for (i = 0; i < e; i++) {
    printf("%d - %d : %d\n", result[i].src, result[i].dest, result[i].weight);
  }
}

int main() {
  struct Graph graph = {4, 5, {{0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4}}};

  Kruskal(&graph);

  return 0;
}