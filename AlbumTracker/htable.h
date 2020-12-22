// CS311 Yoshii - Hash Table header DO NOT CHANGE!!! 
// ------------------------------------------------

#include "slist.h"
#include <stdlib.h>
#include <time.h>

const int TSIZE = 101;  // 101 slots ; updated for final project.
//this is a prime number.

class htable
{
private:
	slist table[TSIZE]; // each node of slist is el_t 
							 // as defined in elem.h
	int hash(string);  // private hash function
						//UPDATED IN FINAL TO TAKE A STRING.

	int shuffle(htable);	//shuffle all albums' hash keys.

public:
	htable();
	~htable();

	int add(el_t);  // adds an element to the table and returns slot#
	el_t find(string); // finds an element based on key and returns it
	void displayTable(); // displays the table with slot#s
	void displaySingle(el_t); //display single album's details

//NEW FUNCTION for HashTable: you must add a deleteIt function to delete an object from the table.  
//Hint: You must use search and deleteIth of the linked list class
//PURPOSE: deletes an object from the table.
//PARAMETERS: an el_t to delete.
	void deleteIt(el_t, htable);

	//PURPOSE:Saves the current table contents to a file. Calls an llist function.
	//Parameters; a hashtable & an ostream. the ostream is passed down to the llist function.
	void saveTable(htable, ostream&);
};
