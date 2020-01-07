// Table.cpp  Table class implementation


#include "Table.h"

#include <iostream>
#include <string>
#include <cassert>

using namespace std;


// listFuncs.h has the definition of Node and its methods.  -- when
// you complete it it will also have the function prototypes for your
// list functions.  With this #include, you can use Node type (and
// Node*, and ListType), and call those list functions from inside
// your Table methods, below.

#include "listFuncs.h"


//*************************************************************************

// create an empty table, i.e., one where numEntries() is 0
// (Underlying hash table is HASH_SIZE.)
Table::Table() {
   hashSize = HASH_SIZE;
   arr = new ListType[hashSize]();
}

// create an empty table, i.e., one where numEntries() is 0
// such that the underlying hash table is hSize
Table::Table(unsigned int hSize) {
   hashSize = hSize;
   arr = new ListType[hashSize]();
}

// returns the address of the value that goes with this key
// or NULL if key is not present.
//   Thus, this method can be used to either lookup the value or
//   update the value that goes with this key.
int * Table::lookup(const string &key) {
   unsigned int hashKey = hashCode(key);
   return findByKey(arr[hashKey], key);   // dummy return value for stub
}

// remove a pair given its key
// false iff key wasn't present
bool Table::remove(const string &key) {
   unsigned int hashKey = hashCode(key);
   return removeKey(arr[hashKey], key);  // dummy return value for stub
}

// insert a new pair into the table
// return false iff this key was already present 
//         (and no change made to table)
bool Table::insert(const string &key, int value) {
   unsigned int hashKey = hashCode(key);
   if (findByKey(arr[hashKey], key) == NULL) {
      insertFront(arr[hashKey], key, value);
      return true;
   }
   return false;  // dummy return value for stub
}

int Table::numEntries() const {
   int count = 0;
   for (int i = 0; i < hashSize; ++i) {
      count += size(arr[i]);
   }
   return count;
}


void Table::printAll() const {
   for (int i = 0; i < hashSize; ++i) {
      printList(arr[i]);
   }
}

// hashStats: for diagnostic purposes only
// prints out info to let us know if we're getting a good distribution
// of values in the hash table.
// Sample output from this function
//   number of buckets: 997
//   number of entries: 10
//   number of non-empty buckets: 9
//   longest chain: 2
void Table::hashStats(ostream &out) const {
   out << "number of buckets: " << hashSize << endl;
   out << "number of entries: " << this -> numEntries() << endl;
   int nonEmpty = 0, longest = 0;
   for (int i = 0; i < hashSize; ++i) {
      if (arr[i] != NULL) {
         ++nonEmpty;
         int currSize = size(arr[i]);
         if (longest < currSize) {
            longest = currSize;
         }
      }
   }
   out << "number of non-empty buckets: " << nonEmpty << endl;
   out << "longest chain: " << longest << endl;
}


// add definitions for your private methods here
