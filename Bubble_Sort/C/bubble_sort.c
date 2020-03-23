#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 20
#define MIN_SIZE 10
#define MAX_INT 100

int swaps = 0;
int comparisons = 0;

//Bubble Sort algorithm
int * bubble_sort(int * array, int size){
  for(int i = 0; i < (size - 1); ++i){    //Passes through array
    int flag = 0;
    for(int j = 0; j < (size-i-1); ++j){  //Adjacent comparisons

      ++comparisons;  //For efficiency analysis

      //If i > i+1, swap elements
      if(array[j] > array[j+1]){
        int temp = array[j];
        array[j] = array[j+1];
        array[j+1] = temp;
        flag = 1;

        ++swaps;  //For efficiency analysis
      }
    }
    if(flag == 0)
     return array;
  }
  return array;
}

void print(int *array, int size){
  for(int i = 0; i < size; ++i)
    printf("%d ", array[i]);
  printf("\n");
}

int * build_array(int * size) {

  //Initialize (seed) random number generator
  srand(time(0));

  //Random size between MAX_SIZE and MIN_SIZE
  *size = (rand() % (MAX_SIZE - MIN_SIZE + 1)) + MIN_SIZE;

  //Malloc() array using size
  int *array = malloc(*size * sizeof(int));

  //Fill array with randomized numbers
  for (int i = 0; i < *size; ++i)
    array[i] = rand() % (MAX_INT + 1);

  return array;
}


int main(void){
  int * array_ptr = NULL;
  int size= 0;

  array_ptr = build_array(&size);

  printf("\nARRAY BEFORE SORTING: ");
  print(array_ptr, size);

  array_ptr = bubble_sort(array_ptr, size);

  printf("\nARRAY AFTER SORTING: ");
  print(array_ptr, size);

  //Efficiency Analysis
  printf("\nSWAPS: %d\n", swaps);
  printf("\nCOMPARISONS: %d\n", comparisons);

  free(array_ptr);

  return 0;
}
