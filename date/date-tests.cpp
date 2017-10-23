#include "date.h"
#include <iostream>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("no state shared between copy and original date object"){
	Date solstice{22,Month::December,2017};
	Date solstice_copy{solstice};
	
	CHECK(solstice == solstice_copy);
}