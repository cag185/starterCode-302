#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"
#include "FindPalindrome.hpp"


// There should be at least one test per FindPalindrome method

//test for non allowable word
TEST_CASE( "Test FindPalindrome add a non-allowable word", "[FindPalindrome]" )
{
	INFO("Hint: add a single non-allowable word");
	FindPalindrome b;
	REQUIRE(!b.add("kayak1"));
}

//single add add valid word
TEST_CASE( "Add a single string", "[FindPalindrome]" )
{
	//create a palindrome
	FindPalindrome b;
	std::string correctString = "abc"; 
	std::string str2 = "abba";
	//for(int i = 0; i<correctString.size(); i++)
	//{
	//	std::cout <<  correctString[i]-0 << std::endl;
	//}
	REQUIRE(b.add(correctString)==true);
	REQUIRE(b.add(str2) == true);
}

//vector add --- add a valid string
TEST_CASE( "Add a vector of strings", "[FindPalindrome]" )
{
	//create a palindrome
	FindPalindrome b;
	//create a vector of words
	std::vector <std::string> vec1;
	vec1.push_back("Hello");
	vec1.push_back("world");
	REQUIRE(b.add(vec1)==true);
	
}

//cutTest1
TEST_CASE( "check cutTest1", "[FindPalindrome]" )
{
	//create a palindrome
	FindPalindrome b;
	//REQUIRE();
}

//cutTest2
TEST_CASE( "check CutTest2", "[FindPalindrome]" )
{
	//create a palindrome
	FindPalindrome b;
	//REQUIRE();
}

//toVector -- return vector of palindromes
TEST_CASE( "check if toVector returns the correct number", "[FindPalindrome]" )
{
	//create a palindrome
	FindPalindrome b;
	//REQUIRE();
}

//isPalindrome
TEST_CASE( "see if a string is a palindrome", "[FindPalindrome]" )
{
	//create a palindrome
	FindPalindrome b;
	//REQUIRE();
}

//recursive 
TEST_CASE( "test recursion", "[FindPalindrome]" )
{
	//create a palindrome
	FindPalindrome b;
	//REQUIRE();
}