#include <iostream>
#include <cstdlib>
#include <assert.h>
using namespace std;

#define MAX_SIZE 20
#define MIN_SIZE 10
#define MAX_INT 100

int swaps = 0;
int comparisons = 0;

//Selection Sort
void selection_sort(int * &array, int size){
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
  for (int i = 0; i < size; ++i)
    array[i] = rand() % (MAX_INT+1);
  

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

  //Create a NULL array pointer for build_array()
  int * array = NULL;

  //int to store array length
  int size = 0;

  //Takes a NULL pointer and builds an array of
  //random numbers
  array = build_array(array, size);

  //Prints array before sorting
  cout << "\nARRAY BEFORE SORTING: ";
  print(array, size);
  cout << endl;

  //Selection Sort
  selection_sort(array, size);

  //Print array after sorting
  cout << "\nARRAY AFTER SORTING: ";
  print(array, size);
  cout << endl;

  //Efficiency Analysis
  cout << "SWAPS: " << swaps << endl;
  cout << "COMPARISONS: " << comparisons << endl;

  //Free dynamic array memory
  delete [] array;

  return 0;
}
