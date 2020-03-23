*** This program is original code by John Lewis 3/17/2020 ***

This program is an implimentation of a simple quicksort
algorithm in C++.



Quicksort:  a divide-and-conquer algorithm. It works by selecting a 'pivot'
            element from the array and partitioning the other elements into two
            sub-arrays, according to whether they are less than or greater than
            the pivot. The sub-arrays are then sorted recursively. This can be
            done in-place, requiring small additional amounts of memory to 
            perform the sorting.
                                    -Wikipedia

    Worst Case Performance: O(n^2)

    Best Case Performance:  O(nlog_2n)

    Average Performance:  = O(nlog_2(n))



Quisksort Algorithm:

  1)  Pick the pivot value.
  2)  Move all values less than the pivot to the left and all values greater than
      the pivot to the right. Pivot is now in it's final position.
  3)  Recursively repeat on each side of the pivot.
    


Example:
  v                  
  5 9 2 8 3 7 4 0 5 6
+                     *
  v                   
  5 9 2 8 3 7 4 0 1 6
  +                   *
  v
  5 9 2 8 3 7 4 0 1 6
    +                 *
  v
  5 9 2 8 3 7 4 0 1 6
    +               *
  v
  5 9 2 8 3 7 4 0 1 6
    +             *  
  v
  5 1 2 8 3 7 4 0 9 6
    +             *  
  v
  5 1 2 8 3 7 4 0 9 6
      +           *
  v
  5 1 2 8 3 7 4 0 9 6
        +         *  
  v
  5 1 2 8 3 7 4 0 9 6
        +       *    
  v
  5 1 2 0 3 7 4 8 9 6
        +       *    
  v
  5 1 2 0 3 7 4 8 9 6
          +     *   
  v
  5 1 2 0 3 7 4 8 9 6
            +   *    
  v
  5 1 2 0 3 7 4 8 9 6
            + *
  v          
  5 1 2 0 3 4 7 8 9 6
            + *   
  v
  5 1 2 0 3 4 7 8 9 6
              *
  v           +
  5 1 2 0 3 4 7 8 9 6
            * +
            v
  4 1 2 0 3 5 7 8 9 6

  Everything less than pivot is left, everything greater than pivot is right.
