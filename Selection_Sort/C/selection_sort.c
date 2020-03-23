#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 20
#define MIN_SIZE 10
#define MAX_INT 100

int swaps = 0;
int comparisons = 0;

//Selection Sort
int * selection_sort(int * array, int size){
  for(int i = 0; i < (size - 1); ++i){  //Steps through each element

    int min_index = i;  //Index with lowest value

    for(int j = i; j < size; ++j){  //Comparisons through array
      ++comparisons;  //For efficiency analysis

      //If lowest, save index
      if(array[j] < array[min_index])
        min_index = j;
    }

    //Swap lowest found into i index
    int temp = array[i];
    array[i] = array[min_index];
    array[min_index] = temp;
    ++swaps;
  } 
  return array;
}


//This function takes a NULL int pointer and creates an
//array with MAX_SIZE to MIN_SIZE elements then initializes it with
//random numbers between 0-MAX_INT and returns the pointer.
int * build_array(int * size){

  //Initialize (seed) random number generator
  srand(time(0));

  //Random int between MAX_SIZE and MIN_SIZE for array.
  *size = (rand() % (MAX_SIZE - MIN_SIZE + 1)) + MIN_SIZE;

  //Dynamically allocate array using "size"
  int *array = malloc(*size * sizeof(int));

  //Fill array with random numbers
  for (int i = 0; i < *size; ++i)
    array[i] = rand() % (MAX_INT+1);

  return array;
}

void print(int *array, int size){
  for(int i = 0; i < size; ++i)
    printf("%d ", array[i]);
  printf("\n");
}

int main(){

  //Create a NULL array pointer for build_array()
  int * array_ptr = NULL;

  //int to store array length
  int size = 0;

  //Takes a NULL pointer and builds an array of
  //random numbers
  array_ptr = build_array(&size);

  //Prints array before sorting
  printf("\nARRAY BEFORE SORTING: ");
  print(array_ptr, size);

  //Selection Sort
  array_ptr = selection_sort(array_ptr, size);

  //Print array after sorting
  printf("\nARRAY AFTER SORTING: ");
  print(array_ptr, size);
  printf("\n");

  //Efficiency Analysis
  printf("\nSWAPS: %d\n",swaps);
  printf("\nCOMPARISONS: %d\n", comparisons);

  //Free dynamic array memory
  free(array_ptr);

  return 0;
}
