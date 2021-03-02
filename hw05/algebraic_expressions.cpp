#include <string>
using std::string;

#include <iostream>

#include <cctype> // for isalpha

#include <vector>

#include "algebraic_expressions.hpp"

bool isoperator(char ch) {
  return ((ch == '+') || (ch == '-') || (ch == '/') || (ch == '*'));
}

int endPost(string s, int last) {
  int first = 0;

  if ((first > last)) {
    return -1;
  }

  char ch = s[last];
  if (isalpha(ch)) {
    return last;
  } else {
    if (isoperator(ch)) {
      int lastEnd = endPost(s, last - 1);
      if (lastEnd > -1) {
        return endPost(s, lastEnd - 1);
      } else {
        return -1;
      }
    } else {
      return -1;
    }
  }
}

bool isPost(string s) {
  int firstChar = endPost(s, s.size() - 1);

  return (firstChar == 0);
}

void convert(string &postfix, string &prefix) {
std::string combination;
 
    //try to implement recursively
    //get the last element
    int postLength = postfix.size();
    char ch = postfix[postLength-1];

    postfix.pop_back();//remove the top value
    prefix.push_back(ch); // pushed ch into the end of prefix
    //check for operator
    if(isoperator(ch) == true)
    {
      std::string tempValue; //create an empty string 
      convert(postfix, tempValue); //call recursive function once
      convert(postfix,prefix);  //call again
      prefix+=tempValue;  //concattonate string with both parts
    }
    return;
}
