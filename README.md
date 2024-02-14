**Problem 1:**
Prove the time complexity of the algorithms

The time complexity of the provided algorithm for merging K sorted arrays of size N each can be analyzed as follows:

Merging Two Sorted Arrays (merge function):

The merge function iterates through both input arrays once, comparing elements and merging them into a new array.
Let's denote the lengths of the two input arrays as n1 and n2.
​
Since both arrays are iterated over once, the time complexity of the merge function is O(n1 + n2).
Inside this loop, we repeatedly find the minimum element among the current elements of all arrays. This operation involves 
iterating over the array of indexes (which has a constant size c) and finding the minimum value among c elements, which can be done in O(c) time.

Since there are c×n elements in the merged array, and for each element, we perform an operation with a time complexity of 
O(c), the overall time complexity of the mergeKArrays function is O(c^2 × n).


