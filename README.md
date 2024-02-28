**3. Mathematically derive the average runtime complexity of the non-random pivot version of quicksort.**

Code Snippet:
<img width="301" alt="image" src="https://github.com/gayathri-leburu/CSE5311/assets/156869407/3bd977f8-7bdd-440f-a191-08f2ed03f030">

-- Partitioning Time :

- Each partitioning operation takes O(n) time, where n is the size of the subarray being partitioned.
- This is because in the worst case, we might need to compare each element with the pivot.

-- Average Number of Comparisons :

- Let T(n) be the average number of comparisons required to partition an array of size n.
The last element is chosen as the pivot in this implementation. So, on average, half of the elements are smaller than the pivot and half are larger.
Therefore, the average number of comparisons for partitioning an array of size n is:
<img width="229" alt="image" src="https://github.com/gayathri-leburu/CSE5311/assets/156869407/97a6d343-cc8c-4da8-82be-2a9281a444aa">
  
n−1 represents the number of comparisons for partitioning the array.
- The summation term represents the average number of comparisons for partitioning the left and right subarrays.

 -- Overall Complexity:
 

- The average-case time complexity of the non-random pivot QuickSort is approximately O(nlogn).
- This complexity arises from the balanced partitioning of the array, which typically occurs in practice despite the deterministic pivot selection.


