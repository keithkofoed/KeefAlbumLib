//============================================
//HTABLE HEADER
//===========================================

#include "slist.h"
//the below includes will be used in a later version
#include <stdlib.h>
#include <time.h>

const int TSIZE = 101;  // 101 slots ;
//this is a prime number.

class htable
{
private:
	slist table[TSIZE]; // each node of slist is el_t 
							 // as defined in elem.h
	int hash(string);  // private hash function

public:
	htable();  //default constructor
	~htable();  //destructor

	int add(el_t);  // adds an album to the table and returns slot #
	el_t find(string); // finds an element based on key and returns it
	void displayTable(); // displays the table with slot#s
	void displaySingle(el_t); //display single album's details

//PURPOSE: deletes an object from the table.
//PARAMETERS: an el_t to delete.
	void deleteIt(el_t, htable);

//PURPOSE:Saves the current table contents to a file. Calls an llist function.
//Parameters; a hashtable & an ostream. the ostream is passed down to the llist function.
	void saveTable(htable, ostream&);
};
