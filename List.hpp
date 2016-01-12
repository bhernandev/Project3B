#ifndef LIST
#define LIST

#include <iostream>
#include "Node.hpp"

using namespace std;

//I used parts of my project 2 to create a fully functioning list ADT, which I utilized for my StringMap

class List{
  private:
   Node* headPtr; //pointer to head of the list
   Node* topPtr; //pointer to end of the list
   int count; //number of unique elements in list
  
  public:
   List();
   List(const List& anotherList);
   List operator=(const List& anotherList);
   void add(string key, string value); //adds a key value pair to the list
   void remove(int index);
   string get(int index);
   string getKey(int index);
   int find(string value);
   int findKey(string key);
   int getCount();
   void clear(); //basically the same as destructor, but also resets count
   ~List();
};

#endif 
