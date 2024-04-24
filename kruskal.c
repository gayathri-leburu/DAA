#include <stdio.h>
#include <stdlib.h>

#define MAX_EDGES 100

typedef struct Edge {
    int src, dest, weight;
} Edge;

typedef struct EdgeList {
    Edge data[MAX_EDGES];
    int size;
} EdgeList;

EdgeList elist;

int parent[MAX_EDGES];
int n; // Number of vertices

void Union(int i, int j) {
    parent[find(i)] = find(j);
}

int find(int i) {
    while (parent[i])
        i = parent[i];
    return i;
}

void kruskal() {
    int i, j, a, b;
    Edge t;
    
    // Sorting edges based on their weight
    for (i = 1; i < elist.size; i++) {
        for (j = 0; j < elist.size - 1; j++) {
            if (elist.data[j].weight > elist.data[j + 1].weight) {
                t = elist.data[j];
                elist.data[j] = elist.data[j + 1];
                elist.data[j + 1] = t;
            }
        }
    }

    for (i = 0; i < n; i++) {
        parent[i] = 0;
    }

    int edge_count = 0;
    for (i = 0; i < elist.size; i++) {
        a = find(elist.data[i].src);
        b = find(elist.data[i].dest);
        if (a != b) {
            printf("Edge %d:(%d, %d) weight:%d \n", edge_count++, elist.data[i].src, elist.data[i].dest, elist.data[i].weight);
            Union(a, b);
        }
    }
}

void addEdge(int src, int dest, int weight) {
    elist.data[elist.size].src = src;
    elist.data[elist.size].dest = dest;
    elist.data[elist.size].weight = weight;
    elist.size++;
}

int main() {
    elist.size = 0;
    n = 4;

    addEdge(0, 1, 10);
    addEdge(0, 2, 6);
    addEdge(0, 3, 5);
    addEdge(1, 3, 15);
    addEdge(2, 3, 4);

    printf("Edges of MST are \n");
    kruskal();
    return 0;
}


*************
OUTPUT
*************

Edges of MST are 
Edge 0:(2, 3) weight:4 
Edge 1:(0, 3) weight:5 
Edge 2:(0, 1) weight:10 
