// address_book.cpp
// Implementation of the AddressBookEntry class
#include "address-book.h"
#include <memory>
using std::make_unique;
using std::make_shared;

// AddressBookEntry Constructor
AddressBookEntry::AddressBookEntry(	const Person& person,
								   const string& image_filename)
								   :_person(person)
{
	// dynamically allocate memory for the image
	if (image_filename != "") {
		// ignore (for now) what will happen if there is a memory allocation failure
        _image_ptr = make_unique<Image>(image_filename);
	}
}

string AddressBookEntry::getImageName() const
{
	if (_image_ptr != nullptr)
		return _image_ptr->name();
	else return "No image!";
}

void AddressBookEntry::setImageName(string newname)
{
	if (_image_ptr != nullptr) _image_ptr->name(newname);
}


AddressBookEntry::AddressBookEntry(const AddressBookEntry& rhs):
_person(rhs._person), _image_ptr{nullptr}
{
	if(rhs._image_ptr != nullptr)
		_image_ptr = make_unique<Image>(rhs._image_ptr->name());
}

void AddressBookEntry::swap(AddressBookEntry& temp){
	//swap person member
	unique_ptr<Person> p1 = make_unique<Person>(_person);
	unique_ptr<Person> p2 = make_unique<Person>(temp.getPerson());
	p1.swap(p2);
	_person = *p1;
	
	//swap image member
	if(temp._image_ptr != nullptr){
		string a = _image_ptr->name();
		string b = temp.getImageName();
		a.swap(b);
		_image_ptr = make_unique<Image>(a);
	} else {
		_image_ptr = nullptr;
	}
}

AddressBookEntry& AddressBookEntry::operator=(const AddressBookEntry& rhs){
	AddressBookEntry temp{rhs};
	swap(temp);
	return *this;
}