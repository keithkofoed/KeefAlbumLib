// ====================================================
//SLIST HEADER FILE
//=====================================================

#include "llist.h"

class slist : public llist {

public:

	slist();   // Default constructor; calls LLIST constructor.

//PURPOSE: Search for an album..
//PARAMETERS: an album to search for.
	int search(el_t);

//PURPOSE: Search thru the list to return the el_t in the list instead of position (HW8)
//PARAMETERS: The el_t provided.
	el_t search2(el_t);

//PURPOSE: Go to the Ith node (I is between 1 and Count) and replace the element there with Elem.
//PARAMETERS: an element and a position integer.
void replace(el_t, int);

//PURPOSE: compare two slist object to see if they look the same.
//PARAMETERS: a list to compare this-> to.
	bool operator==(const slist&);
};