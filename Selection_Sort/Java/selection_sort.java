import java.util.*;

public class selection_sort{

  private final int MAX_SIZE = 20;
  private final int MIN_SIZE = 10;
  private final int MAX_INT = 100;

  private int swaps = 0;
  private int comparisons = 0;

  //Builds a random length array with random integers
  private int [] build_array(){
    //Random class to create random ints
    Random rand = new Random();

    //Random size for array
    int size = rand.nextInt(MAX_SIZE - MIN_SIZE) + MIN_SIZE;

    //Allocate array
    int [] array = new int[size];
 
    //Set array elements to random integers
    for(int i = 0; i < size; ++i)
      array[i] = rand.nextInt(MAX_INT);

    return array;
  }
  
  //Print elements of an array
  private void print(int [] array){
    for(int i = 0; i < array.length; ++ i)
      System.out.print(array[i] + " ");
    System.out.println();
  }

  //Selection Sort Algorithm
  private int [] selection_sort(int [] array){
    for(int i = 0; i < (array.length - 1); ++i){      //Element to set

      int min_index = i;  //Index with lowest value

      for(int j = i; j < array.length; ++j){//Loop through array
        ++comparisons;  //For Efficiency analysis

        if(array[j] < array[min_index])
          min_index = j;
      }

      //Swap lowest into i index
      int temp = array[i];
      array[i] = array[min_index];
      array[min_index] = temp;
      ++swaps;
    }
    return array;
  }

  public static void main(String[] args){
    selection_sort demo = new selection_sort();

    //Build array to sort
    int array[] = demo.build_array();

    System.out.println("\nARRAY BEFORE SORTING:");
    demo.print(array);

    //Selection Sort
    demo.selection_sort(array);

    System.out.println("\nARRAY AFTER SORTING:");
    demo.print(array);

    //Efficiency Analysis
    System.out.println("SWAPS: " + demo.swaps);
    System.out.println("COMPARISONS: " + demo.comparisons);

  }
}
