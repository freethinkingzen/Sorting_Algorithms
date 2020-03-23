*** This program is original code by John Lewis 3/16/2020 ***

This program is an implimentation of a simple selection sort
algorithm in Java.



Selection Sort:	a sorting algorithm that divides the input
		list into two parts: the sublist of items
		already sorted, which is built up from left
		to right at the front (left) of the list,
		and the sublist of items remaining to be
		sorted that occupy the rest of the list. 
		Initially, the sorted sublist is empty and
		the unsorted sublist is the entire input 
		list. The algorithm proceeds by finding the
		smallest (or largest, depending on sorting 
		order) element in the unsorted sublist, 
		exchanging (swapping) it with the leftmost 
		unsorted element (putting it in sorted 
		order), and moving the sublist boundaries 
		one element to the right.

		Worst Case Performance: O(n^2) Comparisons
					O(n) Swaps

		Best Case Performance:	O(n^2)
					O(n) Swaps

		Average Performance:	= Best Case = Worst Case



Selection Sort Algorithm:

	1) Find the minimum value in the entire array
	2) Move minimum value to 0th index
	3) Find minimum value in [1 thru nth] index
	4) Move minimum value to 1st index
	5) Find minimum value in [2 thru nth] index
	6) Move minimum value to 2nd index
	...
	7) Continue until array is sorted (n moves)


Example:

	Sorted List	Unsorted List	Smallest Element
	()		(5, 1, 4, 2, 3) 1
	(1)		(5, 4, 2, 3)	2
	(1, 2)		(5, 4, 3)	3
	(1, 2, 3)	(5, 4)		4
	(1, 2, 3, 4)	(5)		5
	(1, 2, 3, 4, 5) ()		none


