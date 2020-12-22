// ====================================================
//LINKED LIST FUNCTIONS
//=====================================================

using namespace std;
#include <iostream>
#include "llist.h" 

//PURPOSE: Default Constructor. Sets initial elements to null and zero.
//PARAMETERS: None; default.
llist::llist()
{
	Front = NULL;
	Rear = NULL;
	Count = 0;
}

//PURPOSE: Destructor. Eliminates all the elements of the list & the list itself.
//PARAMETERS: None; destructor.
llist::~llist()
{
	while (!isEmpty()) {
		deleteFront(Front->Elem);
	}
}

//PURPOSE: Checks to see if the llist is empty. If not, returns false.
//PARAMETER: None needed.
bool llist::isEmpty() {
	if (Front == NULL) {
		if (Rear == NULL) {
			if (Count == 0) {
				return true;
			}
		}
	}
	return false;
}

//PURPOSE: Displays the elements of the linked list in a horizontal set surrounded by brackets.
//PARAMETER: None needed.
void llist::displayAll() {
	if (isEmpty()) {
		//DO NOTHING OR cout << " (Empty Slot)" << endl;
		return;
	}
	//A common theme here is creating a node to navigate the linked list.
	Node *p = Front;

	while (p != NULL) {
		cout << p->Elem.getkey() << " by " << p->Elem.getArt();	//formatting.
		p = p->Next;		
		//set to p->next to nagivate to next elem.
		cout << endl;
	}
}

//PURPOSE: Displays details of an individual album.
//PARAMETERS: Accepts an element. This is important to access the getters.
void llist::displayDeets(el_t ele)
{
		cout << ele.getkey() << " is a " << ele.getGen() << " album by " << ele.getArt() << " released in " << ele.getYear() << ".";
}

//PURPOSE: saveFile will write contents to filled elems to an outfile.
//PARAMETERS: an ostream is accepted from htable, passed from main.
//You don't know how long I toiled with this.
//& it came out to be four lines. programming is fun and good.
void llist::saveFile(ostream &os)
{	
	Node *p = Front;	//set a node to the front. this will act similarly to displayAll().
	while (p != NULL) {	//while there are elements in this list - useful for collisions
		os << p->Elem;	//write elem to file using overloaded <<
		p = p->Next;	//iterate to next, checking for collided elements.
	}
}

//PURPOSE: Add a node to the rear of the linked list.
//PARAMETER: The new element to be added.
void llist::addRear(el_t NewNum) {

	//Special Case: If there are no current nodes, create a new node.
	//Make Front & Rear point to it.
	//Put NewNum in the ELem field.
	//Count is updated.
	if (Rear == NULL) {
		Node *p = new Node;	//Creation of new node.
		Front = p;			//Set front to p
		Rear = Front;		//and rear.
		p->Elem = NewNum;	//fill it w/ elem.
		Front->Next = NULL; //Since this is the only node, front's next is null.
		Rear->Next = NULL; //Rear->Next should always be NULL
		Count++;			//to keep track of our nodes.
	}

	//Regular Case: When there exists a Node already. Add to rear.
	else {
		Rear->Next = new Node;	//to indicate another node being added after rear
		Rear = Rear->Next;		//move the rear ptr to the new node
		Rear->Elem = NewNum;	//set it's elem to the new num
		Rear->Next = NULL;		//rear->next should always be NULL
		Count++;				//increase count of nodes
	}

}

//PURPOSE: Add a node to the front of the list.
//PARAMETER: The new number to be added.
void llist::addFront(el_t NewNum) {

	//Special Case: If this is the first node, create new node.
	//Front & Rear point to it.
	//Put NewNum in the Elem field. Count++.
	if (Front == NULL) {
		Node *p = new Node;		//this will be the new node
		Front = p;				//set front = p since it is only node in ll
		Rear = Front;			//set rear to front since it is only node in ll
		p->Elem = NewNum;		//sets the elem to passed argument
		Front->Next = NULL;		//front's next is null.
		Rear->Next = NULL;	//rear->next is always null
		Count++;			//increase count of nodes
	}
	//Regular Case: add new node at the front.
	//Put newnum in the elem field.
	//Count is updated.
	else {
		Node *p = new Node;	//this is the node we're adding
		p->Elem = NewNum;	//set its elem value to the argument passed
		p->Next = Front;	//the new node's next points to the previous front
		Front = p;			//move front to the new node at the front
		Count++;			//increase count of our nodes
	}

}

//PURPOSE: Deletes the node at the front of the list.
//PARAMETER: The deleted element will be set equal to a variable passed in the argument.
void llist::deleteFront(el_t& OldNum) {

	//If the list is empty, throw an underflow exception.
	if (isEmpty()) {
		throw Underflow();
	}

	//If this will make the list empty, give back the front node element
	//through oldnum & remove front node.
	if (Front == Rear) {
		OldNum = Front->Elem;		//we can set the oldnum to either rear or front elem.
		Front = NULL;				//make them all null and delete them.
		Rear = NULL;
		delete Front;
		delete Rear;
		Count--;				//decrease number of nodes. should be 0 in this case.
		//as a sidenote, this could be its own function. repeat code.
	}

	//Regular Case: set oldnum to the front element. Delete it & remove front node.
	else {
		OldNum = Front->Elem;		//set the oldnum arg equal to value to be deleted
		Node *Second;				//this will become our new front node
		Second = Front->Next;		//set it equal to the node next to front
		delete Front;				//delete front
		Front = Second;				//and set it equal to the second node
		Count--;					//decrease count of nodes
	}

}

