/*
 * course: CS216-00x
 * Project: Demonstration of using GDB
 * Purpose: Examples of passing an array into the function and check its behavior 
 *          Help students deeply understand "pointer-array duality law"      
 * Author: (your name)
 */
#include <iostream>

using namespace std;

void swap(int arr[], int size);

int main() 
{	
    int a[] = {215, 216};	
    cout << "a[0] = " << a[0] 	<< "; a[1] = " << a[1] << endl;  
    swap(a,2);	
    cout << "After calling swap function..." << endl;
    cout << "a[0] = " << a[0] 	<< "; a[1] = " << a[1] << endl;  
    return 0;
}

/*
 * Purpose: swap the firt two items stored in an array
 * @a array of integers: represent the array which needs to swap the first two items
 * @size int: how many data items in array named a
 * return void function
 */
void swap(int arr[], int size) 
{	
    if (size < 2) 
        return;	
    int temp = arr[0];	
    arr[0] = arr[1];	
    arr[1] = temp;
}
