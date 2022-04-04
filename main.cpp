//Nihal Parthasrathy
//4/3/2022
//This program makes a max heap where you can add, remove, and display the heap
//Help from kushal for file add

//inclusions
#include <iostream>
#include <cstring>
#include <math.h>
#include <fstream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

using namespace std;

//Function Prototypes
void manuallyAdd(int* array, int &curr);
void heap(int* array, int &curr);
void print(int* array);
void addFile(int* array, int &curr);
void display(int index, int* array, int depth, int size);
void remove(int* array, int size);
void rearange(int* array, int index);

int main() {
  srand(time(0));
  
  cout << "Welcome to heap" << endl;
  
  int *array = new int[100];
  int curr = 0;
  
  for (int i = 0; i < 100; i++) {
    array[i] = 0;
  }
  bool playing = true;
  while (playing == true) {//While loop
    cout << "would you like to add from a file(ADD), Manualy add(TYPE), print(PRINT), display(DISPLAY), remove from heap(REMOVE), or quit(QUIT)" << endl;
    char input[10];
    cin >> input;
    if (strcmp(input, "ADD") == 0) {//Calls the add function
      addFile(array, curr);
    }
    else if (strcmp(input, "TYPE") == 0) {//Calls type function
      manuallyAdd(array, curr);
    }
    else if (strcmp(input, "DISPLAY") == 0) {//Calls display function
      display(0, array, 0, curr);
    }
    else if (strcmp(input, "PRINT") == 0) {//Calls the print function
      print(array);
    }
    else if (strcmp(input, "REMOVE") == 0) {//Calls remove function
      remove(array, curr);
      curr = 0;
    }
    else if (strcmp(input, "QUIT") == 0) {//Returns false
      playing = false;//Exits while Loop stopping game
    }
  }
  return 0;
}

void addFile(int* array, int &curr) {//Adds from a file
  cout << "how many numbers to add" << endl;
  int input;
  cin >> input;
  
  for (int i = 0; i < input; i++) {
    char input[10];
    char tempString[10];
    int count = 1;
    int numput;
    int randomnum = (rand() % 50) + 1;
    fstream myfile("numberFile.txt");//Opens file
       
    while (myfile.getline(input,10, ' ')) {
      if (count == randomnum) {
	strcpy(tempString, input);
	count++;
      }
      count++;
    }
    numput = atoi(tempString);//Changes from string to int
    array[curr] = numput;
    heap(array, curr);
    curr++;
  }
}

void manuallyAdd(int* array, int &curr) {//Manualy adds number to the heap
  int num;
  cout << "what number would you like add" << endl;
  cin >> num;
  
  if (array[0] == 0) {//If the heap is blank
    array[0] = num;
    curr = 1;
  }
  else {//Adds the number to the heap
    array[curr] = num;
    heap(array, curr);//Calls the check function
    curr++;
  }

}

void display(int index, int* array, int depth, int size) {//Displays the heap using tabs
  if (index*2 + 2 <= size && array[index*2 + 2] != 0) {
    display(index*2 + 2, array, depth + 1, size);//Recurcive call
  }
  for (int i = 0; i < depth; i++) {//Prints out the amount of tabs based on the depth
    cout << "\t";
  }
  cout << array[index] << endl;//Prints out the number
  if (index*2 + 1 <= size && array[index*2 + 1] != 0) {
    display(index*2 + 1, array, depth + 1, size);//Recurcive call
  }
}

void print(int* array) {//Print function for debugging
  for (int i = 0; i < 100; i ++) {
    cout << array[i] << endl;
  }
}

void remove(int* array, int size) {//Prints out numbers greatest to lowest and removes all of the from the heap
  while (size != 0) {
    cout << array[0] << ", ";//Prints out the number
    array[0] = array[size-1];
    array[size-1] = 0;
    rearange(array, 0);//Calls the rearange function
    size--;
  }
  cout << endl;
}

void rearange(int* array, int index) {//Rearanges the heap so its a proper max heap
  if (array[(index*2)+1] >= array[(index*2)+2] && array[index] < array[(index*2)+1]) {//If the left child is bigger than the right and its value is bigger than its parents
    int temp = array[(index*2)+1];
    array[(index*2)+1] = array[index];//Switches them
    array[index] = temp;
    rearange(array, (index*2)+1);
  }
  else if (array[(index*2)+1] <= array[(index*2)+2] && array[index] < array[(index*2)+2]) {//If the right child is bigger than the left and its value is bigger than its parents
   int temp = array[(index*2)+2];
   array[(index*2)+2] = array[index];//Switches them
   array[index] = temp;
   rearange(array, (index*2)+2);
 }
}

void heap(int* array, int &curr) {//Rearanges the heap so its propper
  if (array[curr] > array[(int) floor((curr-1)/2)]) {//If the childs value is bigger than its parents
    //Switches child and parent
    int temp = array[curr];
    array[curr] = array[(int) floor((curr-1)/2)];
    array[(int) floor((curr-1)/2)] = temp;
    int newcurr = (int) floor((curr-1)/2);
    
    heap(array, newcurr);
  }
}
