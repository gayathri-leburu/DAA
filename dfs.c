#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int visited[MAX];
int graph[MAX][MAX];
int n; // number of vertices

void dfs(int vertex) {
    printf("%d ", vertex);
    visited[vertex] = 1;
    
    for (int i = 0; i < n; i++) {
        if (graph[vertex][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    n = 4;
    graph[0][1] = 1;
    graph[0][2] = 1;
    graph[1][2] = 1;
    graph[2][0] = 1;
    graph[2][3] = 1;
    graph[3][3] = 1;
    
    printf("DFS starting from vertex 2:\n");
    dfs(2);
    return 0;
}


*********
OUTPUT
*********

DFS starting from vertex 2:
2 0 1 3 
