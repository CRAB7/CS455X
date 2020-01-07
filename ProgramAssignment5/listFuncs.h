//*************************************************************************
// Node class definition 
// and declarations for functions on ListType

// Note: we don't need Node in Table.h
// because it's used by the Table class; not by any Table client code.

// Note2: it's good practice to not put "using" statement in *header* files.  Thus
// here, things from std libary appear as, for example, std::string

#ifndef LIST_FUNCS_H
#define LIST_FUNCS_H
  

struct Node {
   std::string key;
   int value;

   Node *next;

   Node(const std::string &theKey, int theValue);

   Node(const std::string &theKey, int theValue, Node *n);
};


typedef Node * ListType;

//*************************************************************************
//add function headers (aka, function prototypes) for your functions
//that operate on a list here (i.e., each includes a parameter of type
//ListType or ListType&).  No function definitions go in this file.
// PRECONDITION: for all list functions except initList, param list must be a well-formed list.


// init the list
void initList(ListType &list);

// insert a node at the beginning of the list
void insertFront(ListType &list, const std::string &theKey, int theValue);

// returns the address of the value that goes with this key
// or NULL if key is not present.
int *findByKey(ListType &list, const std::string &theKey);

// remove a node from the list by its key
// return true if the ndoe exists, or false if it doesn't
bool removeKey(ListType &list, const std::string &theKey);

// print the nodes in the list
void printList(ListType list);

// return the size of the list
int size(ListType list);


// keep the following line at the end of the file
#endif
