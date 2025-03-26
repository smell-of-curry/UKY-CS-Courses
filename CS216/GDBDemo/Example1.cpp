/*
 * course: CS216-00x
 * Project: Demonstration of using GDB
 * Purpose: Example of division operation      
 * Author: (your name)
 */
#include <iostream>
using namespace std;

int divint(int, int);

int main() {
    int x = 5, y = 2;
    cout << divint(x, y);
    x =3; y = 0;
    cout << divint(x, y);
    return 0;
}
int divint(int a, int b)
{
    return a / b;
}
