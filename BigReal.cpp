//
// Created by Tarek on 10/27/2023.
//

#include "BigReal.h"

void BigReal::set_num(string num) {
    MyNum = num;
    set_len();
    set_index_point();

    /*if(index_point != -1)
    {
        for (int i = index_point+1; i < MyNum.length(); i++)
        {
            MyNumP += MyNum[i];
        }
        
        int i = MyNum.length();
        while(i != index_point)
        {
            MyNum.pop_back();
            i--;
        }
        //MyNum.pop_back();
    }*/
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


BigReal::BigReal()
{
    set_num("");
    set_len();
    set_index_point();
    set_sign();
}
BigReal::BigReal(string num)
{
    set_num(num);
    set_len();
    set_index_point();
    set_sign();
}

bool operator == (BigReal &a, BigReal &b)
{
    if(a.len != b.len)
        return 0;

    if(a.MyNum == b.MyNum)
        return 1;

    return 0;
}


BigReal operator- (BigReal &a, BigReal &b)
{
    
}
    
