#include <stdio.h>
#include <time.h>

void selectionSort(int arr[], int n) {
    int i, j, min_index, temp;
    for (i = 0; i < n - 1; i++) {
        min_index = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        // Swap the found minimum element with the first element
        temp = arr[min_index];
        arr[min_index] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    const int n = 5; // Array size

    int arr[5] = {34, 12, 7, 45, 23}; // Predefined array

    // Measure the time taken to run selection sort
    clock_t start_time = clock();
    selectionSort(arr, n);
    clock_t end_time = clock();

    // Calculate the time taken in milliseconds
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC * 1000;

    // Display the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    // Display the time taken in milliseconds
    printf("\nTime taken to run Selection Sort: %f milliseconds\n", time_taken);

    return 0;
}
