// heap.cpp
// Tony Tran

#include "heap.h"
#include <iostream>
using std::cout;
//helper FUNCTIONS

void Heap::bubbleUp(int index){ 
  while (index > 0){
    int parentIndex = (index - 1) / 2;
  
    if (vdata[index] >= vdata[parentIndex]){
      return;
    }
    else{
      int temp = vdata[index];
      vdata[index] = vdata[parentIndex];
      vdata[parentIndex] = temp;
      index = parentIndex;
    }
  }


}
void Heap::bubbleDown(int index){
  int childIndex = 2 * index + 1;
  int value = vdata[index];
  while (childIndex < vdata.size()){
    int max = value;
    int maxIndex = -1;
    int i = 0;
    while (i < 2 && i + childIndex < vdata.size()) {
      if (vdata[i + childIndex]> max){
        max = vdata[i + childIndex];
        maxIndex = i + childIndex;
      }
      ++i;
      }
      if (max == value){
        return;
      }
      else{
        int temp = vdata[index];
        vdata[index] = vdata[maxIndex];
        vdata[maxIndex] = temp;
        index = maxIndex;
        childIndex= 2 * index + 1;
      }
      
      }

}








// Pushes a value into the heap, then ensures
// the heap is correctly arranged
void Heap::push(int value){
  vdata.push_back(value);
  bubbleUp(vdata.size()-1);




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
    bubbleDown(0);
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
    