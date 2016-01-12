#include <iostream>
#include <stdexcept>
#include "Node.hpp"
#include "List.hpp"
#include "StringMap.hpp"

using namespace std;

StringMap::StringMap(){
  //makes sure the new map is clear
  clear();
}

StringMap::StringMap(const StringMap& anotherStringMap){
  //readying for copying
  clear();
  
  //loops through and copy each of the lists
  for(int i = 0; i < MAP_SIZE; i++){
   map[i] = anotherStringMap.map[i];
  }
}

StringMap StringMap::operator=(const StringMap& anotherStringMap){
  //readying for copying
  clear();
  
  //loop through and copy each of the lists
  for(int i = 0; i < MAP_SIZE; i++){
   map[i] = anotherStringMap.map[i];
  }
}

bool StringMap::isEmpty(){
  //sets default to true
  bool empty = true;

  //looks to be proven otherwise
  for(int i = 0; i < MAP_SIZE; i++){
   if(map[i].getCount() > 0){
    empty = false;
    break;
   }
  }
  return empty;
}

int StringMap::getSize(){
  //counter which counts the number of elements
  int counter = 0;
  
  //loops through the lists
  for(int i = 0; i < MAP_SIZE; i++){
   counter += map[i].getCount();
  }
  return counter;
}

bool StringMap::addValue(string key, string value){
  //defaulted to not stored
  bool stored = false;
 
  //if storage is successful using the hash function, then stored becomes true
  if(key != "" && value != ""){
   int hashkey = static_cast<int>(key.front());
   hashkey = (hashkey*(hashkey+3)) % MAP_SIZE;
   map[hashkey].add(key, value);
   stored = true;
  }
  return stored;
}

string StringMap::getValue(string key){
  //using hash function, goes to appropriate list and gets the proper value
  try{
   int hashkey = static_cast<int>(key.front());
   hashkey = (hashkey*(hashkey+3)) % MAP_SIZE;
   if(map[hashkey].findKey(key) >= 0){
    int ind = map[hashkey].findKey(key);
    return map[hashkey].get(ind); 
   }

   //error handling
   else{
    throw 17;
   }
  }
  catch(int e){
   cout << "No value associated with given key | Error Code: " << e;
  }
}

bool StringMap::deleteValue(string key){
  //defaulted to not deleted
  bool deleted = false;
  
  //using hash function to find the appropriate list and delete the right value
  int hashkey = static_cast<int>(key.front());
  hashkey = (hashkey*(hashkey+3)) % MAP_SIZE;
  if(map[hashkey].findKey(key) >= 0){
   int ind = map[hashkey].findKey(key);
   map[hashkey].remove(ind);
   deleted = true;
  }
  return deleted;
}

void StringMap::clear(){
  //loops through and clears each of the lists
  for(int i = 0; i < MAP_SIZE; i++){
   map[i].clear();
  }
}

bool StringMap::contains(string key){
  //uses hash function to find appropriate list and then checks if the key is valid
  bool found = false;
  int hashkey = static_cast<int>(key.front());
  hashkey = (hashkey*(hashkey+3)) % MAP_SIZE;
  int ind = map[hashkey].findKey(key);
  if(ind >= 0){
   found = true;
  }
  return found;
}

StringMap::~StringMap(){
 //loops through each list and clears it
 for(int i = 0; i < MAP_SIZE; i++){
  map[i].~List();
 }
}


