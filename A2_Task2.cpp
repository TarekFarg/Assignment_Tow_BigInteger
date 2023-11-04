/*
* FCAI – OOP Programming – 2023 - Assignment 2
* Author1 and ID and Group: Mahmoud  20220317
* Author2 and ID and Group: Alaa    20230615
* Author3 and ID and Group: Tarek   20220171
*/

#include <iostream>
#include <string>
#include "BigReal.h"
using namespace std;
int main()
{
    //cout << "Hello, we will solve task to here\n" << std::endl;
    string n, m;
    cout << "Enter the first num(a) and the second num(b)  \n";
    cin >> n >> m;
    BigReal a(n);
    BigReal b(m);
    BigReal c;
    if (a == b)
    {

        cout << "equal" << endl;
    }

    else if (a > b)
    {
        cout << "a is bigger than b" << endl;
    }
    else if (a < b)
    {
        cout << "b is bigger than a" << endl;
    }

    c = a + b;
    cout << "The addition= " << c << endl;
    c = a - b;
    cout << "The subtraction: " << c << endl;



}
