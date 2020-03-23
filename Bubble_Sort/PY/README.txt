***This program is original code by John Lewis 7/3/2019***

This program is an implementation of a simple bubble sort
in Python.


Bubble Sort: 	an algorithm that repeatedly steps through a
		list, compares adjacent pairs, and swaps
		them if they are in the wrong order for the
		desired high->low or low->high organization

		Worst Case Performance	=	O(n^2) Comparisons
						O(n^2) Swaps
		Best Case Performance	=	O(n) Comparisons
						O(1) Swaps
		Average Performance 	=	Worst Case Performance

Bubble Sort Algorithm:

	Compare ith and (i+1)th element
	
	If i > i+1
		swap i and i+1;

	Largest item is now at the end;

	Increment i and pass through again.

	Continue until no swaps are made through an entire pass.

Example:

	1st Pass:			2nd Pass:			3rd Pass:

		5 1 4 2 3			1 4 2 3 5			1 2 3 4 5
		5>1, swap			1<4, no swap			1<2, no swap

		1 5 4 2 3			1 4 2 3 5			1 2 3 4 5	
		5>4, swap			4>2, swap			2<3, no swap

		1 4 5 2 3			1 2 4 3 5			1 2 3 4 5
		5>2, swap			4>3, swap			3<4, no swap

		1 4 2 5 3			1 2 3 4 5			1 2 3 4 5
		5>3, swap			4<5, no swap			4<5, no swap

		1 4 2 3 5			1 2 3 4 5			1 2 3 4 5
		no more comparisons		no more comparisons		no more comparisons



	

	

	
	
