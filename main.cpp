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
    if(a == b)
    {
        cout << "equal" << endl;
    }

    else if (a > b)
    {
        cout << "a is bigger than b"<< endl;
    }
    else
    {
        cout << "b is bigger than a"<< endl;
    }

    c = a + b;
    cout << "The addition= "<<c<< endl;
    c = a - b;
    cout << "The subtraction: "<<c << endl;



}
