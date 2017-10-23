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
	
	CHECK(entry.getImageName() == entry_copy.getImageName());
	entry.setImageName("newFace");
	CHECK(entry.getImageName() == entry_copy.getImageName());
}