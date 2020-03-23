#include <iostream>
#include <cstdlib>
#include <ctime>
#include <assert.h>
using namespace std;

#define MAX_SIZE 20
#define MIN_SIZE 10
#define MAX_INT 100

int swaps = 0;
int comparisons = 0;

//Insertion Sort Algorithm
void insertion_sort(int * &array, int size){

  //Increments the index of already sorted ints
  //start at index 1 because nothing happens at 0
  for(int i=1; i<size; ++i){

    //Compare each element to find lowest int
    for(int j=i; j>0; --j){
      
      ++comparisons;

      //If index to left is greater, swap
      if(array[j] < array[j-1]){

        int temp = array[j];
        array[j] = array[j-1];
        array[j-1] = temp;
        ++swaps;
      }
    }
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
  for (int i=0; i<size; ++i){
    array[i] = rand() % (MAX_INT+1);
  }

  return array;
}

//This function takes a dynamically allocated array and
//prints until reaching the null terminating character.
void print(int * array, int size) {
  assert(array);

  for (int i=0; i<size; ++i)
    cout << array[i] << " ";
  cout << endl;
}

int main(){

  //Create a NULL array pointer for build_array()
  int * array_ptr = NULL;

  //int to store array length
  int size = 0;

  //Build random int array
  array_ptr = build_array(array_ptr, size);

  //Prints array before sorting
  cout << "\nARRAY BEFORE SORTING: ";
  print(array_ptr, size);
  cout << endl;

  //Insertion Sort
  insertion_sort(array_ptr, size);

  //Print array after sorting
  cout << "\nARRAY AFTER SORTING: ";
  print(array_ptr, size);
  cout << endl;

  //Efficiency Analysis
  cout << "\nSWAPS: " << swaps << endl;
  cout << "\nCOMPARISONS: " << comparisons << endl;

  return 0;
}
