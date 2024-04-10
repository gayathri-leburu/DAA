#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *array;
    size_t used;
    size_t size;
} DynamicArray;

void initArray(DynamicArray *a, size_t initialSize) {
    a->array = (int *)malloc(initialSize * sizeof(int));
    if (a->array == NULL) {
        perror("Failed to allocate initial memory for dynamic array");
        exit(EXIT_FAILURE);
    }
    a->used = 0;
    a->size = initialSize;
}

void insertArray(DynamicArray *a, int element) {
    // Resize if necessary
    if (a->used == a->size) {
        a->size *= 2;
        int *temp = (int *)realloc(a->array, a->size * sizeof(int));
        if (temp == NULL) {
            perror("Failed to allocate additional memory for dynamic array");
            free(a->array);
            exit(EXIT_FAILURE);
        }
        a->array = temp;
    }

    a->array[a->used++] = element;
}

void freeArray(DynamicArray *a) {
    free(a->array);
    a->array = NULL;
    a->used = a->size = 0;
}

// Utility function for printing the array's elements (for demonstration)
void printArray(const DynamicArray *a) {
    printf("DynamicArray: ");
    for (size_t i = 0; i < a->used; i++) {
        printf("%d ", a->array[i]);
    }
    printf("\n");
}

int main() {
    DynamicArray a;
    size_t initialSize = 4;

    initArray(&a, initialSize);
    for (int i = 0; i < 10; ++i) {
        insertArray(&a, i);
    }


  *****************************
    OUTPUT
  *****************************

  DynamicArray: 0 1 2 3 4 5 6 7 8 9 

    printArray(&a);
    freeArray(&a);

    return 0;
}
