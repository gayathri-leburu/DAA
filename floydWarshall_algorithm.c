#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void initializeGraph(int **graph, int numVertices) {
    printf("Enter the adjacency matrix (use -1 for infinity):\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == -1) {
                graph[i][j] = INT_MAX;
            }
        }
    }
}

void floydWarshall(int numVertices, int **graph) {
    int **dist = malloc(numVertices * sizeof(int *));
    for (int i = 0; i < numVertices; i++) {
        dist[i] = malloc(numVertices * sizeof(int));
        for (int j = 0; j < numVertices; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    for (int k = 0; k < numVertices; k++) {
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print shortest distances
    printf("Shortest distances between every pair of vertices:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            if (dist[i][j] == INT_MAX) {
                printf("INF ");
            } else {
                printf("%d ", dist[i][j]);
            }
        }
        printf("\n");
    }

    // Free allocated memory
    for (int i = 0; i < numVertices; i++) {
        free(dist[i]);
    }
    free(dist);
}

int main() {
    int numVertices;
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    int **graph = malloc(numVertices * sizeof(int *));
    for (int i = 0; i < numVertices; i++) {
        graph[i] = malloc(numVertices * sizeof(int));
    }

    initializeGraph(graph, numVertices);
    floydWarshall(numVertices, graph);

    // Free allocated memory
    for (int i = 0; i < numVertices; i++) {
        free(graph[i]);
    }
    free(graph);

    return 0;
}


******************
OUTPUT
******************
