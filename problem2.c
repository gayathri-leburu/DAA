#include <stdio.h>

// Function to remove duplicate elements from the sorted array
int removeDuplicates(int array[], int n) {
    if (n == 0 || n == 1)
        return n;

    int j = 0;
    for (int i = 0; i < n - 1; i++) {
        if (array[i] != array[i + 1])
            array[j++] = array[i];
    }
    array[j++] = array[n - 1];

    return j;
}

// Function to print the array
void printArray(int array[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");
}

// Main function
int main() {
    int array[100], n;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array in sorted order: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &array[i]);

    printf("Original Array: ");
    printArray(array, n);

    // Removing duplicates
    n = removeDuplicates(array, n);

    printf("Array after removing duplicates: ");
    printArray(array, n);

    return 0;
}


*** OUTPUT ***

Enter the number of elements in the array: 5
Enter the elements of the array in sorted order: 2 2 2 2 2
Original Array: 2 2 2 2 2 
Array after removing duplicates: 2 
