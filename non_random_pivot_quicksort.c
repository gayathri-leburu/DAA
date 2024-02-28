#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function for quicksort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Quicksort function
void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

// Generate sorted array (best-case scenario)
void generate_sorted_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }
}

// Generate identical array (worst-case scenario)
void generate_identical_array(int arr[], int n, int val) {
    for (int i = 0; i < n; i++) {
        arr[i] = val;
    }
}

// Generate random array (average-case scenario)
void generate_random_array(int arr[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % n + 1;
    }
}

// Utility function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n = 100000; // Size of the array
    int arr[n];    // Array to store elements

    clock_t start, end;
    double cpu_time_used;

    // Best-case scenario: Sorted array
    generate_sorted_array(arr, n);
    start = clock();
    quicksort(arr, 0, n - 1);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Sorted array (Best case): Time taken: %lf seconds\n", cpu_time_used);

    // Worst-case scenario: Identical array
    generate_identical_array(arr, n, 1);
    start = clock();
    quicksort(arr, 0, n - 1);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Identical array (Worst case): Time taken: %lf seconds\n", cpu_time_used);

    // Average-case scenario: Random array
    generate_random_array(arr, n);
    start = clock();
    quicksort(arr, 0, n - 1);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Random array (Average case): Time taken: %lf seconds\n", cpu_time_used);

    return 0;
}
