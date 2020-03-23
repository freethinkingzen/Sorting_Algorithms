#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 20
#define MIN_SIZE 10
#define MAX_INT 100

//Preprocssor to switch between Lomuto and Hoare Algs
//#define HOARE
//#define LOMUTO
#define BOTH

int swaps = 0;
int comparisons = 0;

//Hoare Method Quicksort Algorithm
int * Hquicksort(int * array, int low, int high){
  if(low < high){
    int pivot = array[low];  

    int l = low - 1;
    int r = high + 1;

    int loops = 0;   //For efficiency analysis only
    for(;;){
      do{
        ++l;
        ++comparisons;  //For efficiency analysis only
      }while(array[l] < pivot);

      do{
        --r;
        ++comparisons;  //For efficiency analysis only
      }while(array[r] > pivot);

      if(l >= r)
        break;

      int temp = array[l];
      array[l] = array[r];
      array[r] = temp;
      ++swaps;          //For efficiency analysis only
      ++loops;          //For efficiency analysis only
    }
    comparisons -= 2 * loops; //Remove extra comparisons from do:whiles

    Hquicksort(array, low, r);
    Hquicksort(array, r+1, high);
  }
  return array;
}

//Lomuto Method Quicksort Algorithm
int * Lquicksort(int * array, int low, int high){
  if(low < high){
    int pivot = array[high];
    int index = low;

    for(int i = low; i <= high; ++i){
      ++comparisons;    //For efficiency analysis only
      if(array[i] < pivot){
        //Swap
        int temp = array[index];
        array[index] = array[i];
        array[i] = temp;
        ++index;
        ++swaps;        //For efficiency analysis only
      }
    }
    //Swap
    int temp = array[index];
    array[index] = array[high];
    array[high] = temp;
    ++swaps;            //For efficiency analysis only

    Lquicksort(array, low, index-1);
    Lquicksort(array, index+1, high);
  }
  return array;
}

//Prints array of integers
void print(int *array, int size){
  for(int i = 0; i < size; ++i)
    printf("%d ", array[i]);
  printf("\n");
}

//Builds array of random length and integers
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

//Copy an array of ints and return new array
int * copy(int * array, int size){
  int * a_copy = malloc(size * sizeof(int));

  for(int i = 0; i < size; ++i)
    a_copy[i] = array[i];
  
  return a_copy;
}

int main(void){
  int * array_ptr = NULL;
  int size= 0;

  array_ptr = build_array(&size);

  printf("\nARRAY BEFORE SORTING: ");
  print(array_ptr, size);

#ifdef HOARE
  array_ptr = Hquicksort(array_ptr, 0, size-1);
#elif LOMUTO
  array_ptr = Lquicksort(array_ptr, 0, size-1);
#endif
#ifdef BOTH
  int * array_ptr2 = copy(array_ptr, size);
  array_ptr2 = Hquicksort(array_ptr2, 0, size-1);

  printf("\nHOARE ALGORITHM");
  printf("\nARRAY AFTER SORTING: ");
  print(array_ptr2, size);

  printf("\nSWAPS: %d\n", swaps);
  printf("\nCOMPARISONS: %d\n\n", comparisons);

  swaps = 0;
  comparisons = 0;
  array_ptr = Lquicksort(array_ptr, 0, size-1);
  printf("LOMUTO ALGORITHM");
#endif
  printf("\nARRAY AFTER SORTING: ");
  print(array_ptr, size);

  //Efficiency Analysis
  printf("\nSWAPS: %d\n", swaps);
  printf("\nCOMPARISONS: %d\n", comparisons);

  free(array_ptr);
#ifdef BOTH
  free(array_ptr2);
#endif

  return 0;
}
