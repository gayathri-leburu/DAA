#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

// Graph representation with an adjacency list
int adj[MAX_NODES][MAX_NODES];
int visited[MAX_NODES];
int n; // number of nodes
int stack[MAX_NODES], top = -1;

void addEdge(int u, int v) {
    adj[u][v] = 1; // add a directed edge from u to v
}

void dfs(int v) {
    visited[v] = 1;
    for (int i = 0; i < n; i++) {
        if (adj[v][i] && !visited[i]) {
            dfs(i);
        }
    }
    stack[++top] = v; // Push onto stack as we backtrack
}

void topologicalSort() {
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    while (top != -1) {
        printf("%d ", stack[top--]);
    }
    printf("\n");
}

int main() {
    n = 6;
    addEdge(5, 2);
    addEdge(5, 0);
    addEdge(4, 0);
    addEdge(4, 1);
    addEdge(2, 3);
    addEdge(3, 1);
    
    printf("Topological Sorting: ");
    topologicalSort();
    return 0;
}


**********
OUTPUT
**********

Topological Sorting: 5 4 2 3 1 0 
