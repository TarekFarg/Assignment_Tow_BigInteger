//
// Created by Tarek on 10/27/2023.
//
#include <iostream>
#include <string>
using namespace std;


class BigReal {
private:
    int sign;                // -1 --> negative , 1 --> positive
    int len;                // length of MyNum(string)
    int index_point = -1;       // the position of the decimal point

    int get_index_point();
    void set_sign();
    void set_len();
    void set_index_point();
    string get_num();       // numbers before index point
    string get_nump();      // numbers after index point
public:
    string MyNum;              // numbers before index point
    string MyNump;            // numbers after index point
    void set_num(string num);
    int get_sign();
    BigReal();              // Default Constructor
    BigReal(string num);   // Parameterized Constructor

    friend bool operator == (BigReal& a, BigReal& b);
    friend BigReal operator+ (BigReal& a, BigReal& b);
    bool operator > (BigReal SecNum);
};

bool operator == (BigReal& a, BigReal& b);
BigReal operator+ (BigReal& a, BigReal& b);
