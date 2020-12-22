// =======================================================
//LINKED LIST HEADER
//=======================================================

#include "elem.h"

struct Node
{
	el_t Elem;   // elem is the element stored
	Node *Next;  // next is the pointer to the next node
};
//---------------------------------------------------------

class llist
{
protected: //Other clients will not be inheriting these.
	Node *Front;       // pointer to the front node
	Node *Rear;        // pointer to the rear node
	int  Count;  // counter for the number of nodes

	// utility function to move to a specified node position
	void moveTo(int, Node*&);

public:
	// Exception handling classes 
	class Underflow {};	//thrown when insert/delete is called on empty list.
	class OutOfRange {};  // thrown when the specified Node is out of range

//PURPOSE: Default Constructor. Sets initial elements to null and zero.
//PARAMETERS: None; default.
	llist();     // constructor to create a list object

//PURPOSE: Destructor. Eliminates all the elements of the list & the list itself.
//PARAMETERS: None; destructor.
	~llist();     // destructor to destroy all nodes

//PURPOSE: Checks to see if the llist is empty. If not, returns false.
//PARAMETER: None needed.
	bool isEmpty();

//PURPOSE: Different display functions. Parameters vary.
	void displayAll();
	void displayDeets(el_t);

//PURPOSE: Saving a file to an ostream. Mirrors displayAll functionality.
	void saveFile(ostream&);

//PURPOSE: Add a node to the front of the list.
//PARAMETER: The new number to be added.
	void addFront(el_t NewNum);

//PURPOSE: Add a node to the rear of the linked list.
//PARAMETER: The new number to be added.
	void addRear(el_t NewNum);

//PURPOSE: Deletes the node at the front of the list.
//PARAMETER: The deleted number will be set equal to a variable passed in the argument.
	void deleteFront(el_t& OldNum);

//PURPOSE: Deletes the node at the rear.
//PARAMETER: The deleted number is set equal to the passed argument.
	void deleteRear(el_t& OldNum);

//PURPOSE: Deletes a node at the position indicated by the I argument.
//PARAMETER: The I argument holds the position to be deleted; the deleted
//integer will be set to the second argument passed.
	void deleteIth(int, el_t& a);  // calls moveTo

//PURPOSE: Inserts a node between two other nodes.
//PARAMETER: An int to indicate position to be 
	void insertIth(int, el_t);   // calls moveTo

//PURPOSE: A copy constructor that sets a new llist to properties of another llist.
//PARAMETER: Accepts an "Original" linked list.
	llist(const llist&);

//PURPOSE: Overloaded = Operator.
//PARAMETER: This will be used to compare objects, such as the linked list.
//This is important because the equals operator usually only works on primitive types, but not objects.
	llist& operator=(const llist&);
};