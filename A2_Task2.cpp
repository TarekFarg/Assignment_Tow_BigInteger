#include <iostream>
#include <string>
#include "BigReal.h"

using namespace std;
int main() 
{
    //cout << "Hello, we will solve task to here\n" << std::endl;
    
    string n, m;
    cin >> n >> m;


    BigReal a;
    BigReal b;

    a.set_num(n);
    b.set_num(m);

    //cout << a->get_sign() << endl;

    if(a == b)
        cout << "equal" << endl;
    else
        cout << "not equal" << endl;

    


}
