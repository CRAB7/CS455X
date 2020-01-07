// pa5list.cpp
// a program to test the linked list code necessary for a hash table chain

// You are not required to submit this program for pa5.

// We gave you this starter file for it so you don't have to figure
// out the #include stuff.  The code that's being tested will be in
// listFuncs.cpp, which uses the header file listFuncs.h

// The pa5 Makefile includes a rule that compiles these two modules
// into one executable.

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

#include "listFuncs.h"

void testEmpty() {
   ListType empty;
   initList(empty);
   cout << "an empty list: ";
   printList(empty);
   cout << endl;
   cout << size(empty) << endl;
}

void testInsert() {
   ListType list1;
   initList(list1);
   insertFront(list1, "zhou", 1);
   insertFront(list1, "mary", 2);
   insertFront(list1, "Jack", 3);
   cout << "entries in list1:" << endl;
   printList(list1);
   cout << "endprint!" << endl;
   cout << "test Find By Key:" << endl;
   cout << findByKey(list1, "Jac") << endl;
   int* result = findByKey(list1, "zhou");
   if (result == NULL) 
      cout << "zhou is not present!" << endl;
   else
      cout << "have find zhou in " << *result << endl;
   cout << "test removeKey" << endl;
   cout << "try to remove zhou:" << removeKey(list1, "zhou") << endl;
   cout << "list after remove zhou :" << endl;
   printList(list1);
   cout << "try to remove zhou:" << removeKey(list1, "zhou") << endl;
   cout << "list after remove zhou :" << endl;
   printList(list1);
   cout << "size of list1 is " << size(list1) << endl;
}

int main() {

   // testEmpty();
   testInsert();

   return 0;
}
