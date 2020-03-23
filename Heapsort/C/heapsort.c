#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 20
#define MIN_SIZE 10
#define MAX_INT 100

int swaps = 0;
int comparisons = 0;

//Swap array elements
void swap(int *elem1, int *elem2){
  int temp = *elem1;
  *elem1 = *elem2;
  *elem2 = temp;
}

//Create a max heap from an array
int * heapify(int * array, int size, int i){
  int largest = i;      
  int left = 2 * i + 1; 
  int right = 2 * i + 2;

  //Compare to left child
  ++comparisons;    //For efficiency analysis
  if(array[largest] < array[left] && left < size)
    largest = left;

  //Compare to right child
  ++comparisons;    //For efficiency analysis
  if(array[largest] < array[right] && right < size)
    largest = right;

  //If a child was largest, swap and recursive call
  if(largest != i){
    swap(&array[i], &array[largest]);
    ++swaps;        //For efficiency analysis
    heapify(array, size, largest);
  }
  return array;
}

//Heapsort
int * heapsort(int * array, int size){
  //Make array into max heap
  for(int i = size/2-1; i >= 0; --i)
    array = heapify(array, size, i); 

  for(int i = size-1; i > 0; --i){
    //swap root and last
    swap(&array[0], &array[i]);
    ++swaps;      //For efficiency analysis
    
    //Make array into max heap
    array = heapify(array, i, 0);
  }
  return array;
}


//Print an array
void print(int * array, int size){
  int counter = 0;
  for(int i = 0; i < size; ++i){
    //Array view
   // printf("%d ", array[i]);

    //Heap/Tree view
    if(i - 2 * (counter + 1) == 0 || i == 0){
      printf("%d\n\n", array[i]);
      counter = i;
    }
    else
      printf("%d ", array[i]);
  }

  printf("\n");
}

//Build a random size array of random integers
int * build_array(int * size) {

  //Initialize (seed) random number generator
  srand(time(0));

  //Random size between MAX_SIZE and MIN_SIZE
  *size = (rand() % (MAX_SIZE - MIN_SIZE + 1)) + MIN_SIZE;

  //Malloc() array using size
  int * array = calloc(*size, sizeof(int));

  
  //Fill array with randomized numbers
  for(int i = 0; i < *size; ++i){
      array[i] = rand() % (MAX_INT + 1);
  }

  return array;
}


int main(void){
  int * array_ptr = NULL;
  int size= 0;

  array_ptr = build_array(&size);

  printf("\nARRAY BEFORE SORTING: \n");
  print(array_ptr, size);

  array_ptr = heapsort(array_ptr, size);

  printf("\nARRAY AFTER SORTING: \n");
  print(array_ptr, size);

  //Efficiency Analysis
  printf("\nSWAPS: %d\n", swaps);
  printf("\nCOMPARISONS: %d\n", comparisons);

  free(array_ptr);

  return 0;
}
