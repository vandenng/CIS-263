#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <algorithm>
#include <string>
#include "catch.hpp"
#include "AUDS.h"

// Test cases take two parameters - the first is a test
// name and the second is a tag.
// This test merely checks that 1 is equal to 1.  It
// should always pass.  It is included here to show how
// to write test cases.


/*******************************************************************************************
 *Test that the AUDS can take any datatype, and that the consturcts correctly initialize
 *all variables.
 ******************************************************************************************/
TEST_CASE( "Constructor test", "[creation]" ){
	AUDS<int> a;
	AUDS<float> b;
	AUDS<AUDS<int> > c;
	CHECK( a.size() == 0 );
	CHECK( b.size() == 0 );
	CHECK( c.size() == 0 );
}

/*******************************************************************************************
 *Test to ensure the Cop & Swap Idiom workds correctly.
 ******************************************************************************************/
TEST_CASE( "Copy Swap Idiom test", "[inner]" ){
	AUDS<int> a;
	a.push(100);
	
	AUDS<int> b = a;
	CHECK( b.size() == 1 );
}

/*******************************************************************************************
 *Test to endsure the AUDS will correctly store data without having to resize.
 ******************************************************************************************/
TEST_CASE( "Initial Push Test", "[inner]" ){
	AUDS<int> a;

	for(int i = 0; i < 100; i++)
		a.push(i);

	CHECK( a.size() == 100 );
}

/*******************************************************************************************
 *Test to ensure the AUDS resizes correctly without having any issues with the data
 *location. It also tests the functionality of the pop() method.
 ******************************************************************************************/
TEST_CASE( "Resize test", "[inner]" ){
	AUDS<int> a;

	a.push(1);
	CHECK( a.pop() == 1 );
	
	a.push(2);
	CHECK( a.size() == 1 );
}

/*******************************************************************************************
 *Tests to ensure the pop() method will throw an error message if the AUDS is empty.
 ******************************************************************************************/
TEST_CASE( "Empty Pop Test", "[inner]" ){
	AUDS<char> a;
	CHECK_THROWS( a.pop() );
}

/*******************************************************************************************
 *Test to make sure the AUDS can push elemets & correctly resize without lossing any data.
 ******************************************************************************************/
TEST_CASE( "Push test", "[inner]" ){
	AUDS<int> a;
	for(int i=0; i<1000; i++){
		a.push(i);
	}
	CHECK( a.size() == 1000 );
}

/*******************************************************************************************
 *This will test the functionality of the pop() method by making sure all items returned
 *are random & non repeating. This also will ensure the AUDS will resize corrctly.
 ******************************************************************************************/
TEST_CASE( "Pop test", "[inner]" ){
	AUDS<std::string> s;
	for(int i=0; i<1000; i++){
		s.push("Item " + std::to_string(i));
	}
	for(int i=0; i<500; i++){
		std::cout << s.pop() << std::endl;
	}
	CHECK( s.size() == 500 );
}
