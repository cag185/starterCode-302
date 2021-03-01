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
  //detemine if postfix is valid
  if(isPost(postfix))
  {
    //get the length of the post expression
    int postLength = postfix.length();
    //create vector to hold values
    std::vector <char> PostfixVec;
    //loop through all characters of the postfix
    for(int i = 0; i <=postLength-1;i++)
    {
      //check to see if value is operator or operand
      char test = postfix[i];
      if(isoperator(test))
      {
        //we do have an operator
        //need to move operator two places earlier in the stack
        char op1 = PostfixVec[i-2];
       // std::cout << op1 << std::endl;
        char op2 = PostfixVec[i-1];
        //std::cout << op2 << std::endl;
        char sym = test;
        //std::cout << sym << std::endl;

        //erase values of postfix vec at i-2 and i-1
        PostfixVec.erase(PostfixVec.begin() + i-2);
        //pushback 1 value in case we have vec size of 0
        PostfixVec.push_back(sym);
        //std::cout << "Sym = " << PostfixVec[i-1] << std::endl;
        //erase other value
        PostfixVec.erase(PostfixVec.begin() + i-2); 
        //std::cout << "Sym = " << PostfixVec[i-2] << std::endl; // the operator is now 2 characters ahead
        //push_back values we want
        PostfixVec.push_back(op1);
        PostfixVec.push_back(op2);
        //std::cout << "PostVec at i " << PostfixVec[i-2] << std::endl;
        //std::cout << "PostVec at 1 " << PostfixVec[0] << std::endl;
        //std::cout << "PostVec at 2 " << PostfixVec[1] << std::endl;
        //std::cout << "PostVec at 3 " << PostfixVec[2] << std::endl;
      }
      else{
        //we do not have an operator
        //push into stack
        PostfixVec.push_back(test);
      }
    }
    for(int a  = 0; a <= postLength-1;a++)
    {
      //concatonate into one big string
      combination += PostfixVec[a];
    }
    prefix = combination;
  }
}
