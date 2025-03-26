/*
 * course: CS216-00x
 * Project: Demonstration of using GDB
 * Purpose: Examples of recursive functions 
 *          Help students deeply understand the call stack      
 * Author: (your name)
 */
#include <iostream>

using namespace std;

string changeStr(string original);

int myfunction(int x, int n);

int main() 
{
    // check the first recursive function, named changeStr
    string input;
    cout << "Please input a string to be changed: ";
    getline(cin, input);

    cout << "The string you input is: " << input << endl;
    cout << "It has been changed into: " << changeStr(input) << endl;
    
    // check the second recursive function, named myfunction
    int x, n;
    cout << "Please input two POSITIVE integers: (x and n) ";
    cin >> x;
    cin >> n;
    cout << "Calling myfunction(x, n)...the result is: ";
    cout << myfunction(x,n) << endl;
    return 0;
}

string changeStr(string old) 
{
    // base case
    if (old.length() <= 1)
        return old + old;
    // recursive step
    string mid = changeStr(old.substr(1, old.length()-1));
    return old[0] + mid + old [0];
}

int myfunction(int x, int n)
{
    // base case
    if (n == 0) 
        return 1;	
    // recursive step
    return x * myfunction(x, n-1);
}
