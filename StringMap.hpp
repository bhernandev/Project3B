#ifndef STRING_MAP
#define STRING_MAP

#include <iostream>
#include "Node.hpp"
#include "List.hpp"

using namespace std; 

class StringMap{
  private:
   int MAP_SIZE = 32;
   List map[32]; //this was implemented with a hash function using an array of lists (lists used for collision)

  public:

   /*
     Default constructor
     @post all lists created and cleared
   */
   StringMap();
 
   /*
     Copy constructor
     @param another string map to be copied from
     @post each list of the other string map SHOULD be copied
   */
   StringMap(const StringMap& anotherStringMap);

   /*
     Assignment operator
     @param another string map to be copied from
     @post each list of the other string map SHOULD be copied
   */
   StringMap operator=(const StringMap& anotherStringMap);
   
   /*
     Loops through and checks if each list of the map is empty
     @return true if empty false if otherwise
   */
   bool isEmpty(); 
 
   /*
     Loops through all lists and counts the number of key value pairs
     @return number of pairs
   */
   int getSize();

   /*
     Uses hash function to determine what index the key value should be added to
     @post key value pair is added to a unique index based off of its first character
     @return true if successful false if otherwise
   */
   bool addValue(string key, string value);
   
   /*
     Using hash function, goes to index of desired value of matching key and returns it
     @return value for key if exists
   */
   string getValue(string key);
   
   /*
     Deletes a value for a given key
     @return true if successful false if otherwise
   */
   bool deleteValue(string key);
  
   /*
     Clears the StringMap of all pairs of values and keys
   */
   void clear();
   
   /* 
     Searches for a value with a given key
   */
   bool contains(string key);

   /*
     Destructor loops through and clears each of the lists
     @post dynamically allocated variables are freed
   */
   ~StringMap();
};

#endif
