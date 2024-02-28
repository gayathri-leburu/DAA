/*This program defines two functions for quicksort: quicksort_non_random and quicksort_random. 
The former always selects the last element as the pivot, while the latter chooses a random pivot each time. 
The partition function is used differently in both cases to partition the array around the chosen pivot. 
Finally, main function demonstrates the usage of both versions of quicksort by sorting an array of integers.*/



#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function for quicksort with non-random pivot
int partition_non_random(int arr[], int low, int high) {
    int pivot = arr[high]; // Choosing the last element as pivot
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

// Partition function for quicksort with random pivot
int partition_random(int arr[], int low, int high) {
    srand(time(NULL)); // Seed for randomization
    int random = low + rand() % (high - low);
    swap(&arr[random], &arr[high]); // Swap random element with last element
    
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

// Quicksort with non-random pivot
void quicksort_non_random(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition_non_random(arr, low, high);

        quicksort_non_random(arr, low, pi - 1);
        quicksort_non_random(arr, pi + 1, high);
    }
}

// Quicksort with random pivot
void quicksort_random(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition_random(arr, low, high);

        quicksort_random(arr, low, pi - 1);
        quicksort_random(arr, pi + 1, high);
    }
}

// Utility function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array before sorting: \n");
    printArray(arr, n);

    // Sort using non-random pivot quicksort
    quicksort_non_random(arr, 0, n - 1);
    printf("Array after non-random pivot quicksort: \n");
    printArray(arr, n);

    // Re-initialize array
    int arr2[] = {10, 7, 8, 9, 1, 5};

    // Sort using random pivot quicksort
    quicksort_random(arr2, 0, n - 1);
    printf("Array after random pivot quicksort: \n");
    printArray(arr2, n);

    return 0;
}

/* OUTPUT
Array before sorting: 
10 7 8 9 1 5 
Array after non-random pivot quicksort: 
1 5 7 8 9 10 
Array after random pivot quicksort: 
1 5 7 8 9 10  */
