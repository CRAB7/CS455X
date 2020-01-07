/*
 * grades.cpp
 * A program to test the Table class.
 * How to run it:
 *      grades [hashSize]
 * 
 * the optional argument hashSize is the size of hash table to use.
 * if it's not given, the program uses default size (Table::HASH_SIZE)
 *
 */

#include "Table.h"

// cstdlib needed for call to atoi
#include <cstdlib>

using namespace std;

// try to insert
void callInsert(Table * &grades) {
   string name;
   int score;
   cin >> name >> score;
   bool result = grades -> insert(name, score);
   if (!result) {
      cout << "This record has existed!" << endl;
   }   
}

// try to change a score
void callChange(Table * &grades) {
   string name;
   int newscore;
   cin >> name >> newscore;
   int *value = grades -> lookup(name);
   if (value == NULL) {
      cout << name << " does not exist..." << endl;
   } else {
      *value = newscore;
   }
}

// try to lookup
void callLookup(Table * &grades) {
   string name;
   cin >> name;
   int *value = grades -> lookup(name);
   if (value == NULL) {
      cout << name << " does not exist..." << endl;
   } else {
      cout << *value << endl;
   }
}

// try to remove
void callRemove(Table * &grades) {
   string name;
   cin >> name;
   bool result = grades -> remove(name);
   if (!result) {
      cout << name << " does not exist..." << endl;
   }
}

// print help message
void helper() {
   cout << "Valid comments are: " << endl;
   cout << "   insert name score; change name newscore; lookup name; remove name; print; size; stats; help; quit." << endl;
}

// handle different commands
void start(Table * &grades) {
   bool keepgoing = true;
   string command;
   
   do {
      cout << "cmd> " << endl;
      cin >> command;
      if (command == "insert") {
         callInsert(grades);
      } else if (command == "change") {
         callChange(grades);
      } else if (command == "lookup") {
         callLookup(grades);
      } else if (command == "remove") {
         callRemove(grades);
      } else if (command == "print") {
         grades -> printAll();
      } else if (command == "size") {
         cout << grades -> numEntries() << endl;
      } else if (command == "stats") {
         grades -> hashStats(cout);
      } else if (command == "help") {
         helper();
      } else if (command == "quit") {
         return;
      } else {
         cout << "ERROR: invalid command" << endl;
         helper();
      }
   } while (keepgoing);
}

// main function
int main(int argc, char * argv[]) {

   // gets the hash table size from the command line

   int hashSize = Table::HASH_SIZE;

   Table * grades;  // Table is dynamically allocated below, so we can call
   // different constructors depending on input from the user.

   if (argc > 1) {
      hashSize = atoi(argv[1]);  // atoi converts c-string to int

      if (hashSize < 1) {
         cout << "Command line argument (hashSize) must be a positive number" 
              << endl;
         return 1;
      }

      grades = new Table(hashSize);

   }
   else {   // no command line args given -- use default table size
      grades = new Table();
   }

   grades->hashStats(cout);

   start(grades);
      
   return 0;
}
