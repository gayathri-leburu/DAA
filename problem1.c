
#include <stdio.h>
#include <stdlib.h>

// Function to merge two sorted arrays
void merge(int arr1[], int arr2[], int n1, int n2, int res[]) {
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j])
            res[k++] = arr1[i++];
        else
            res[k++] = arr2[j++];
    }

    while (i < n1)
        res[k++] = arr1[i++];

    while (j < n2)
        res[k++] = arr2[j++];
}

// Function to merge K sorted arrays
void mergeKArrays(int *arrays[], int k, int n, int result[]) {
    // Create an array to store the indexes of the current elements of each array
    int indexes[k];
    for (int i = 0; i < k; i++)
        indexes[i] = 0;

    for (int count = 0; count < k * n; count++) {
        int min_val = INT_MAX;
        int min_index = -1;

        // Find the minimum value among the current elements of all arrays
        for (int i = 0; i < k; i++) {
            if (indexes[i] < n && arrays[i][indexes[i]] < min_val) {
                min_val = arrays[i][indexes[i]];
                min_index = i;
            }
        }

        // Store the minimum value in the result array
        result[count] = min_val;

        // Move to the next element in the array from which the minimum value was taken
        indexes[min_index]++;
    }
}

int main() {
    int k, n;

    // Input the number of arrays (k) and the size of each array (n)
    printf("Enter the number of arrays (k): ");
    scanf("%d", &k);
    printf("Enter the size of each array (n): ");
    scanf("%d", &n);

    // Allocate memory for the array of pointers to arrays
    int *arrays[k];

    // Input the arrays
    for (int i = 0; i < k; i++) {
        printf("Enter elements for array %d (sorted):\n", i + 1);
        arrays[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++)
            scanf("%d", &arrays[i][j]);
    }

    // Allocate memory for the result array
    int result[k * n];

    // Merge the arrays
    mergeKArrays(arrays, k, n, result);

    // Print the merged array
    printf("Merged array: ");
    for (int i = 0; i < k * n; i++)
        printf("%d ", result[i]);
    printf("\n");

    // Free allocated memory
    for (int i = 0; i < k; i++)
        free(arrays[i]);

    return 0;
}

*** OUTPUT ***
***/tmp/0KaiMiItRZ.o
Enter the number of arrays (k): 3
Enter the size of each array (n): 4
Enter elements for array 1 (sorted):
1
3
5
7
Enter elements for array 2 (sorted):
2
4
6
8
Enter elements for array 3 (sorted):
0
9
10
11
Merged array: 0 1 2 3 4 5 6 7 8 9 10 11 
***
