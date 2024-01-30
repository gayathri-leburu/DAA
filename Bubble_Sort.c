#include <stdio.h>
#include <time.h>

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap if the element found is greater than the next element
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    const int n = 5; // Array size

    int arr[5] = {3, 1, 7, 4, 2}; // Predefined array

    // Measure the time taken to run bubble sort
    clock_t start_time = clock();
    bubbleSort(arr, n);
    clock_t end_time = clock();

    // Calculate the time taken in milliseconds
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC * 1000;

    // Display the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    // Display the time taken in milliseconds
    printf("\nTime taken to run Bubble Sort: %f milliseconds\n", time_taken);

    return 0;
}
