/*
 * course: CS216-00x
 * Project: Demonstration of using GDB
 * Purpose: Example of dynamic allocaiton 
 *          Help students deeply understand the code      
 * Author: (your name)
 */
#include <iostream>

using namespace std;

int main() 
{
    const int HOWMANY = 10;
    string* myword;

    // create a loop for dynamic allocation in heap
    // and also give the initial values
    for (int i=0; i < HOWMANY; i++)
    {
        myword = new string("Hello, CS216");
    }
    cout << *myword << endl;

    return 0;
}
