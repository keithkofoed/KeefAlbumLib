// ====================================================
//SLIST FUNCTIONS
//=====================================================

using namespace std;
#include<iostream>
#include"slist.h" 

//PURPOSE: to indicate the slist constructor is activating; this happens as the llist constructor activates
//PARAMETERS: none needed
slist::slist()
{
}

//PURPOSE: Search through the list to see if any node contains the Album.
//PARAMETERS: an album to search for.
int slist::search(el_t key) {
	//Create a node to search through the this-> list
	Node *p = this->Front;
	//positions always start at 1
	int look = 1;

	//while reading the list
	while (p != NULL) {
		if (p->Elem == key) {
			return look;
			//if album is found, return position
		}
		look++; //increment position
		p = p->Next; //increment p's position in the list likewise
	}
	//else, return 0.
	return 0;
}

//PURPOSE: searches by album name; returns full information about that album if it exists.
//PARAMETERS: an album name.
el_t slist::search2(el_t key)
{
	//Create a node to search through the this-> list
	el_t temp;
	Node *p = Front;
	string s = key.getkey();
	string re;

	//while reading the list
	while (p != NULL) {
		//set int re to key from p->elem
		re = (p->Elem).getkey();
		//if there is equality
		if (re == s) {
			//return p->elem, which has both components
			return p->Elem;
		}
		p = p->Next; //increment p's position in the list
	}

	//else, return blank
	return temp;
}

//PURPOSE: Go to the Ith node (I is between 1 and Count) and replace the element there with Elem.
//PARAMETERS: an album to look for & a position.
//can throw outofrange.
void slist::replace(el_t element, int pos) {

	//If the position passed is greater than this->count or less than one, throw out of range.
	if (pos > this->Count || pos < 1) {
		throw OutOfRange();
	}

	Node *p = new Node;
	p = this->Front;
	llist::moveTo(pos, p);
	p->Elem = element;
}

//PURPOSE: compare two slist object to see if they look the same.
//PARAMETERS: a list to compare this-> to.
bool slist::operator==(const slist& OtherOne) {

	// if not the same length, return false
	if (this->Count != OtherOne.Count) {
		return false;
	}

	//Create two temp nodes to cycle through each list
	//(being this-> and otherone)
	Node *p = this->Front;
	Node *q = OtherOne.Front;
	//I choose to use a counter to keep track of iterations
	int i = 1;

	// if the same lengths, check each node to see if the elements are the same
	while (i <= this->Count) {
		if (p->Elem != q->Elem) {
			return false;
			//return false if the elements are not the same
		}
		i++; //iterate i
		p = p->Next; //go to p's next
		q = q->Next; //go to q's next
	}

	//if no false flags were raised, then return true.
	return true;
}
