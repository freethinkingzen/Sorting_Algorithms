***This program is original code by John Lewis 3/22/2020***

This program is an implementation of a simple heapsort in C.

Heapsort:
  Comparison based sorting algorithm that divides its input
  into a sorted and an unsorted region, and iteratively 
  shrinks the unsorted region by extracting the largest 
  element and inserting it into the sorted region. The 
  unsorted region is maintained as a heap so that the
  largest item always remains on top of the heap.

  Worst Case Performance = O(nlog_2(n))
  Best Case Performance = O(nlog_2(n))
  Average Performance = O(nlog_2(n))

Heapsort Algorithm:
  1) Build a heap structure from the input
  2) Swap the first and last element
  3) Swap the new root down to the appropriate position in
     the heap.
  4) Repeat 2 and 3 until sorted.

Example:

  Input: 5 1 4 2 3 6 0
  
  Original Input
       5             
     /   \
    1     4
   / \   / \
  2   3 6   0

  Create max heap from input
  Start at height - 1 and compare children, swap largest child

       5             5
     /   \         /   \
    1     4 <-    1     6
   / \   / \     / \   / \
  2   3 6   0   2   3 4   0
        ^

       5             5
     /   \         /   \
 -> 1     6       3     6
   / \   / \     / \   / \
  2   3 4   0   2   1 4   0
      ^
      
    -> 5             6
     /   \         /   \
    3     6 <-    3     5
   / \   / \     / \   / \
  2   1 4   0   2   1 4   0

  New Unsorted: 6 3 5 2 1 4 0

  Swap first and last of unsorted data

       6 <-          0
     /   \         /   \
    3     5       3     5
   / \   / \     / \   / \
  2   1 4   0   2   1 4   6
            ^
  New sorted: 6

  Swap down to correct index in heap

       0 <-          5
     /   \         /   \
    3     5 <-    3     0
   / \   /       / \   / 
  2   1 4       2   1 4   
             

       5             5 
     /   \         /   \
    3     0 <-    3     4
   / \   /       / \   / 
  2   1 4       2   1 0   
        ^
            
  New Unsorted: 5 3 4 2 1 0

  Swap first and last of unsorted data

       5 <-          0
     /   \         /   \
    3     4       3     4
   / \   /       / \   / 
  2   1 0       2   1 5   
        ^   
  New Sorted: 5 6

  Swap down to correct index in heap

       0 <-          4
     /   \         /   \
    3     4 <-    3     0
   / \           / \   
  2   1         2   1    
          

  New Unsorted: 4 3 0 2 1

  Swap first and last of unsorted data

       4 <-          1
     /   \         /   \
    3     0       3     0
   / \           / \   
  2   1         2   4  
      ^
  New Sorted: 4 5 6

  Swap down to correct index in heap
       1 <-          3
     /   \         /   \
 -> 3     0       1     0
   /             /    
  2             2   
       
       3             3
     /   \         /   \
 -> 1     0       2     0
   /             /    
  2             1   
  ^

  New Unsorted: 3 2 0 1

  Swap first and last of unsorted data

       3 <-          1
     /   \         /   \
    2     0       2     0
   /             /    
  1             3   
  ^
  New Sorted: 3 4 5 6

  Swap down to correct index in heap

       1 <-          2
     /   \         /   \
    2     0       1     0
    ^
  
  New Unsorted: 2 1 0

  Swap first and last of unsorted data

       2 <-          0
     /   \         /   \
    1     0       1     2
          ^
  New Sorted: 2 3 4 5 6

  Swap down to correct index in heap

       0 <-          1
      /             /
     1             0
     ^
  New Unsorted: 1 0

  Swap first and last of unsorted data

      1 <-           0
     /              /
    0              1
    ^
  New Sorted: 1 2 3 4 5 6
  New Unsorted: 0
  New Sorted: 0 1 2 3 4 5 6
