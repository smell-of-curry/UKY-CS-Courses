/*
 * course: CS216-00x
 * Project: Demonstration of using GDB
 * Purpose: Example of dynamic allocation 
 *          Help students deeply understand the code      
 * Author: (your name)
 */
#include <iostream>

using namespace std;

int main() 
{
    const int CAPACITY = 20;
    const int HOWMANY = 10;

    string* myword[CAPACITY];
    
    // create a loop to assign the initial value
    // to the dynamically allocated boxes in heap
    for (int i=0; i < HOWMANY; i++)
    {
        myword[i] = new string("Hello, CS216");
    }

    cout << *myword[HOWMANY] << endl;
   
    // avoid memory leak
    for (int i = 0; i < HOWMANY; i++)
        delete myword[i];

    return 0;
}
