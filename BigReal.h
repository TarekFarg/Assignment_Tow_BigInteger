//
// Created by Tarek on 10/27/2023.
// Modified by Mahmoud on 29/10/2023

#include <iostream>
#include <string>
using namespace std;


class BigReal {
private:
    string MyNum;
    int sign;      // -1 --> negative , 1 --> positive
    int index_point;       // the position of the decimal point
    void set_sign();
    void set_len();
    void set_index_point();
    int len;       // length of MyNum(string)
public:
    void set_num(string num);
    string get_num();
    int get_sign();
    BigReal();  // Default Constructor
    BigReal(string num);   // Parameterized Constructor

    friend bool operator == (BigReal &a, BigReal &b);
    
};

bool operator == (BigReal &a, BigReal &b);
