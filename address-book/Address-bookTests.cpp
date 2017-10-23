#include "address-book.h"
#include <iostream>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("AddressBookEntry object does not share any state with copy"){
	int age = 21;
	string name = "Gift";
	Person person{name,age};
	string image_filename = "Face";
	AddressBookEntry entry{person, image_filename};
	AddressBookEntry entry_copy{entry};
	
	entry.setImageName("newFace");
	CHECK_FALSE(entry.getImageName() == entry_copy.getImageName());
	
	//The image pointers in entry and entry_copy share the same Image address
	//Changing one changes the other
}
/*
TEST_CASE("Assignment of AddressBookEntry object does not share any state "){
	int age = 21;
	string name = "Gift";
	Person person{name,age};
	string image_filename = "Face";
	AddressBookEntry entry{person, image_filename};
	AddressBookEntry entry_copy = entry;
	
	entry.setImageName("newFace");
	CHECK_FALSE(entry.getImageName() == entry_copy.getImageName());
	
	//The image pointers in entry and entry_copy share the same Image address
	//Changing one changes the other
}
*/