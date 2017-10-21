// address_book.h
// class Image and AddressBookEntry declarations

#ifndef ADDRESS_BOOK_H
#define ADDRESS_BOOK_H

#include <string>
using std::string;
#include <memory>
using std::shared_ptr;

#include "Person.h"

//! A dummy class for image data.
class Image
{
public:
	Image(const string& image_data_filename):
		_image_filename{image_data_filename}
		{
			// read image file from disk ...
		};
	string name() {return _image_filename;};
	void name(string newname) { _image_filename = newname; }

private:
	string _image_filename;
	// data member to store image ...
};

// -------------------------------------------------------

//! This class represents an entry in a multimedia address book.
/*! It contains a person's information in the form of a Person object as well as an optional image.
	\author SP Levitt (based on Item 10 of More Effective C++ by S Meyers)
    \version 1.3
    \date    2012
*/
class AddressBookEntry
{
public:
	//! The image file is an optional parameter.
	/*! \param person a Person object containing the person's name and age
		\param image_filename a file containing an image of the person
	*/
	AddressBookEntry(const Person& person, const string& image_filename = "");
	// Relies on the compiler-provided copy constructor
	// Relies on the compiler-provided assignment operator

	string getImageName() const;
	void setImageName(string newname);
	Person getPerson() const { return _person; }
	void setPerson(Person person) { _person = person; }

private:
	Person _person;					//!< Contains the name and age of the person
	shared_ptr<Image> _image_ptr;	//!< A shared pointer to the person's image
};

#endif