//PURPOSE: Deletes the node at the rear.
//PARAMETER: The deleted element is set equal to the passed argument.
void llist::deleteRear(el_t& OldNum) {

	//when the list is empty, throw an underflow exception.
	if (Count == 0) {
		throw Underflow();
	}

	//If this empties the list, return rear element thru oldnum.
	//Remove rear node.
	//Update Count. Front & Rear become NULL.
	if (Front == Rear) {
		OldNum = Front->Elem;		//we can set the oldnum to either rear or front elem.
		Front = NULL;				//make them all null and delete them.
		Rear = NULL;
		delete Front;
		delete Rear;
		Count--;				//decrease number of nodes. should be 0 in this case.
		//as a sidenote, this could be its own function. repeat code.
	}

	//In the regular case, the node at the end of the list
	//is deleted and rear now points to the i-1 node.
	else {
		Node *Second = Front;			//declare a node to point at front
		OldNum = Rear->Elem;			//sets the old num to elem in the rear.
		while (Second->Next != Rear) {	//navigate second ptr to the ptr preceeding rear.
			Second = Second->Next;		//using ->next
		}
		delete Rear;					//then, delete it
		Rear = Second;					//new Rear is at the second node (preceeding last rear)
		Rear->Next = NULL;				//Rear->Next should always be NULL.
		Count--;						//Decrease our count of nodes.
	}
}

//PURPOSE: Utility Function to move a local pointer to the Jth node.
//PARAMETERS: The integer indicating the desired position & a temp Node to set position to.
void llist::moveTo(int J, Node*& temp)
{
	//Will set temp to the position indicated by the integer argument.
	// moves temp J-1 times to go to the Jth node
	for (int K = 1; K < J; K++) {
		temp = temp->Next;
	}
}

//PURPOSE: Deletes a node at the position indicated by the I argument.
//PARAMETER: The I argument holds the position to be deleted; the deleted
//element will be set to the second argument passed.
void llist::deleteIth(int I, el_t& OldNum) {

	//If the position indicated is more than the number of nodes we have
	//or is less than 1, we are out of range.
	if (I > Count || I < 1) {
		throw OutOfRange();
	}

	//If I is set to position 1 (index 0) then just delete the front node.
	if (I == 1) {
		deleteFront(OldNum);
	}

	//If the position indicated is the position at the rear, just call deleteRear.
	else if (I == Count) {
		deleteRear(OldNum);
	}

	//In the normal case, delete a node indicated by the integer I.
	//This is done by declaring two pointers; one points to the
	//position before the node indicated, the other points to
	//the one to be deleted through ->next. the first node's
	//next attribute is set to ->next->next, and the second
	//node is deleted & set to NULL.
	else {
		Node *p = Front;			//set first node equal to front
		moveTo(I - 1, p);			//move it to node preceeding index desired
		Node *d = p->Next;			//set second node equal to first's next
		p->Next = p->Next->Next;	//the first's node's next is equal to two nodes over
		OldNum = d->Elem;			//Set the oldnum to d's elem.
		delete d;					//delete second node
		d = NULL;					//and set it to NULL.
		Count--;					//Decrease count.
	}
}

//PURPOSE: Inserts a node between two other nodes.
//PARAMETER: An int to indicate position.
void llist::insertIth(int I, el_t newNum) {

	if (I > Count + 1 || I < 1) {
		throw OutOfRange();
	}

	//If I indicates index 0 (position 1) then just call addFront.
	else if (I == 1) {
		addFront(newNum);
	}

	//If I indicates adding a node to the rear, just call addRear.
	else if (I == Count + 1) {
		addRear(newNum);
	}

	//In the normal case, insert a node between two other nodes.
	//This is done using two pointers; one points to the node at
	//the node indicated. Then, a second node is declared and its elem
	//is set to the new num. The second node is placed between the pre-
	//ceeding and next; p->next points to the new, the new points to the
	//previously sequential node.
	else {
		I = I - 1;
		Node *p = Front;		//local ptr to front
		moveTo(I, p);			//move it to index of insertion point
		Node *a = new Node;		//declare new node
		a->Elem = newNum;		//fill it with elem in argument
		a->Next = p->Next;		//it's next is set to p->next
		p->Next = a;			//set p->next = a; a is inserted.
		Count++;				//increase count.
	}

}
// use moveTo to move local pointers. Be sure to comment to which node you are moving them.

//PURPOSE: A copy constructor that sets a new llist to properties of another llist.
//PARAMETER: Accepts an "Original" linked list.
llist::llist(const llist& Original) {
	this->Front = NULL;
	this->Rear = NULL;
	this->Count = 0;

	Node* P;  // local pointer for OtherOne
	P = Original.Front;
	while (P != NULL)  // a loop which repeats until you reach the end of OtherOne. 
	{
		this->addRear(P->Elem); //P’s element is added to this->
		P = P->Next; //Go to the next node in OtherOne   
	}
}

//PURPOSE: Overloaded = Operator.
//PARAMETER: This will be used to compare objects, such as the linked list.
//This is important because the equals operator usually only works on primitive types, but not objects.
llist& llist::operator=(const llist& OtherOne) {
	el_t x;
	// First make sure this-> and OtherOne are not the same object.
	// To do this, compare the pointers to the objects .

	if (&OtherOne != this)  // if not the same
	{
		// this-> object has to be emptied first.
		while (!this->isEmpty())
			this->deleteRear(x);
		// this-> object has to be built up by allocating new cells with OtherOne elements (**)
		Node* P;  // local pointer for OtherOne
		P = OtherOne.Front;
		while (P != NULL)  // a loop which repeats until you reach the end of OtherOne. 
		{
			this->addRear(P->Elem);    //P’s element is added to this->
			P = P->Next;               // Go to the next node in OtherOne   
		}
	}       
	return *this;    
	// Returns result by reference. This is where copy constructor comes in handy. Built-in operations can't return by reference.
}