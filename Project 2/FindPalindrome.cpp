#include <string>
#include <vector>
#include <iostream>
#include <locale> 
#include "FindPalindrome.hpp"

using namespace std;

//------------------- HELPER FUNCTIONS -----------------------------------------

// non-class helper functions go here, should be declared as "static" so that
// their scope is limited

// helper function to convert string to lower case
static void convertToLowerCase(string & value)
{
	locale loc;
	for (int i=0; i<value.size(); i++) {
		value[i] = tolower(value[i],loc);
	}
}

//------------------- PRIVATE CLASS METHODS ------------------------------------

// private recursive function. Must use this signature!
void FindPalindrome::recursiveFindPalindromes(vector<string>
        candidateStringVector, vector<string> currentStringVector)
{
	//make a loop that is run as many times as candidateStringVector is long
	for(int  i = 0; i < candidateStringVector.size(); i++)
	{
		//create new temporary vectors to hold candidate and current vectors 
		//copies of candidateStringVector and currentStringVector
		std::vector<std::string> newCandidate(candidateStringVector);
		std::vector<std::string> newCurrent(currentStringVector);

		//remove a word from the candidate vector
		newCandidate.erase(newCandidate.begin() + i-1);
		//add the word to the current vector at the end
		newCurrent.push_back(candidateStringVector.at(i));

		//run the isPalindrome tests
		//need to make all entries in vector into one string
		std::string longAFString;
		for( int j = 0; j < currentStringVector.size(); j++)
		{
			//loop through vector and make one long string from all values in vector
			//convert each element into lowecase and append the long string
			std::string TempStr = currentStringVector.at(j);
			convertToLowerCase(TempStr); // make lower case
			longAFString = longAFString + TempStr;
		}
		//giant string should be concattonated now and ready to pass to isPalidrome function
		if(isPalindrome(longAFString) == true)
		{
			//increase the numPalandrones
			numPal++;
		}

		//call the function recursively
		recursiveFindPalindromes(newCandidate, newCurrent); 
	}
	return;
}

// private function to determine if a string is a palindrome (given, you
// may change this if you want)
bool FindPalindrome::isPalindrome(string currentString) const
{
	locale loc;
	// make sure that the string is lower case...
	convertToLowerCase(currentString);
	// see if the characters are symmetric...
	int stringLength = currentString.size();
	for (int i=0; i<stringLength/2; i++) {
		if (currentString[i] != currentString[stringLength - i - 1]) {
			return false;
		}
	}
	return true;
}

//------------------- PUBLIC CLASS METHODS -------------------------------------

FindPalindrome::FindPalindrome()
{
	//initailize the size of the vector to zero
	sizeVec = 0;
	//initialize the number of palindrones to 0
	numPal = 0;
	
}

FindPalindrome::~FindPalindrome()
{
	//free memory
	clear();
}

int FindPalindrome::number() const
{
	// return the number of palindrones
	return numPal;
}

void FindPalindrome::clear()
{
	// set the number of sentence palindromes to 0
	numPal = 0;
	//clear the vector of words
	sentenceVec.clear(); // clear is the built in vector method
	//clear the vector of palindrones
	PalindroneVec.clear(); // clear is the built in vector method

}

bool FindPalindrome::cutTest1(const vector<string> & stringVector)
{
	// TODO need to implement this...
	return false;
}

bool FindPalindrome::cutTest2(const vector<string> & stringVector1,
                              const vector<string> & stringVector2)
{
	// TODO need to implement this...
	return false;
}

bool FindPalindrome::add(const string & value) // implement recursive function to work
{
	// need to check if the word added is acceptable
	std::string tempStr;
	tempStr = convertToLowerCase(value); // make the string lowercase
	//check if each letter is an ascii alphabetical
	for(int i = 0; i < value.size(); i++)
	{
		//check each letter
		if((int)value(i) < 65 || 90 < (int)value(i) < 97 || 122 < (int)value(i))
		{
			return false; //not within ascii range
		}
	}
	//also check if word is a repeat, which is not allowed
	for(int i = 0; i < sentenceVec.size(); i ++)
	{
		
	}
	//at this point, word should be okay to test for palindrome
	//check for palindrome
	if(isPalindrome(tempStr) == true)
	{
		//is a palindrone, add to vector

	}

	return true;
}

bool FindPalindrome::add(const vector<string> & stringVector) // implement recursive function to work
{
	// TODO need to implement this...
	return false;
}

//return vector that holds palindrones
vector< vector<string> > FindPalindrome::toVector() const
{
	// TODO need to implement this...
	//vector<vector<string>> returnThingie;
	return PalindroneVec;
}

