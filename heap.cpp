// heap.cpp
// Tony Tran

#include "heap.h"
#include <iostream>
using std::cout;
//helper FUNCTIONS
void Heap::up(int value){
  while(value > 0){
    int temp = (value - 1)/2;
    if(vdata[value] >= vdata[temp]){
      return;
    }
    else{
      int temp = vdata[value];
      vdata[value] = vdata[temp];
      vdata[temp] = temp;
      value = temp;
    }
  }

}
void Heap::down(int value){
  int newValue = 2 * value + 1;
  int value = vdata[value];
  while(newValue < vdata.size()){
    int MIN = value;
    int ind = -1;
    int i = 0;
    while (i < 2 && i + newValue < vdata.size()) {
      if (vdata[i + newValue] < MIN){
        MIN = vdata[i + newValue];
        ind = i + newValue;
      }
      i++;
    }
    if(MIN == value){
      return;
    }
    else{
      int temp = vdata[value];
      vdata[value] = vdata[ind];
      vdata[ind] = temp;
      value = ind;
      newValue = 2 * value + 1;
    }
  }
  }










// Pushes a value into the heap, then ensures
// the heap is correctly arranged
void Heap::push(int value){
  vdata.push_back(value);
  up(vdata.size()-1);




}

// Pops the minimum value off the heap
// (but does not return it), then ensures
// the heap is correctly arranged
void Heap::pop(){
  if (vdata.size() == 0){
    return;
  }
  else if (vdata.size() == 1){
    vdata.erase(vdata.begin());
  }
  else{
    int Val = vdata[vdata.size() - 1];
    vdata[0] = Val;
    vdata.pop_back();
    down(0);
  }

}

// Returns the minimum element in the heap
int Heap::top(){
  if(vdata.size()==0){
    return -1;
  }
  else{
    return vdata[0];
  }
}

// Returns true if the heap is empty, false otherwise
bool Heap::empty(){
  if (vdata.size()==0){
    return true;
  }
  else{
    return false;
  }
}
    