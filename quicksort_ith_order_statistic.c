#include <stdio.h>
#include <stdlib.h>

// Function prototypes
int partition(int arr[], int low, int high);
int quickSelect(int arr[], int low, int high, int i);
void swap(int* a, int* b);

// QuickSort partition function
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// QuickSelect function to find ith order statistic
int quickSelect(int arr[], int low, int high, int i) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        if (pivotIndex == i)
            return arr[pivotIndex];
        else if (pivotIndex < i)
            return quickSelect(arr, pivotIndex + 1, high, i);
        else
            return quickSelect(arr, low, pivotIndex - 1, i);
    }
    return arr[low]; // If array contains only one element
}

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int arr[] = {3, 1, 2, 8, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int i = 2; // Find the 2nd order statistic

    int ithOrderStatistic = quickSelect(arr, 0, n - 1, i - 1);
    printf("The %dth order statistic is: %d\n", i, ithOrderStatistic);

    return 0;
}



**********
OUTPUT
***********
array : 3, 1, 2, 8, 6

The 2th order statistic is: 2
