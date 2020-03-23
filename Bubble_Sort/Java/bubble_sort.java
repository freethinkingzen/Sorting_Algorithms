import java.util.*;

public class bubble_sort{

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

  //Bubble Sort Algorithm
  private int [] bubble_sort(int [] array){
    for(int i = 0; i < (array.length - 1); ++i){
      int flag = 0;
      for(int j = 0; j < (array.length - 1); ++j){
        ++comparisons;
        if(array[j] > array[j+1]){
          int temp = array[j];
          array[j] = array[j+1];
          array[j+1] = temp;
          ++swaps;
          flag = 1;
        }
      }
      if(flag == 0)
        return array;
    }
    return array;
  }

  public static void main(String[] args){
    bubble_sort demo = new bubble_sort();

    //Build array to sort
    int array[] = demo.build_array();

    System.out.println("\nARRAY BEFORE SORTING:");
    demo.print(array);

    //Bubble Sort
    demo.bubble_sort(array);

    System.out.println("\nARRAY AFTER SORTING:");
    demo.print(array);

    //Efficiency Analysis
    System.out.println("SWAPS: " + demo.swaps);
    System.out.println("COMPARISONS: " + demo.comparisons);

  }
}
