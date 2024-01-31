
Question 2: Argue Correctness of Selection Sort:

Selection sort is a simple sorting algorithm that works by repeatedly selecting the minimum element from the unsorted part of the array and placing it at the beginningof the array.

Initialization:


At the start, the sorted array is empty, and the unsorted array contains all the elements. The algorithm finds the smallest element in the unsorted subarray and places it at the end of the sorted subarray.

Maintenance:


At the end of each iteration, the smallest element in the unsorted subarray is selected and moved to the sorted subarray. This maintains the invariant that the elements in the sorted subarray are in their final sorted order.
   
Termination: 


The algorithm terminates when the entire array is sorted. In each iteration, the size of the unsorted subarray is reduced by one, and the sorted subarray grows. Eventually, the entire array becomes sorted.
   
Time Complexity: 


The time complexity of selection sort is O(n^2), where n is the number of elements in the array. Although not the most efficient sorting algorithm, it is simple and performs well for small datasets.


