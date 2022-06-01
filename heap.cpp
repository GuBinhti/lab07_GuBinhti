// heap.cpp
// Tony Tran

#include "heap.h"
#include <iostream>
using std::cout;
//helper FUNCTIONS

void Heap::bubbleUp(int index){ 
  while (index > 0){
    int parentIndex = (index - 1) / 2;
  
    if (vdata.at(index) >= vdata.at(parentIndex)){
      return;
    }
    else{
      int temp = vdata.at(index);
      vdata.at(index) = vdata.at(parentIndex);
      vdata.at(parentIndex) = temp;
      index = parentIndex;
    }
  }


}
void Heap::bubbleDown(int index){
  int childIndex = 2 * index + 1;
  int value = vdata.at(index);
  while (childIndex < vdata.size()){
    int min = value;
    int minIndex = -1;
    for (int i = 0; (i < 2) && (i + childIndex < vdata.size()); i++){
      if (vdata.at(i + childIndex)< min){
        min = vdata.at(i + childIndex);
        minIndex = i + childIndex;
      }
      }
      if (min == value){
        return;
      }
      else{
        int temp = vdata.at(index);
        vdata.at(index) = vdata.at(minIndex);
        vdata.at(minIndex) = temp;
        index = minIndex;
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
    vdata.pop_back();
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
    