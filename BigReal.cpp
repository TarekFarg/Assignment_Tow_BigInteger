//
// Created by Tarek on 10/27/2023.
//

#include "BigReal.h"

void BigReal::set_num(string num) {
    MyNum = num;
    set_len();
    
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
    BigReal c;
    string result;
    int remain = 0, temp = 0;

    if((a.MyNum[0] == '-' && b.MyNum[0] != '-'))
    {

        if(b.MyNum.length() < a.MyNum.length() - 1)
        {
            string filled;

            for (int i = 0; i < a.MyNum.length() - b.MyNum.length() - 1; i++)
            {
                filled += '0';
            }

            filled += b.MyNum;

            b.MyNum = filled;
            
        }
        else if(a.MyNum.length() - 1 < b.MyNum.length())
        {
            string filled = "";

            filled += '-';

            for (int i = 0; i < b.MyNum.length() - a.MyNum.length() + 1; i++)
            {
                filled += '0';
            }

            for(int i = 1; i < a.MyNum.length(); i++)
                filled += a.MyNum[i];

            a.MyNum = filled;
        }

        for (int i = a.MyNum.length() - 1; i > 0; i--)
        {
            temp = (a.MyNum[i]-48) + (b.MyNum[i-1]-48) + remain;

            if(temp >= 10)
            {
                temp -= 10;
                remain = 1;
            }
            else
                remain = 0;

            result += (char)(temp + 48);

            temp = 0;
        }
        
        if(remain == 1)
            result += '1';

        result += '-';
        
        for (int i = result.length() - 1; i >= 0; i--)
        {
            c.MyNum += result[i];
        }

        return c;
    }
    else if((a.MyNum[0] != '-' && b.MyNum[0] == '-'))
    {

        if(b.MyNum.length() - 1 < a.MyNum.length())
        {
            string filled;

            filled += '-';

            for (int i = 0; i < a.MyNum.length() - b.MyNum.length() + 1; i++)
            {
                filled += '0';
            }

            for(int i = 1; i < b.MyNum.length(); i++)
                filled += b.MyNum[i];

            //

            b.MyNum = filled;
            
        }
        else if(a.MyNum.length() < b.MyNum.length() - 1)
        {
            string filled = "";

            for (int i = 0; i < b.MyNum.length() - a.MyNum.length() - 1; i++)
            {
                filled += '0';
            }

            filled += a.MyNum;

            a.MyNum = filled;
        }


        for (int i = b.MyNum.length() - 1; i > 0; i--)
        {
            temp = (a.MyNum[i-1]-48) + (b.MyNum[i]-48) + remain;

            if(temp >= 10)
            {
                temp -= 10;
                remain = 1;
            }
            else
                remain = 0;

            result += (char)(temp + 48);

            temp = 0;
        }
        
        if(remain == 1)
            result += '1';

        result += '-';
        
        for (int i = result.length() - 1; i >= 0; i--)
        {
            c.MyNum += result[i];
        }

        return c;
    }
}
    
