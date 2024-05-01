#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Edge {
    int src, dest, weight;
} Edge;

typedef struct Graph {
    int numVertices, numEdges;
    Edge* edges;
} Graph;

Graph* createGraph(int numVertices, int numEdges) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->numEdges = numEdges;
    graph->edges = (Edge*)malloc(numEdges * sizeof(Edge));
    return graph;
}

void initializeDistances(int* dist, int numVertices, int src) {
    for (int i = 0; i < numVertices; i++) {
        dist[i] = INT_MAX;
    }
    dist[src] = 0;
}

void relaxEdges(Graph* graph, int* dist) {
    for (int i = 0; i < graph->numVertices - 1; i++) {
        for (int j = 0; j < graph->numEdges; j++) {
            int u = graph->edges[j].src;
            int v = graph->edges[j].dest;
            int weight = graph->edges[j].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }
}

void checkNegativeCycles(Graph* graph, int* dist) {
    for (int i = 0; i < graph->numEdges; i++) {
        int u = graph->edges[i].src;
        int v = graph->edges[i].dest;
        int weight = graph->edges[i].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            printf("Graph contains negative-weight cycle\n");
            return;
        }
    }
}

void printDistances(int* dist, int numVertices) {
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < numVertices; i++) {
        if (dist[i] == INT_MAX)
            printf("%d -> INF\n", i);
        else
            printf("%d -> %d\n", i, dist[i]);
    }
}

void bellmanFord(Graph* graph, int src) {
    int* dist = malloc(graph->numVertices * sizeof(int));
    initializeDistances(dist, graph->numVertices, src);
    relaxEdges(graph, dist);
    checkNegativeCycles(graph, dist);
    printDistances(dist, graph->numVertices);
    free(dist);
}

int main() {
    int numVertices, numEdges;
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    Graph* graph = createGraph(numVertices, numEdges);

    printf("Enter the edges (source destination weight):\n");
    for (int i = 0; i < numEdges; i++) {
        scanf("%d %d %d", &graph->edges[i].src, &graph->edges[i].dest, &graph->edges[i].weight);
    }

    int sourceVertex;
    printf("Enter the source vertex for the Bellman-Ford algorithm: ");
    scanf("%d", &sourceVertex);

    bellmanFord(graph, sourceVertex);

    free(graph->edges);
    free(graph);
    return 0;
}



*****************
OUTPUT
*****************
Enter the number of vertices: 4
Enter the number of edges: 5
Enter the edges (source destination weight):
0 1 1
1 2 3
 2 3 12 3 1
3 1 -6
0 3 10
Enter the source vertex for the Bellman-Ford algorithm: 1
Graph contains negative-weight cycle
Vertex   Distance from Source
0 -> INF
1 -> -6
2 -> -1
3 -> 0
