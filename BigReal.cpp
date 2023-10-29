//
// Created by Tarek on 10/27/2023.
//

#include "BigReal.h"

void BigReal::set_num(string num) {
    MyNum = num;
}
string BigReal::get_num()
{
    return MyNum;
}

void BigReal::set_sign() {
    if (MyNum[0] == '-')
        sign = -1;
    else
        sign = 1;
}

int BigReal::get_sign() {
    return sign;
}

void BigReal::set_len() {
    len = MyNum.size();
}

void BigReal::set_index_point() {
    for (int i = 0; i < len; ++i) {
        if (MyNum[i] == '.') {
            index_point = i;
            break;
        }
    }
}

BigReal::BigReal() :MyNum("0")
{
    set_len();
    set_index_point();
    set_sign();
}
BigReal::BigReal(string num) :MyNum(num)
{
    set_len();
    set_index_point();
    set_sign();
}