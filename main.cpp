#include <iostream>
#include <cstring>
#include <math.h>
#include <fstream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

using namespace std;

void manuallyAdd(int* array, int &curr);
void heap(int* array, int &curr);
void print(int* array);
void addFile(int* array, int &curr);

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
    cout << "would you like to add from a file(ADD), Manualy add(TYPE), print(PRINT), display(DISPLAY), or quit(QUIT)" << endl;
    char input[10];
    cin >> input;
    if (strcmp(input, "ADD") == 0) {//Calls the add function
      addFile(array, curr);
    }
    else if (strcmp(input, "TYPE") == 0) {//Calls type function
      manuallyAdd(array, curr);
    }
    else if (strcmp(input, "DISPLAY") == 0) {//Calls display function
      
    }
    else if (strcmp(input, "PRINT") == 0) {//Calls the print function
      print(array);
    }
    else if (strcmp(input, "QUIT") == 0) {//Returns false
      playing = false;//Exits while Loop stopping game
    }
  }
  return 0;
}

void addFile(int* array, int &curr) {
  for (int i = 0; i < 100; i++) {
    char input[10];
    char tempString[10];
    int count = 1;
    int numput;
    int randomnum = (rand() % 50) + 1;
    fstream myfile("numberFile.txt");
    while (myfile.getline(input,10, ' ')) {
      if (count == randomnum) {
	strcpy(tempString, input);
	count++;
      }
      count++;
    }
    numput = atoi(tempString);
    array[curr] = numput;
    heap(array, curr);
    curr++;
  }
}

void manuallyAdd(int* array, int &curr) {
  int num;
  cout << "what number would you like add" << endl;
  cin >> num;
  if (array[0] == 0) {
    array[0] = num;
    curr = 1;
  }
  else {
    array[curr] = num;
    heap(array, curr);
    curr++;
  }

}

void display(int* array) {
  
}

void print(int* array) {
  for (int i = 0; i < 100; i ++) {
    cout << array[i] << endl;
  }
}

void heap(int* array, int &curr) {
  if (array[curr] > array[(int) floor((curr-1)/2)]) {
    int temp = array[curr];
    array[curr] = array[(int) floor((curr-1)/2)];
    array[(int) floor((curr-1)/2)] = temp;
    int newcurr = (int) floor((curr-1)/2);
    heap(array, newcurr);
  }
}
