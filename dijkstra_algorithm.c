#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

typedef struct {
    int vertex;
    int weight;
} Edge;

typedef struct {
    Edge *edges;
    int size;
    int capacity;
} AdjList;

typedef struct {
    int numVertices;
    AdjList *lists;
} Graph;

Graph *createGraph(int vertices) {
    Graph *graph = malloc(sizeof(Graph));
    graph->numVertices = vertices;
    graph->lists = malloc(vertices * sizeof(AdjList));
    for (int i = 0; i < vertices; i++) {
        graph->lists[i].edges = NULL;
        graph->lists[i].size = 0;
        graph->lists[i].capacity = 0;
    }
    return graph;
}

void addEdge(Graph *graph, int src, int dest, int weight) {
    if (graph->lists[src].size >= graph->lists[src].capacity) {
        if (graph->lists[src].capacity == 0)
            graph->lists[src].capacity = 4;
        else
            graph->lists[src].capacity *= 2;
        graph->lists[src].edges = realloc(graph->lists[src].edges, graph->lists[src].capacity * sizeof(Edge));
    }
    graph->lists[src].edges[graph->lists[src].size++] = (Edge){ dest, weight };
}

int minDistance(int *dist, bool *visited, int vertices) {
    int min = INT_MAX, min_index = -1;
    for (int v = 0; v < vertices; v++) {
        if (!visited[v] && dist[v] < min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void printPath(int *parent, int j) {
    if (parent[j] == -1)
        return;
    printPath(parent, parent[j]);
    printf(" -> %d", j);
}

void dijkstra(Graph *graph, int src) {
    int vertices = graph->numVertices;
    int dist[vertices], parent[vertices];
    bool visited[vertices];

    for (int i = 0; i < vertices; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
        parent[i] = -1;
    }

    dist[src] = 0;

    for (int count = 0; count < vertices - 1; count++) {
        int u = minDistance(dist, visited, vertices);
        visited[u] = true;

        for (int i = 0; i < graph->lists[u].size; i++) {
            int v = graph->lists[u].edges[i].vertex;
            int weight = graph->lists[u].edges[i].weight;
            if (!visited[v] && dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                parent[v] = u;
            }
        }
    }

    for (int i = 0; i < vertices; i++) {
        printf("%d: Distance from %d = %d, Path = %d", i, src, dist[i], src);
        printPath(parent, i);
        printf("\n");
    }
}

int main() {
    int numVertices = 6;
    Graph *graph = createGraph(numVertices);
    addEdge(graph, 0, 1, 5);
    addEdge(graph, 0, 2, 3);
    addEdge(graph, 1, 3, 6);
    addEdge(graph, 1, 2, 2);
    addEdge(graph, 2, 4, 4);
    addEdge(graph, 2, 5, 2);
    addEdge(graph, 2, 3, 7);
    addEdge(graph, 3, 4, -1);
    addEdge(graph, 4, 5, -2);

    int sourceVertex = 0;
    printf("Dijkstra's Algorithm from vertex %d:\n", sourceVertex);
    dijkstra(graph, sourceVertex);

    // Free memory
    for (int i = 0; i < numVertices; i++) {
        free(graph->lists[i].edges);
    }
    free(graph->lists);
    free(graph);
    return 0;
}


**********************
OUTPUT
**********************
  
Dijkstra's Algorithm from vertex 0:
  
0: Distance from 0 = 0, Path = 0
1: Distance from 0 = 5, Path = 0 -> 1
2: Distance from 0 = 3, Path = 0 -> 2
3: Distance from 0 = 10, Path = 0 -> 2 -> 3
4: Distance from 0 = 7, Path = 0 -> 2 -> 4
5: Distance from 0 = 5, Path = 0 -> 2 -> 5
