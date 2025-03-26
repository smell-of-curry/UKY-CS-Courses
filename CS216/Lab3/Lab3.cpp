/*
 * Course: CS216-00x
 * Project: Lab Assignment 3
 * Purpose: To reverse each text line, say original,
 *          either from the specified file passing as the command line argument
 *          or from the user input
 *          and then decide if each of original, 
 *          is a palindrome or not
 *          if original is not a palindrome, demo how to create two palindromes 
 *          based on original (assume original contains n characters):
 *             (1) one contains 2n characters;
 *             (2) another one contains 2n-1 characters.
 ******PLEASE DO NOT CHANGE THIS FILE!******
 *
 */

#include <iostream>
#include <string>
#include <fstream>
#include "PowerString.h"

using namespace std;

int main(int argc, char** argv)
{
    const int NOCOMMLINEARG = 1;  //if running without command line argument
    const int COMMLINEARG = 2; //if running with one command line argument as the input filename
    
    // check if the number of command line arguments is correct
    if (argc < NOCOMMLINEARG || argc > COMMLINEARG)
    {
	    cout << "Usage: " << argv[0] << "  or " << argv[0] << " <filename>" << endl;
	    return 1;
    }
    // if there is no command line argument, read the standard input from the keyboard
    if (argc == NOCOMMLINEARG)
    {
   	    string original;
   	    cout << "Please input a string to watch its magic: " << endl;
   	    getline(cin, original);

        // Stop the loop when the user clicks Ctrl-d
   	    while (!cin.eof())
   	    {	
	   	    // create s PowerString object
            PowerString magic(original);
   		    cout << "The original string you type is: ";
            magic.print();
            cout << "Reverse of the string (using a loop): " << magic.rev_loop() << endl;
            cout << "Reverse of the string (using recursion): " << magic.rev_recursion() << endl;
            cout << "Reverse of the string (using a stack): " << magic.rev_stack() << endl << endl;
   		    
            // when the boolalpha format flag is set, bool values are represented as true or false, instead of integral values
            // for standard streams, the boolalpha flag is not set on initialization
            cout << boolalpha;
            cout << "Is \" " << magic.getString() << " \" a palindrome? " <<endl;
            // note that the following two answers should always be the same
            cout << "Calling member function to decide, the answer is: " << magic.isPalindrome() << endl;
            cout << "Using recursion to decide, the answer is: " << magic.isPalindrome_recursion() << endl;

            // if the string is not a palindrome, demo how to create two palindromes
            // (1) contains 2*n characters
            // (2) contains 2*n+1 characters
            if (!magic.isPalindrome())
            {
                cout << "I will demo to you how to create two palindromes:)" << endl;
                cout << "The palindrome with even number of characters: " << magic.evenPalindrome() << endl;
                cout << "The palindrome with odd number of characters: " << magic.oddPalindrome() << endl;
            }

            // asking for another input string...till the user clicks Ctrl-d
   		    cout << endl << endl;
            cout << "Please input a string to watch its magic: " << endl;
            getline(cin, original);
   	    }
   	    return 0;
    }
    // if there is one command line argument, read each line from the input file 
    else 
    {
	    string original;
	    ifstream inFile;
	    inFile.open(argv[1]);
	    if (!inFile.good())
	    {
		    cout <<"File open failure!" << endl;
		    return 1;
	    }
        //display each text lines from the file in original order, then followed by reversed order
        cout << "Display each text line from the file in original order, then followed by the reverse order: " << endl;
	    while (getline(inFile, original))     // it also contains eof check, avoid an extra line
        {
            PowerString magic(original);
            magic.print();
            cout << "--> ";
            cout << magic.rev_loop() << endl;
	    }
	    inFile.close();
	    return 0;
    }
}

