#include <iostream>
#include <stdexcept>
#include "Node.hpp"
#include "List.hpp"

using namespace std;

List::List(){
  //all variables set to null value equivalents
  headPtr = nullptr;
  topPtr = nullptr;
  count = 0;
}

List::List(const List& anotherList){
  //same copy constructor as stack implementation from project 2 except keys are copied too
  if(anotherList.headPtr == nullptr && anotherList.topPtr == nullptr){
   headPtr = nullptr;
   topPtr = nullptr;
   count = 0;
  }
  else{
   Node* nNode = new Node();
   headPtr = nNode;
   topPtr = headPtr;
   Node* travPtr = anotherList.headPtr;
   topPtr->key = travPtr->key;
   topPtr->value = travPtr->value;
   while(travPtr->next != nullptr){
    topPtr->next = new Node();
    topPtr = topPtr->next;
    travPtr = travPtr->next;
    topPtr->key = travPtr->key;
    topPtr->value = travPtr->value;
   }
   count = anotherList.count;
   travPtr = nullptr;
  }
}

List List::operator=(const List& anotherList){
  //same assignment operator as stack implementation from project 2 except keys are copied too
  if(anotherList.headPtr == nullptr && anotherList.topPtr == nullptr){
   clear();
   headPtr = nullptr;
   topPtr = nullptr;
   count = 0;
  }
  else{
   clear();
   Node* nNode = new Node();
   headPtr = nNode;
   topPtr = headPtr;
   Node* travPtr = anotherList.headPtr;
   topPtr->key = travPtr->key;
   topPtr->value = travPtr->value;
   while(travPtr->next != nullptr){
    topPtr->next = new Node();
    topPtr = topPtr->next;
    travPtr = travPtr->next;
    topPtr->key = travPtr->key;
    topPtr->value = travPtr->value;
   }
   count = anotherList.count;
   travPtr = nullptr;
  }
}

void List::add(string key, string value){
 //checks if value is unique
 if(find(value) == -1){

  //creates new node to be added
  Node* nNode = new Node();
  nNode->key = key;
  nNode->value = value;
 
  //if list is empty makes top and head the same
  if(topPtr == nullptr){
   topPtr = nNode;
   headPtr = topPtr;
  }
  
  //otherwise adds to end of the list
  else{
   topPtr->next = nNode;
   topPtr = nNode;
  }
  count += 1;
 }
}

void List::remove(int index){
  //making sure no accessing outside of list
  if(index < count){
 
   //travPtr to traverse and savePtr to keep order
   Node* travPtr = headPtr;
   Node* savePtr = headPtr;

   //edge case of index 0
   if(index == 0){
    savePtr = travPtr->next;
    delete travPtr;
    headPtr = savePtr;
   }

   //going to desired index
   else{
    int counter = 1;
    travPtr = travPtr->next;
    while(counter != index){
     travPtr = travPtr->next;
     savePtr = savePtr->next;
     counter += 1;
    }

    //deletind desired index while keeping the order
    savePtr->next = travPtr->next;
    delete travPtr;
    travPtr = nullptr;
    savePtr = nullptr;
   }
   count -= 1;
  }
}

string List::get(int index){
  //returns this if nothing
  string val = "";

  //going to desired index
  if(index < count){
   Node* travPtr = headPtr;
   int counter = 0;
   while(counter != index){
    travPtr = travPtr->next;
    counter += 1;
   }

   //retrieving the value
   val = travPtr->value;
  }
  return val;
}

string List::getKey(int index){
  //same methodology as other get method
  string val = "";
  if(index < count){
   Node* travPtr = headPtr;
   int counter = 0;
   while(counter != index){
    travPtr = travPtr->next;
    counter += 1;
   }
   val = travPtr->key;
  }
  return val;
}

int List::find(string value){
  //default return value
  int val = -1;

  //loops through list using get to see if the value is contained at all
  for(int i = 0; i < count; i++){
   if(get(i) == value){
    val = i;

    //ends loop if found
    break;
   }
  }
  return val;
}

int List::findKey(string key){
  //same methodology as other find method
  int val = -1;
  for(int i = 0; i < count; i++){
   if(getKey(i) == key){
    val = i;
    break;
   }
  }
  return val;
}

int List::getCount(){
 return count;
}

void List::clear(){
  //same as destructor, loops through and deletes each member of the list seperately
  Node* travPtr = headPtr;
  while(headPtr != nullptr){
  headPtr = travPtr->next;
  delete travPtr;
  travPtr = headPtr;
  }
  headPtr = nullptr;
  topPtr = nullptr;
  travPtr = nullptr;
  count = 0;
}

List::~List(){
  Node* travPtr = headPtr;
  while(headPtr != nullptr){
   headPtr = travPtr->next;
   delete travPtr;
   travPtr = headPtr;
  }
  headPtr = nullptr;
  topPtr = nullptr;
  travPtr = nullptr;
}
