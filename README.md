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

************************************************************************************************************************

**Problem 2:**

The algorithm iterates through the array once from the beginning to the second-to-last element. This is a linear time operation and takes O(n) time, where n is the number of elements in the array.

Inside the loop, it checks if the current element is different from the next element. This operation takes constant time and doesn't affect the overall time complexity.

If the current element is different from the next one, it copies the current element to the output array. This operation also takes constant time.

Finally, it copies the last element to the output array.

Overall, the algorithm performs a single pass through the input array, performing constant time operations at each step. Therefore, the time complexity of the algorithm is O(n), where n is the number of elements in the input array.

