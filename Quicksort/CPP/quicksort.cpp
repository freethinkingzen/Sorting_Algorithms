#include <iostream>
#include <cstdlib>
#include <assert.h>
using namespace std;

#define MAX_SIZE 20
#define MIN_SIZE 10
#define MAX_INT 100

int swaps = 0;
int comparisons = 0;

void quicksort(int *&array, int low, int high){
  if(low < high){
    //Hoare Partition
    int pivot = array[low];
    
    int l = low - 1;
    int r = high + 1;

    for(;;){
      do{
        ++l;
        ++comparisons;
      }while(array[l] < pivot);

      do{
        --r;
        ++comparisons;
      }while(array[r] > pivot);

      if(l >= r)
        break;

      int temp = array[l];
      array[l] = array[r];
      array[r] = temp;
      ++swaps;
    }

    quicksort(array, low, r);
    quicksort(array, r+1, high);
  }
}

//This function takes a NULL int pointer and creates an
//array with MAX_SIZE to MIN_SIZE elements then initializes it with
//random numbers between 0-MAX_INT and returns the pointer.
int * build_array(int * array, int & size){

  //Check that a null pointer was passed
  assert(array == NULL);

  //Initialize (seed) random number generator
  srand(time(0));

  //Random int between MAX_SIZE and MIN_SIZE for array.
  size = (rand() % (MAX_SIZE - MIN_SIZE + 1)) + MIN_SIZE;

  //Dynamically allocate array using "size"
  array = new int[size];

  //Fill array with random numbers
  for (int i = 0; i < size; ++i){
    array[i] = rand() % (MAX_INT+1);
  }

  return array;
}

//This function takes a dynamically allocated array and
//prints until reaching the null terminating character.
void print(int * array, int size) {
  assert(array);

  for (int i = 0; i < size; ++i)
    cout << array[i] << " ";
  cout << endl;
}

int main(){

  //Create null int pointer for build_array() and
  int * array = NULL;

  //an int to store the length
  int size = 0;

  //Takes a null int pointer and creates array
  //of random numbers;
  array = build_array(array, size);

  //Prints array before sorting
  cout << "\nARRAY BEFORE SORTING: ";
  print(array, size);
  cout << endl;

  //Bubble Sort
  quicksort(array, 0, size-1);

  //Prints array after sorting
  cout << "\nARRAY AFTER SORTING: ";
  print(array, size);
  cout << endl;

  //Efficiency Analysis
  cout << "\nSWAPS: " << swaps << endl;
  cout << "\nCOMPARISONS: " << comparisons << endl;

  //Free dynamic array memory
  delete [] array;
    
  return 0;
}
