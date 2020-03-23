*** This program is original code by John Lewis 6/11/2019 ***

This program is an implimentation of a simple insertion sort
algorithm in C++.



Insertion Sort:	an iterative sorting algorithm that removes
		one element from an input array/list, finds
		the location where it belongs in the sorted
		output array/list, and inserts it there. 
		This repeats until the list is sorted.

		Worst Case Performance: O(n^2) Comparisons
					O(n^2) Swaps

		Best Case Performance:	O(n) Comparisons
					O(1) Swaps

		Average Performance:	= Worst Case



Insertion Sort Algorithm:

	1) Pick nth index value
	2) Compare to the left until:
		a) if n-k value is less than n value
			swap
		b) no index to the left
	3) Go to n+1 index and repeat 
		
		
		



Example:

	Input Array: [5, 1, 3, 4, 2]

	Sorted | Unsorted

	1st Pass:	Pick array[0]
			Nothing to left			[(5),1,3,4,2]
			insert
		  	[5] | [1,3,4,2]
		  

	2nd Pass: 	Pick array[1]
		  	Compare left, 1 < 5		[(5,1),3,4,2]
			compare left, nothing to left	[(1),5,3,4,2]
			insert
		  	[1,5] | [3,4,2]

	3rd Pass: 	Pick array[2]
			Compare left, 3 < 5		[1,(5,3),4,2]
			Compare left, 3 > 1		[(1,3),5,4,2]
			insert
			[1,3,5] | [4,2]

	4th Pass: 	Pick array[3]
			Compare left, 4 < 5		[1,3,(5,4),2]
			Compare left, 4 > 3		[1,(3,4),5,2]
			insert
			[1,3,4,5] | [2]

	5th Pass: 	Pick array[4]
			Compare left, 2 < 5		[1,3,4,(5,2)]
			Compare left, 2 < 4		[1,3,(4,2),5]
			Compare left, 2 < 3		[1,(3,2),4,5]
			Compare left, 2 > 1		[(1,2),3,4,5]
			insert
			[1,2,3,4,5] | []
	
