#include <string>
#include <vector>
#include <iostream>
#include <locale> 
#include "FindPalindrome.hpp"
#include <iostream>

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
		if(cutTest2(newCandidate, newCurrent)== false)
			return;
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
	//run clear
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
		for(int j = 0; j < sizeLongString; j++) // compares to all other values
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
	//need to create two small strings and two large strings
	std::string s1, s2, largeString, smallString;

	//make strings from vectors
	//s1 -- firstVec
	for(int i = 0; i <stringVector1.size(); i++)
	{
		s1 += stringVector1[i];
	}
	//s2 -- secondVec
	for(int i = 0; i < stringVector2.size(); i++)
	{
		s2+=stringVector2[i];
	}

	//need to convert both strings to lowercase
	convertToLowerCase(s1);
	convertToLowerCase(s2);

	//find the bigger string and store it in largeString
	if(s1.length() > s2.length())
	{
		largeString = s1;
		smallString = s2;
	}
	else
	{
		largeString = s2;
		smallString = s1;
	}

	//create temp arrays that hold the number of how many times each elements occur
	int temp1[26]; //smaller string
	int temp2[26]; //larger string

	//make sure the numbers in array are 0
	for(int i = 0; i <26; i++)
	{
		//make each index 0
		temp1[i] =0;
		temp2[i] =0;
	}

	//loop through and convert evey value in the array to its numerical representation and increase the number in that position of the alphabet array
	for(int i = 0; i < smallString.length(); i++)
	{
		temp1[smallString[i]-97]++; // increases everytime the letter at its alphabetical component is found
	}
	//repeat for other array
	for(int i = 0; i <largeString.length(); i++)
	{
		temp2[largeString[i]-97]++; // increases everytime the letter at its alphabetical component is found
	}
	
	//test to make sure that the smaller string has less of the same characters than larger string
	for(int i  = 0; i < 26; i++)
	{
		if(temp1[i] > temp2[i])
			return false; // the num in array1 is larger than num in array2 -- we DONT want this 
	}
	return true; //otherwise we gucci // double check // add this comment to make sure that github is workin
}

bool FindPalindrome::add(const string & value)
{
	// need to check if the word added is acceptable
	std::string tempStr;
	tempStr = value; 
	//convertToLowerCase(tempStr); // make the string lowercase
	//check if each letter is an ascii alphabetical
	for(int i = 0; i < value.size(); i++)
	{
		//check each letter
		//if((int)value[i] < 65 || 90 < ((int)value[i]) < 97 || 122 < ((int)value[i])) // use -97 to shift from char to ascii decimal
		if(tempStr[i]-0 < 97 || tempStr[i]-0 > 122 )
		{
			//return false
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
		copyVec.push_back(sentenceVec.at(i)); //copy value
		convertToLowerCase(copyVec.at(i)); //convert to lowercase
		if(tempStr == copyVec.at(i))
		{
			//increase copies value
			copies++;
		}
	}
	
	if(copies > 1)
	{
		//return false
		return false; //cannot add a value that already exists to the palindrome
	}
	//check with cutTest1 before sending to recursive test
	if(cutTest1(sentenceVec) == false)
	{
		//return false
		return true;
	}
	//now want to add the value to the vector of words to find palindromes
	sentenceVec.push_back(value); //stores the value at the end of the vector
	//at this point, sentence should be okay to test for palindrome
	//check for palindrome
	std::vector <std::string> emptyVec;
	recursiveFindPalindromes(sentenceVec, emptyVec);  // should loop through all cominations of sentenceVec and determine how many palindromes we can make
	//return true
	return true;
}

//This does the same thing as the first add test, but by entering a whole vector of words
bool FindPalindrome::add(const vector<string> & stringVector)
{
	// We have a vector full of strings, we need to test each string -- CANNOT RECURSIVELY USE THE STRING ADD FUNCTION
	//Test for allowable words
	//4 criteria
	std::string tempString;
	std::string caseSenString; //case sensitive string at each index of array

	//create a vector to hold repeats
	std::vector <std::string> copyVec;
	int copies = 0;

	//loop through each word in vector
	for(int i = 0; i <stringVector.size(); i++)
	{
		//test each word
		// need to check if the word in vector is acceptable
		caseSenString = stringVector.at(i); // gets the case sensitive version of the word
		tempString = stringVector.at(i); convertToLowerCase(tempString); // make the string lowercase

		//check if each letter in word is an ascii alphabetical
		for(int i = 0; i < tempString.size(); i++)
		{
			//check each letter
			if(tempString[i]-0 < 97 || tempString[i]-0> 122 )
			{
				//return false
				return false; //not within ascii range 
			}
		} 
	
		//also check if any word is a repeat, which is not allowed
		//copy vector
		//copies string in vector at each index
		copyVec.push_back(stringVector.at(i)); //copy value 
		convertToLowerCase(copyVec.at(i)); //convert to lowercase 
	}
	//need to compare each string in the vector with itself and every other string in vector
	//if the copy count is > 1 per word we have a repeat which is not permitted 
	for(int i = 0; i < copyVec.size(); i++) // controlling which word we are on
	{
		for(int j = 0; j <copyVec.size(); j++) //cycling through everyword one time per word
		{
			if(copyVec.at(j) == copyVec.at(i))
			{
				//increment copies count
				copies++; //expecting one copy, because we compare the item against the whole vector INCLUDING the index where itself is contained
			}
		}
		//check to see if there is an unallowable ( >1) number of copies
		if(copies >copyVec.size())
		{
			//return false
			return false; //cant have too many copies!
		}
	}
	
	
	//by this point, the words should all be allowable, and we need to send the vector to the reccursive test
	//create an empty vector
	std::vector <std::string> emptyVec;
	//pass the vectors to the recursive test if it passes the cutTest1
	if(cutTest1(stringVector) == false)
	{
		//return false
		return false; // doesn't go to recursion
	}
	//passes then pass to recursive
	recursiveFindPalindromes(stringVector, emptyVec); // issue
	return true; 
}

vector< vector<string> > FindPalindrome::toVector() const
{
	// Vector of vectors -- one vector is a Palindrome which is a vector of strings
	//vector<vector<string>> returnThingie;
	return PalindroneVec;
}

