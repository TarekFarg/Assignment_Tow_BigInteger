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

    /*a.set_num("1111");
    b.set_num("1111");

    cout << a.len << " " << b.len << endl;*/


    if(a == b)
        cout << "equal" << endl;
    else
        cout << "not equal" << endl;

    


}
