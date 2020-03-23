#include <iostream>
#include <cstdlib>
#include <assert.h>
using namespace std;

#define MAX_SIZE 20
#define MIN_SIZE 10
#define MAX_INT 100

int swaps = 0;
int comparisons = 0;


//Bubble Sort Algorithm
void bubble_sort(int * &array, int size){
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
    if (flag == 0)    //Pass with no swaps, end loop
      return;
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
  bubble_sort(array, size);

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
