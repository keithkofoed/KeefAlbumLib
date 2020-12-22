// CS311 Yoshii - el_t for HW8 Hash Table
// Element type of a list node is defined here
// el_t can be changed by the client to fit its needs
// ---------------------------------

#include <iostream>
#include <string>
//#include "slist.h"
using namespace std;

class el_t
{
private:  // these will change depending
		  // on the client needs
	string albumTitle;      // the key is the album title in char form
	string artist;		    // string artist
	int yearReleased;		//year recorded is an int
	string genre;			//genre is string
	int rating;				//rating is an int; may convert to float later.

public:

	el_t();  // to create a blank album object
	el_t(string, string); //secondary constructor strictly for the find function
	el_t(string, string, string, int, int); // fully initialized album

   // The following functions are available to
   // the htable class to be able to
   // use different el_t without modifying the code
	
	//getters make life so much easier.
	string getkey();
	string getArt();
	string getGen();
	int getYear();
	int getRate();

	void setkey(string); // only the key part can be accessed by the user of this class.


	// In linked list search,
	//    == is used to compare node elements
	// but what does it mean for this client to compare
	// node elements?  
	bool operator==(el_t);  // overload == for search
	bool operator!=(el_t);  // overload != for search

	// This overloads cout for the el_t object
	// This is a friend function since the receiver object is not el_t
	//I've updated this to << all elements. This helps save to .txt file.
	friend ostream& operator<<(ostream&, const el_t&);
};