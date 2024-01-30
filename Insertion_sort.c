#include <stdio.h>
#include <time.h>

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    const int n = 5; // Array size

    int arr[n] = {3, 1, 7, 4, 2}; // Predefined array

    // Measure the time taken to run insertion sort
    clock_t start_time = clock();
    insertionSort(arr, n);
    clock_t end_time = clock();

    // Calculate the time taken in milliseconds
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC * 1000;

    // Display the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    // Display the time taken in milliseconds
    printf("\nTime taken to run Insertion Sort: %f milliseconds\n", time_taken);

    return 0;
}
