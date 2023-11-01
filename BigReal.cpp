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

void BigReal::set_index_point() 
{
    string temp;
    for (int i = 0; i < len; ++i) 
    {   
        if(MyNum[i] == '-')
            continue;

        if(MyNum[i] != '.')  
            temp += MyNum[i];

        if (MyNum[i] == '.') {
            index_point = i;
            for (i = i + 1; i < len; i++) {
                MyNump += MyNum[i];
            }    
        }
    }
    MyNum = temp;
}

BigReal::BigReal() :MyNum("")
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

    if (a.MyNum == b.MyNum && a.MyNump == b.MyNump && a.sign == b.sign)
        return 1;

    return 0;
}

BigReal operator+ (BigReal &a, BigReal &b)
{
    BigReal c;
    string result;
    int remain = 0, temp = 0;
    bool add = 0, subt = 0;


    if(b.MyNump.length() < a.MyNump.length())
    {
        string filled;
        filled += b.MyNump;

        for (int i = 0; i < a.MyNump.length() - b.MyNump.length(); i++)
            filled += '0';
        
        b.MyNump = filled;
            
    }

    else if(a.MyNump.length() < b.MyNump.length())
    {
        string filled = "";
        filled += a.MyNump;

        for (int i = 0; i < b.MyNump.length() - a.MyNump.length(); i++)
            filled += '0';

        a.MyNump = filled;
    }

    //cout << a.MyNump << " " << b.MyNump << endl;

    for (int i = a.MyNump.length() - 1; i >= 0; i--)
    {
        temp = (a.MyNump[i]-48) + (b.MyNump[i]-48) + remain;

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
    for (int i = result.length() - 1; i >= 0; i--)
    {
        c.MyNump += result[i];
    }
    temp = 0; result = "";
    if(remain == 1)
    {
        add = 1;
    }

    remain = 0; temp = 0; result = "";


    if(b.MyNum.length() < a.MyNum.length())
    {
        string filled;

        for (int i = 0; i < a.MyNum.length() - b.MyNum.length(); i++)
            filled += '0';

        filled += b.MyNum;

        b.MyNum = filled;
    }
    else if(a.MyNum.length() < b.MyNum.length())
    {
        string filled = "";
        //filled += '-';

        for (int i = 0; i < b.MyNum.length() - a.MyNum.length(); i++)
            filled += '0';

        for(int i = 0; i < a.MyNum.length(); i++)
            filled += a.MyNum[i];

        a.MyNum = filled;
    }

    //cout << a.MyNum << " " << a.MyNump << endl;
    //cout << b.MyNum << " " << b.MyNump << endl;


    for (int i = a.MyNum.length() - 1; i >= 0; i--)
    {
        temp = (a.MyNum[i]-48) + (b.MyNum[i]-48) + remain;

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
    //result += '-';
    for (int i = result.length() - 1; i >= 0; i--)
    {
        c.MyNum += result[i];
    }
    temp = 0; result = "";


    if(add)
    {
        remain = 1;
        for (int i = c.MyNum.length() - 1; i >= 0; i--)
        {
            temp = (c.MyNum[i]-48) + remain;

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

        //result += '-';
        c.MyNum = "";

        for (int i = result.length() - 1; i >= 0; i--)
            c.MyNum += result[i];
    }

    if(a.sign == 1 && b.sign == 1)
        c.sign = 1;
    else if(a.sign == -1 && b.sign == -1)
        c.sign = -1;


    //cout << c.MyNum << " " << c.MyNump << endl;

    return c;
}
