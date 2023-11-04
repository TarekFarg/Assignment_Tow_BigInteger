//
// Created by Tarek on 10/27/2023.
//
#include <iostream>
#include <string>
using namespace std;

class BigReal
{
private:
    string MyNum;               // the full number
    string MyNum1;             // numbers before index point
    string MyNum2;            // numbers after index point
    int sign;                // -1 --> negative , 1 --> positive
    int len;                // length of MyNum(string)
    int index_point;       // the position of the decimal point
    void set_sign();
    void set_len();
    void set_index_point();
    string dif(string x1, string x2, string y1, string y2);
public:
    void set_num(string num);   // set MyNum
    string get_num();           // get MyNum
    bool operator > (BigReal SecNum);
    BigReal operator- (BigReal x);
    friend BigReal operator+ (BigReal a, BigReal b);
    BigReal();              // Default Constructor
    BigReal(string num);   // Parameterized Constructor
    friend ostream &operator<<( ostream &output, const BigReal &BR );
    friend bool operator == (BigReal& a, BigReal& b);
};
ostream &operator<<( ostream &output, const BigReal &BR );
bool operator == (BigReal& a, BigReal& b);
BigReal operator+ (BigReal a, BigReal b);
