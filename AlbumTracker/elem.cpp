//============================================
//ELEM FUNCTIONS
//===========================================

#include "elem.h"

// blank album object.
el_t::el_t()
{
	albumTitle = "";
	artist = "";
	yearReleased = -1;
	genre = "";
	rating = -1;
}

//secondary constructor that only takes a key and artist name.
//useful for the find function.
el_t::el_t(string akey, string aname)
{
	albumTitle = akey;
	artist = aname;
}

//fully initialized album object.
el_t::el_t(string akey, string aname, string agenre, int ayear, int arating)
{
	albumTitle = akey;
	artist = aname;
	yearReleased = ayear;
	genre = agenre;
	rating = arating;
}

//Getters make your life better; trust me on this one
string el_t::getkey()
{
	return albumTitle;
}

string el_t::getArt()
{
	return artist;
}

string el_t::getGen()
{
	return genre;
}

int el_t::getYear()
{
	return yearReleased;
}

int el_t::getRate()
{
	return rating;
}

//sets the key of the object called upon.
void el_t::setkey(string akey)
{
	albumTitle = akey;
}

// overload == for search based on the key part only
bool el_t::operator==(el_t OtherOne)
{
	if (albumTitle == OtherOne.albumTitle) return true; else return false;
}

//operator for unequivalence
bool el_t::operator!=(el_t OtherOne)
{
	if (albumTitle != OtherOne.albumTitle) return true; else return false;
}

// overload cout 
//this lets me cout elements & write elements to a file.
ostream& operator<<(ostream& os, const el_t& E)
{
	os << E.albumTitle << "\t" << E.artist << "\t" << E.genre << "\t" << E.yearReleased << "\t" << E.rating;
	return os;
}