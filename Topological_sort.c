#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100

struct Node {
    char name[20];
    struct Node* next;
};

struct Graph {
    struct Node* adjacency_list[MAX_NODES];
};

struct Node* create_node(char* name) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    strcpy(new_node->name, name);
    new_node->next = NULL;
    return new_node;
}

void add_edge(struct Graph* graph, char* src, char* dest) {
    int i;
    for (i = 0; i < MAX_NODES; i++) {
        if (graph->adjacency_list[i] == NULL) {
            graph->adjacency_list[i] = create_node(dest);
            break;
        }
    }
    struct Node* new_node = create_node(src);
    new_node->next = graph->adjacency_list[i];
    graph->adjacency_list[i] = new_node;
}

void depth_first_search(struct Graph* graph, char* node, int* visited, char** topological_order, int* index) {
    int i;
    for (i = 0; i < MAX_NODES; i++) {
        if (graph->adjacency_list[i] != NULL && strcmp(graph->adjacency_list[i]->name, node) == 0 && !visited[i]) {
            visited[i] = 1;
            struct Node* current = graph->adjacency_list[i]->next;
            while (current != NULL) {
                depth_first_search(graph, current->name, visited, topological_order, index);
                current = current->next;
            }
            topological_order[*index] = graph->adjacency_list[i]->name;
            (*index)++;
            break;
        }
    }
}

void topological_sort(struct Graph* graph, char** topological_order) {
    int visited[MAX_NODES] = {0};
    int index = 0;
    int i;
    for (i = 0; i < MAX_NODES; i++) {
        if (graph->adjacency_list[i] != NULL && !visited[i]) {
            depth_first_search(graph, graph->adjacency_list[i]->name, visited, topological_order, &index);
        }
    }
}

int main() {
    struct Graph graph;
    memset(&graph, 0, sizeof(struct Graph));

    add_edge(&graph, "belt", "jacket");
    add_edge(&graph, "pants", "shoes");
    add_edge(&graph, "belt", "jacket");
    add_edge(&graph, "jacket", "");
    add_edge(&graph, "shirt", "belt");
    add_edge(&graph, "shirt", "tie");
    add_edge(&graph, "tie", "jacket");
    add_edge(&graph, "socks", "shoes");
    add_edge(&graph, "undershorts", "pants");
    add_edge(&graph, "undershorts", "shoes");

    char* topological_order[MAX_NODES];
    topological_sort(&graph, topological_order);

    printf("Topological order: [");
    for (int i = MAX_NODES - 1; i >= 0; i--) {
        if (topological_order[i] != NULL) {
            printf("'%s'", topological_order[i]);
            if (i != 0 && topological_order[i - 1] != NULL) {
                printf(", ");
            }
        }
    }
    printf("]\n");

    return 0;
}


**************************
OUTPUT
**************************
Topological order: ['undershorts', 'socks', 'tie', 'shoes', 'shirt', 'jacket', 'belt', 'pants']
