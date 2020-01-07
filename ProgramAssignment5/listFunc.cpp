#include <iostream>

#include <cassert>

#include "listFuncs.h"

using namespace std;

Node::Node(const string &theKey, int theValue) {
   key = theKey;
   value = theValue;
   next = NULL;
}

Node::Node(const string &theKey, int theValue, Node *n) {
   key = theKey;
   value = theValue;
   next = n;
}




//*************************************************************************
// put the function definitions for your list functions below

// init the list
void initList(ListType &list) {
   list = NULL;
}

// insert a node at the beginning of the list
void insertFront(ListType &list, const string &theKey, int theValue) {
   Node *newNode = new Node(theKey, theValue, list);
   list = newNode;
}

// returns the address of the value that goes with this key
// or NULL if key is not present.
int *findByKey(ListType &list, const string &theKey) {
   Node *p = list;
   while (p != NULL) {
      if (p -> key == theKey) {
         return &(p -> value);
      }
      p = p -> next;
   }
   return NULL;
}

// remove a node from the list by its key
bool removeKey(ListType &list, const string &theKey) {
   if (list == NULL) {
      return false;
   }
   if (list -> key == theKey) {
      delete list;
      list = NULL;
      return true;
   }
   Node *prev = list;
   Node *p = list -> next;
   while (p != NULL) {
      if (p -> key == theKey) {
         prev -> next = p -> next;
         delete p;
         return true;
      }
      prev = p;
      p = p -> next;
   }
   return false;
}
         

// print the nodes in the list
void printList(ListType list) {
   if (list == NULL) {
      return;
   }
   Node *p = list;
   while (p != NULL) {
      cout << p -> key << " " << p -> value << endl;
      p = p -> next;
   }
}
   
   
// return the size of the list
int size(ListType list) {
   int count = 0;
   Node *p = list;
   while (p != NULL) {
      ++count;
      p = p -> next;
   }
   return count;
}
