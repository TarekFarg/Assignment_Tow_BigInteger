#include <iostream>
#include <string>
#include "BigReal.h"

using namespace std;
int main() 
{
    //cout << "Hello, we will solve task to here\n" << std::endl;
    
    string n, m;
    cin >> n >> m;


    BigReal a(n);
    BigReal b(m);
    BigReal c;

    //cout << a.MyNum << " " << a.MyNump << " " << a.get_sign() <<  endl;    
    //cout << b.MyNum << " " << b.MyNump << " " << b.get_sign() <<  endl; 


    /*if(a == b)
        cout << "equal" << endl;
    else
        cout << "not equal" << endl;*/

    
    if (a > b)
        cout << " a is bigger than b\n";
    else
        cout << "a is not bigger than b\n";
    

    /*c = a + b;

    if(c.get_sign() == -1)
        cout << '-';

    cout << c.MyNum << "." << c.MyNump << endl;   */          // mynum and mynump are public for experimenting untill << is overloaded



}
