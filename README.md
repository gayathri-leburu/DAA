**3. Mathematically derive the average runtime complexity of the non-random pivot version of quicksort.**

Code Snippet:
int partition_non_random(int arr[], int low, int high) {
// Choosing the last element as pivot
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

-- Partitioning Time :

- Each partitioning operation takes O(n) time, where n is the size of the subarray being partitioned.
- This is because in the worst case, we might need to compare each element with the pivot.

-- Average Number of Comparisons :

- Let T(n) be the average number of comparisons required to partition an array of size n.
The last element is chosen as the pivot in this implementation. So, on average, half of the elements are smaller than the pivot and half are larger.
Therefore, the average number of comparisons for partitioning an array of size n is:

                     n
  
T(n) = n – 1 + (1/n) ∑ (T(i-1) + T(n-i))

                    i=1
  
n−1 represents the number of comparisons for partitioning the array.
- The summation term represents the average number of comparisons for partitioning the left and right subarrays.

 -- Overall Complexity:
 

- The average-case time complexity of the non-random pivot QuickSort is approximately O(nlogn).
- This complexity arises from the balanced partitioning of the array, which typically occurs in practice despite the deterministic pivot selection.


