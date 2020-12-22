//============================================
//ELEM HEADER
//===========================================

#include <iostream>
#include <string>
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
	
	//overloaded operators to make comparisons of objects easier
	bool operator==(el_t);  // overload == for search
	bool operator!=(el_t);  // overload != for search

	// This overloads cout for the el_t object
	// This is a friend function since the receiver object is not el_t
	//I've updated this to << all elements. This helps save to .txt file.
	friend ostream& operator<<(ostream&, const el_t&);
};