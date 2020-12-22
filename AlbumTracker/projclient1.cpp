//============================================
//KEEF'S ALBUM LIBRARY
//===========================================

#include "htable.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	htable T;  // generic hash table

	// All declarations happen outside switch
	string albumName;    // ** change
	string artist; // ** change and add more
	int yearReleased;		//year recorded is an int
	string genre;			//genre is string
	int rating;				//rating is an int; may convert to float later.
	el_t E;     // blank element
	el_t temp; //separate temp elem

	cout << "THNX FOR USING KEEF'S ALBUM LIBRARY" << endl;

	// File info declared outside switch
	string fname;
	string oname;
	cout << "If you have an import file, enter it here." << endl;
	cout << "Otherwise, type anything, then enter: ";
	cin >> fname;
	ifstream fin(fname.c_str(), ios::in);
	cout << "Name the file to save to (add .txt to the end!): ";
	cin >> oname;
	ofstream fout(oname.c_str(), ios::out);

	//Menu
	int ans = 0;
	while (ans != 7)
	{
		cout << endl;
		cout << "MENU------------------ :" << endl;
		cout << "1. Load Album List (only if you have an import file!)" << endl;
		cout << "2. Display All Albums" << endl;
		cout << "3. Search For An Album" << endl;
		cout << "4. Add A New Album" << endl;
		cout << "5. Delete An Album" << endl;
		cout << "6. Save Album List" << endl;
		cout << "7. Exit" << endl;
		cout << "==>";
		cin >> ans;
		cin.ignore(1000, '\n');
		
		switch (ans)
		{

		case 1: //load information from a file.
			while (getline(fin, albumName, '\t'))
			{
				getline(fin, artist, '\t');
				getline(fin, genre, '\t');
				fin >> yearReleased;
				fin >> rating;
				T.add(el_t(albumName, artist, genre, yearReleased, rating));
			}
			cout << "loaded data..." << endl;
			break;

		case 2:	//the weakest part of my assignment is the user interface. I want to improve this.
			cout << "Displaying All Albums..." << endl;
			cout << endl;
			T.displayTable();
			cout << endl;
			break;

		case 3: // search for an album
			cout << "Enter album to look for: ";
			getline(cin, albumName);
			E = T.find(albumName);
			if (E == el_t()) {
				cout << "Not found" << endl;
			}
			else {
				cout << "Found!" << endl;
				T.displaySingle(E);
				cout << "\n";
			}
			break;

		case 4: // add an album
			//this required me to use getline() and cin.ignore to accept the full length of user input.
			//cin.ignore() is needed to initiate a new line for some reason I'm not aware of yet.
			//therefore, I implemented another cout to accompany the empty space for some user friendliness.
			//cin >> would not allow for spaces to be recorded.
			//so, adding an album is a little more arduous than anticipated.
			cout << "Enter the album's name: " << endl; 
			getline(cin, albumName);
			cout << albumName << " accepted. Press Enter to continue...";
			cin.ignore(1000, '\n');

			cout << "Enter the artist's name: " << endl;
			getline(cin, artist);
			cout << artist << " accepted. Press Enter to continue...";
			cin.ignore(1000, '\n');

			cout << "Enter the genre of the album: " << endl;
			getline(cin, genre);
			cout << genre << " accepted. Press Enter to continue...";
			cin.ignore(1000, '\n');

			//The integers are easier to implement.
			cout << "Enter the year of release: " << endl;
			cin >> yearReleased;
			cout << yearReleased << " accepted." << endl;
			cout << "Enter your rating (1-5): " << endl;
			cin >> rating;
			cout << rating << " accepted." << endl;

			cout << "Adding to slot " << T.add(el_t(albumName, artist, genre, yearReleased, rating)) << "..." << endl;
			cout << "..." << endl;
			cout << "Success!" << endl;
			break;

		case 5: // delete an album
			cout << "Enter the album's name: ";
			getline(cin, albumName);	//get album's name
			temp = T.find(albumName);		//set a temp to the album
			//if temp.getkey is blank, no deletion will be attempted.
			if(temp.getkey() != ""){
				cout << "Deleting...: " << endl;
				T.deleteIt(temp, T);
				cout << "Success!" << endl;
			}
			else {
				cout << "No entry exists." << endl;
			}
			break;

		case 6: //send data to a new file.
			cout << "Sending data to " << oname << "..." << endl;
			T.saveTable(T, fout);
			cout << "Success!" << endl;
			break;

		case 7: //exit the program.
			cout << "Exiting Program. Thank You!" << endl;
			break;

		default: //for any other input
			cout << "I don't understand that input. Please enter a number from 1-7." << endl;
			break;
		}
	}// end of loop
	fin.close();
	fout.close();
}