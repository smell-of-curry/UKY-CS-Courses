/*
 * course: CS216-00x
 * Project: Demonstration of using GDB
 * Purpose: Example of using pointer as parameter       
 * Author: (your name)
 */
#include <iostream>

using namespace std;

void setint(int*, int);

int main() {
    int a;
    setint(&a, 10);
    cout << a << endl;
    int* b;
    setint(b, 20);
    cout << *b << endl;
    return 0;
}

void setint(int* ip, int i) {
    *ip = i;
}
