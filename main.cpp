#include <iostream>
#include <cstring>

using namespace std;

void manuallyAdd(int* array, int &curr);
void heap(int* array, int &curr);

int main() {
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
      
    }
    else if (strcmp(input, "TYPE") == 0) {//Calls type function
      manuallyAdd(array, curr);
    }
    else if (strcmp(input, "DISPLAY") == 0) {//Calls display function
      
    }
    else if (strcmp(input, "PRINT") == 0) {//Calls the print function
      
    }
    else if (strcmp(input, "QUIT") == 0) {//Returns false
      playing = false;//Exits while Loop stopping game
    }
  }
  return 0;
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
    //heap()
    curr++;
  }

}

void heap(int* array, int &curr) {
  if (array[curr] > array[(curr-1)/2]) {
    int temp = array[curr];
    array[curr] = array[(curr-1)/2];
    array[(curr-1)/2] = temp;
    heap(array, (curr-1)/2);
  }
}
