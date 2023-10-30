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

string BigReal::get_nump()
{
    return MyNump;
}

int BigReal::get_index_point()
{
    return index_point;
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

bool BigReal::operator>(BigReal SecNum)
{
    if (sign != SecNum.sign)
    {
        if (sign == 1 )         // MyNum is pos and secNum is neg
            return true;
        else                    // MyNum is neg and secNum is pos
            return false;
    }
    if (sign == 1 )             // MyNum and SecNum is pos 
    {
        if (MyNum > SecNum.MyNum)
            return true;
        else if (MyNum < SecNum.MyNum)
            return false;
        else if (MyNump > SecNum.MyNump)
            return true;
        return false;  
    }
    else                    // MyNum and SecNum is neg
    {
        if (MyNum < SecNum.MyNum)
            return true;
        else if (MyNum > SecNum.MyNum)
            return false;
        else if (MyNump < SecNum.MyNump)
            return true;
        return false;
    }
    return false;
}

void BigReal::set_len() {
    len = MyNum.size();
}

void BigReal::set_index_point() {
    string temp;
    for (int i = 0; i < len; ++i) {
        if (MyNum[i] == '-' || MyNum[i] == '+')
            continue;
        temp += MyNum[i];
        if (MyNum[i] == '.') {
            index_point = i;
            for (i = i; i < len; i++) {
                MyNump += MyNum[i];
            }    
        }
    }
    MyNum = temp;
}

BigReal::BigReal() :MyNum("0")
{
    set_sign();
    set_len();
    set_index_point();
}
BigReal::BigReal(string num) :MyNum(num)
{
    set_sign();
    set_len();
    set_index_point();
}

bool operator == (BigReal& a, BigReal& b)
{
    if (a.len != b.len)
        return 0;

    if (a.MyNum == b.MyNum)
        return 1;

    return 0;
}


BigReal operator- (BigReal& a, BigReal& b)
{
    return BigReal();
}