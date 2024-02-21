#include <stdio.h>
#include <stdlib.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify(int arr[], int n, int i) {
    int smallest = i;  // Initialize smallest as root
    int left = (i << 1) + 1;  // left = 2*i + 1
    int right = (i << 1) + 2;  // right = 2*i + 2

    // If left child is smaller than root
    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    // If right child is smaller than smallest so far
    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    // If smallest is not root
    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        // Recursively heapify the affected sub-tree
        heapify(arr, n, smallest);
    }
}

// Function to build a min heap
void buildHeap(int arr[], int n) {
    int startIdx = (n / 2) - 1;
    for (int i = startIdx; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

// Function to remove and return the root node from the heap
int extractRoot(int arr[], int *n) {
    if (*n == 0) return -1; // Heap is empty

    int root = arr[0];
    arr[0] = arr[*n - 1];
    (*n)--;
    heapify(arr, *n, 0);
    return root;
}

// Function to print the heap
void printHeap(int arr[], int n) {
    printf("Heap: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    buildHeap(arr, n);
    printHeap(arr, n);

    // Extracting and printing the root node
    int root = extractRoot(arr, &n);
    if (root != -1) {
        printf("Root node removed from the heap: %d\n", root);
        printf("Heap after removal:\n");
        printHeap(arr, n);
    } else {
        printf("Heap is empty, cannot remove root node.\n");
    }

    return 0;
}



***************************
********* OUTPUT **********
***************************

Enter the number of elements: 5
Enter 5 elements: 8 3 2 9 5
Heap: 2 3 8 9 5 
Root node removed from the heap: 2
Heap after removal:
Heap: 3 5 8 9 
