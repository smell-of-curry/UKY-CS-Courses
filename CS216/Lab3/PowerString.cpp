/* 
 * File:   PowerString.cpp
 * Purpose: provide the definition of the PowerString class
 *
 * Author: (your name)
 *
 */
#include <iostream>
#include <stack>
#include "PowerString.h"

// initialize str with ini_str passing as a parameter
PowerString::PowerString(string ini_str)
{
    str = ini_str;
}

// return the current value of the private data member: str
string PowerString::getString() const
{
    return this->str;
}

// set the value of str to be the passed in parameter input_str
void PowerString::setString(string input_str)
{
    str = input_str;
}

// return a reverse string
// using a loop to implement
// Note that the private data member named str, has not been changed
string PowerString::rev_loop() const
{
   if (str.length() <= 1) 
       return this->str;

   string reversedStr = "";
   for (int i = str.length() - 1; i >= 0; i--)
       reversedStr += str[i];
   return reversedStr;
}

// return a reverse string
// using recursion to implement
// Note that the private data member named str, has not been changed
string PowerString::rev_recursion() const
{
    if (str.length() <= 1)
        return this->str;

    PowerString shorter(str.substr(1, str.length()-1));
    return shorter.rev_recursion() + str[0];
}

// return a reverse string
// using a stack to implement
// Note that the private data member named str, has not been changed
string PowerString::rev_stack() const
{
    if (str.length() <= 1)
        return str;

    stack<char> st;
    string reversedStr = "";

    // Push each character onto the stack
    for (char c : str) {
        st.push(c);
    }

    // Pop characters from the stack to build the reversed string
    while (!st.empty()) {
        reversedStr += st.top();
        st.pop();
    }

    return reversedStr;
}

// return true if str is a palindrome
// otherwise return false
// A palindrome is defined as a sequence of characters which reads the same backward as forward
// calling member function to  implement
// Note that the private data member named str, has not been changed
bool PowerString::isPalindrome() const
{
    return this->rev_loop() == str;
}

// return true if str is a palindrome
// otherwise return false
// A palindrome is defined as a sequence of characters which reads the same backward as forward
// using recursion to implement
// Note that the private data member named str, has not been changed
bool PowerString::isPalindrome_recursion() const
{
    if (str.length() <= 1)
        return true;

    PowerString shorter(str.substr(1, str.length()-2));
    bool firstPair = str[0] == str[str.length()-1];
    return (firstPair && shorter.isPalindrome_recursion());
}

// generate a palindrome with even number of characters
// by concatenate the original str with the reverse of str
// Note that the private data member named str, has not been changed
string PowerString::evenPalindrome() const
{
    string reversedStr = this->rev_stack();

    return str + reversedStr;    
}

// generate a palindrome with odd number of characters using recursion
// it is formed by the original str followed by the reverse of the str cutting away the last character from str
// e.g. if str is "abc", it returns "abcba"
// Note that the private data member named str, has not been changed
string PowerString::oddPalindrome() const
{
    string reversedStr = this->rev_stack();

    return str.substr(0, str.length()-1) + reversedStr;
}

// displays str followed by a new line marker
// to the standard output
void PowerString::print() const
{
    cout << str << "\n";
}
