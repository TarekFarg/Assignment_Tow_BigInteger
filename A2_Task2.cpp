#include <iostream>
#include <string>
#include "BigReal.h"

using namespace std;
int main()
{
    //cout << "Hello, we will solve task to here\n" << std::endl;

    string n, m;
    cout << "Enter the first num and the second num  \n";
    cin >> n >> m;


    BigReal a(n);
    BigReal b(m);
    BigReal c;



    /*if(a == b)
        cout << "equal" << endl;
    else
        cout << "not equal" << endl;
*/

    c = a + b;
    cout << ' ' << a.get_num() << " + " << b.get_num() << " = " << c.get_num() << endl;

    /*
    if (a > b)
        cout << " a is bigger than b\n";
    else
        cout << "a is not bigger than b\n";
    */
}
