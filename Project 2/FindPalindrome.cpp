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
	//need to check if the candidateStringVec is empty
	if(candidateStringVector.empty() == true)
	{
		//create a long AF string and see if it is a palindrome, add to vec if so
		std::string longAFstring;
		std::string tempString;
		for(int a = 0; a <currentStringVector.size(); a++)
		{
			tempString =  currentStringVector.at(a);
			//make it lowercase
			convertToLowerCase(tempString);
			//add it to the long string
			longAFstring += tempString;
		}
		//now test the long string to see if its a palindrome
		if(isPalindrome(longAFstring)==true)
		{
			//add the palindrome to the vector
			//increase size
			PalindroneVec.push_back(currentStringVector); 
			numPal++;
		}
	}
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
	//AT SOME POINT WE NEED TO ADD THE FOUND PALINDROME TO A VECTOR OF VECTORS THATY HOLDS ORDERED PALINDROMES
	return true;
}

//------------------- PUBLIC CLASS METHODS -------------------------------------

FindPalindrome::FindPalindrome()
{
	//initialize stuff to 0
	sizeVec = 0;
	numPal = 0;
}

FindPalindrome::~FindPalindrome()
{
	// TODO need to implement this...
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
	//Need to look at each character in the sentence palindrome and see if more than one character shows up an odd amount of times
	int oddCheck = 0; //this value cannot be greater than 1 and still pass
	int letterCount = 0;

	//need to add all values of sentence vec into a single long af string
	std::string longAFString;
	std::string tempString;
	for(int i = 0; i <sentenceVec.size(); i++)
	{
		tempString =  stringVector.at(i);
		//make it lowercase
		convertToLowerCase(tempString);
		//add it to the long string
		longAFString += tempString;
	}
	//now string should be one long string 
	int sizeLongString = longAFString.length();
	//loop to check through the string
	for(int i = 0; i < sizeLongString; i++) // gets the character we want to compare
	{
		for(int j = 0; j <= sizeLongString; j++) // compares to all other values
		{
			//check string at i and compare with j
			if(longAFString[i] == longAFString[j])
				{
					letterCount++;
				}
			//now check if letterCount is evenly divisible by 2
			if(letterCount % 2 != 0) //we have an odd amount of same letters
			{
				oddCheck++;
			}
		}
	}
	//after we finish looping, check if oddCheck > 1
	if(oddCheck > 1)
	{
		return false;
	}
	return true;
}

bool FindPalindrome::cutTest2(const vector<string> & stringVector1,
                              const vector<string> & stringVector2)
{
	// TODO need to implement this...
	return false;
}

bool FindPalindrome::add(const string & value)
{
	// need to check if the word added is acceptable
	std::string tempStr;
	tempStr = value; convertToLowerCase(tempStr); // make the string lowercase
	//check if each letter is an ascii alphabetical
	for(int i = 0; i < value.size(); i++)
	{
		//check each letter
		if((int)value[i] < 65 || 90 < (int)value[i] < 97 || 122 < (int)value[i])
		{
			return false; //not within ascii range
		}
	}
	//create a vector to hold repeats
	std::vector <std::string> copyVec;
	int copies = 0;
	//also check if word is a repeat, which is not allowed
	//copy vector
	for(int i = 0; i < sentenceVec.size(); i ++)
	{
		copyVec.at(i) = sentenceVec.at(1); //copy value
		convertToLowerCase(copyVec.at(i)); //convert to lowercase
		if(tempStr == copyVec.at(i))
		{
			//increase copies value
			copies++;
			return false; //cannot add a value that already exists to the palindrome
		}
	}
	//now want to add the value to the vector of words to find palindromes
	sentenceVec.push_back(value); //stores teh value at the end of the vector
	//at this point, sentence should be okay to test for palindrome
	//check for palindrome
	recursiveFindPalindromes(sentenceVec, sentenceVec);  // should loop through all cominations of sentenceVec and determine how many palindromes we can make
	return true;
}

bool FindPalindrome::add(const vector<string> & stringVector)
{
	// TODO need to implement this...
	return false;
}

vector< vector<string> > FindPalindrome::toVector() const
{
	// TODO need to implement this...
	//vector<vector<string>> returnThingie;
	return PalindroneVec;
}

