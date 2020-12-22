// CS311 Yoshii - Hash Table - complete all ** parts.
// Note: this class does not know the parts of element except for key
// so that it would work even if each element in the hash table changed
//-----------------------------------------------------

// ============================================
// HW#: Final Project (Album Tracker)
// Name: Keith Kofoed
// File Type: implementation htable.cpp
// =============================================

using namespace std;
#include <iostream>
#include "htable.h"

//default constructor
htable::htable()
{

}
//destructor
htable::~htable()
{

}

//This hash function takes a string & converts each character into an integer, adds 13 to each, and sums the total; then, mods
//by the table size.
//parameters: a string key.
int htable::hash(string key)
{
	int sum = 0;
	for (int i = 0; i < key.size(); i++) {
		sum += key[i] + 13;
	}
	int h = sum % TSIZE;
	return h;
}

// adds the element to the table and returns slot#
//parameteres; an el_t element
int htable::add(el_t element)
{
	int slot = hash(element.getkey());  // hash with the key part
	table[slot].addRear(element);
	//** Note that this means adding the element to a slist in the slot(addRear)
	return slot;
}

// finds element using the skey and returns the found element itself
// or a blank element  -- there is no cout in here
//parameters: a char key; int was previously used in another assignment but
//as elem.cpp changes, find also changes - an exception to keeping previous
//functions intact.
el_t htable::find(string skey)
{
	int slot = hash(skey); // hash with skey
	el_t selement(skey, "");  // this is the element to look for in slist
	return table[slot].search2(selement);
}

//Displays albums that are in the table. Slots without an entry will indicate as such. Slot #'s are also displayed.
//parameters: none needed.
void htable::displayTable()
{
	for (int i = 0; i < TSIZE; i++)	//iterate thru the table.
	{
	//	cout << "Slot " << i << ": ";	//indicates current slot position
		table[i].displayAll();		//displays all elements of that slot
	}
}

void htable::displaySingle(el_t arg)
{
	table->displayDeets(arg);
}

//Saves the current table contents to a file. Calls an llist function.
//Parameters; a hashtable & an ostream. the ostream is passed down to the llist function.
void htable::saveTable(htable at, ostream& as)
{
	for (int i = 0; i < TSIZE; i++)	//iterate thru the table.
	{
		if (!at.table[i].isEmpty()) {	//if the element at this slot isn't empty,
			at.table[i].saveFile(as);	//call llist's savefile on this slot.
		}
	}
}

//PURPOSE: Deletes an entry from the table.
//PARAMETERS: an el_t object (data entry) and a table.
void htable::deleteIt(el_t arg, htable ht)
{
	string s = arg.getkey();	//get the key from the argument.
	int i = hash(s);			//turn this key into an integer. redundant; may find better fix later.
	int d = ht.table[i].search(arg);	//find index of element within the table slot.
										//this is useful for colliding elements.
	table[i].deleteIth(d, arg);		//deleteIth is in llist.
}
