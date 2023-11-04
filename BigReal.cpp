

#include "BigReal.h"
ostream& operator<<(ostream& output, const BigReal& BR)
{
    output << BR.MyNum;
    return output;
}

void BigReal::set_num(string num)
{
    MyNum = "0";
    bool valid = 1;
    for (int i = 0; i < num.size(); i++)
    {
        if (num[i] < '0' || num[i] > '9')
        {
            if (num[i] == '-' || num[i] == '+' || num[i] == '.')
                continue;
            else
                valid = 0;
        }
    }
    if (valid)
    {
        MyNum = num;
        set_sign();
        set_len();
        set_index_point();
    }
    else
        cout << "This is not valid number\nYou number now equal to the default value 0 \n ";
}

string BigReal::get_num()
{
    return MyNum;
}


void BigReal::set_sign()
{
    if (MyNum[0] == '-')
        sign = -1;
    else
        sign = 1;
}
bool BigReal::operator < (BigReal SecNum)
{
    BigReal n(MyNum);
    if (n == SecNum && n > SecNum)
        return false;

    else
        return true;
}
bool BigReal::operator>(BigReal SecNum)
{
    if (sign != SecNum.sign)
    {
        if (sign == 1)         // MyNum is pos and secNum is neg
            return true;
        else                    // MyNum is neg and secNum is pos
            return false;
    }
    if (sign == 1)             // MyNum and SecNum is pos
    {
        if (MyNum1.size() > SecNum.MyNum1.size())
            return true;
        else if (MyNum1.size() < SecNum.MyNum1.size())
            return false;
        else
        {
            int i = 0;
            while (i < MyNum1.size() && MyNum1[i] == SecNum.MyNum1[i]) i++;
            if (i < MyNum1.size())
                return (MyNum1[i] > SecNum.MyNum1[i]);
        }
        int i = 0;
        while (i < min(MyNum2.size(), SecNum.MyNum2.size()))
        {
            if (MyNum2[i] == SecNum.MyNum2[i])
                i++;
            else
                return (MyNum2[i] > SecNum.MyNum2[i]);
        }

        return (MyNum2.size() > SecNum.MyNum2.size());
    }
    else                    // MyNum and SecNum is neg
    {
        if (MyNum1.size() < SecNum.MyNum1.size())
            return true;
        else if (MyNum1.size() > SecNum.MyNum1.size())
            return false;
        else
        {
            int i = 0;
            while (i < MyNum1.size() && MyNum1[i] == SecNum.MyNum1[i]) i++;
            if (i < MyNum1.size())
                return (MyNum1[i] < SecNum.MyNum1[i]);
        }
        int i = 0;
        while (i < min(MyNum2.size(), SecNum.MyNum2.size()))
        {
            if (MyNum2[i] == SecNum.MyNum2[i])
                i++;
            else
                return (MyNum2[i] < SecNum.MyNum2[i]);
        }
        return (MyNum2.size() < SecNum.MyNum2.size());
    }
    return false;
}

void BigReal::set_len()
{
    len = MyNum.size();
}

void BigReal::set_index_point()
{
    for (int i = 0; i < len; ++i)
    {
        if (MyNum[i] == '-' || MyNum[i] == '+')
            continue;
        if (MyNum[i] == '.')
        {
            index_point = i;
            for (i = i + 1; i < len; i++)
            {
                MyNum2 += MyNum[i];
            }
        }
        else
            MyNum1 += MyNum[i];
    }
}

string BigReal::dif(string x1, string x2, string y1, string y2)
{
    string ans;
    if (x2.size())
    {
        for (int i = x2.size() - 1; i >= 0; i--)
        {
            if (x2[i] >= y2[i])
                ans = char(x2[i] - y2[i] + '0') + ans;
            else
            {
                int j = i - 1;
                while (j >= 0 && x2[j] == '0')
                {
                    x2[j] = '9';
                    j--;
                }
                if (j >= 0)
                {
                    x2[j] -= 1;
                }
                else
                {
                    j = 0;
                    while (j < x1.size() && x1[i] == '0')
                    {
                        x1[j] = '9';
                        j++;
                    }
                    x1[j] -= 1;
                }
                int d = x2[i] - y2[i] + 10;
                ans = char(d + '0') + ans;
            }
            if (i == 0)
                ans = '.' + ans;
        }
    }
    for (int i = x1.size() - 1; i >= 0; i--)
    {
        if (x1[i] >= y1[i])
            ans = char(x1[i] - y1[i] + '0') + ans;
        else
        {
            int j = i - 1;
            while (j >= 0 && x1[j] == '0')
            {
                x1[j] = '9';
                j--;
            }
            x1[j] -= 1;
            int d = x1[i] - y1[i] + 10;
            ans = char(d + '0') + ans;
        }
    }
    if (ans[0] == '0')
    {
        int i = 0;
        while (ans[i] == '0') i++;
        string temp;
        for (i = i; i < ans.size(); i++)
            temp += ans[i];
        ans = temp;
    }
    return ans;
}

BigReal::BigReal() :MyNum("")
{
    set_sign();
    set_len();
    set_index_point();
}
BigReal::BigReal(string num) 
{
    MyNum = "0";
    bool valid = 1;
    for (int i = 0; i < num.size(); i++)
    {
        if (num[i] < '0' || num[i] > '9')
        {
            if (num[i] == '-' || num[i] == '+' || num[i] == '.')
                continue;
            else
                valid = 0;
        }
    }
    if(valid)
    {
        MyNum = num;
        set_sign();
        set_len();
        set_index_point();
    }
    else
        cout << "This is not valid number\nYou number now equal to the default value 0 \n ";
}

bool operator == (BigReal& a, BigReal& b)
{
    if (a.len != b.len)
        return 0;

    if (a.MyNum1 == b.MyNum1 && a.MyNum2 == b.MyNum2 && a.sign == b.sign)
        return 1;

    return 0;
}


BigReal BigReal::operator- (BigReal y)
{
    BigReal x(MyNum);
    BigReal result;

    // make the len equal
    string x1 = x.MyNum1, x2 = x.MyNum2;
    string y1 = y.MyNum1, y2 = y.MyNum2;
    while (x1.size() > y1.size())
    {
        y1 = '0' + y1;
    }
    while (y1.size() > x1.size())
    {
        x1 = '0' + x1;
    }
    while (x2.size() > y2.size())
    {
        y2 += '0';
    }
    while (y2.size() > x2.size())
    {
        x2 += '0';
    }
    //..........
    string ans;
    if (x.sign == -1 && y.sign == -1) // y-x
    {
        x.sign = 1, y.sign = 1;
        //cout << 1 << endl;
        if (x > y)  // -(x-y)
        {
            ans = '-' + dif(x1, x2, y1, y2);
        }
        else        // y-x
        {
            ans = dif(y1, y2, x1, x2);
        }
        result.MyNum = ans;
    }
    else if (x.sign == -1 && y.sign == 1) // -(x+y)
    {
        //cout << 2 << endl;
        BigReal z = y;
        z.sign = -1;
        result = x + z;
    }
    else if (x.sign == 1 && y.sign == -1)  // x+y
    {
        //cout << 3 << endl;
        BigReal z = y;
        z.sign = 1;
        result = x + z;
    }
    else // x-y
    {
        x.sign = 1, y.sign = 1;
        //cout << 4 << endl;
        if (y > x) // -(y-x)
        {
            //cout << x1 << ' ' << x2 << ' ' << y1 << ' ' << y2 << endl;
            ans = '-' + dif(y1, y2, x1, x2);
        }
        else       // x-y
        {
            //cout << x1 << ' ' << x2 << ' ' << y1 << ' ' << y2 << endl;
            ans = dif(x1, x2, y1, y2);
        }
        result.MyNum = ans;
    }

    if (result.MyNum == "")
        result.MyNum = "0";
    return result;
}

BigReal operator+ (BigReal a, BigReal b)
{
    BigReal c;
    string result;
    int remain = 0, temp = 0;
    bool add = 0;

    if (a.sign == 1 && b.sign == -1)
    {
        BigReal z = b;
        z.sign = 1;
        c = a - z;
        return c;
    }


    if (a.sign == -1 && b.sign == 1)
    {
        BigReal z = b;
        z.sign = -1;
        c = a - z;
        return c;
    }

    if (b.MyNum2.length() < a.MyNum2.length())
    {
        string filled;
        filled += b.MyNum2;

        for (int i = 0; i < a.MyNum2.length() - b.MyNum2.length(); i++)
            filled += '0';

        b.MyNum2 = filled;

    }

    else if (a.MyNum2.length() < b.MyNum2.length())
    {
        string filled = "";
        filled += a.MyNum2;

        for (int i = 0; i < b.MyNum2.length() - a.MyNum2.length(); i++)
            filled += '0';

        a.MyNum2 = filled;
    }

    //cout << a.MyNump << " " << b.MyNump << endl;

    for (int i = a.MyNum2.length() - 1; i >= 0; i--)
    {
        temp = (a.MyNum2[i] - 48) + (b.MyNum2[i] - 48) + remain;

        if (temp >= 10)
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
        c.MyNum2 += result[i];
    }
    temp = 0;
    result = "";
    if (remain == 1)
    {
        add = 1;
    }

    remain = 0;
    temp = 0;
    result = "";


    if (b.MyNum1.length() < a.MyNum1.length())
    {
        string filled;

        for (int i = 0; i < a.MyNum1.length() - b.MyNum1.length(); i++)
            filled += '0';

        filled += b.MyNum1;

        b.MyNum1 = filled;
    }
    else if (a.MyNum1.length() < b.MyNum1.length())
    {
        string filled = "";
        //filled += '-';

        for (int i = 0; i < b.MyNum1.length() - a.MyNum1.length(); i++)
            filled += '0';

        for (int i = 0; i < a.MyNum1.length(); i++)
            filled += a.MyNum1[i];

        a.MyNum1 = filled;
    }

    //cout << a.MyNum << " " << a.MyNump << endl;
    //cout << b.MyNum << " " << b.MyNump << endl;


    for (int i = a.MyNum1.length() - 1; i >= 0; i--)
    {
        temp = (a.MyNum1[i] - 48) + (b.MyNum1[i] - 48) + remain;

        if (temp >= 10)
        {
            temp -= 10;
            remain = 1;
        }
        else
            remain = 0;

        result += (char)(temp + 48);

        temp = 0;
    }
    if (remain == 1)
        result += '1';
    //result += '-';
    for (int i = result.length() - 1; i >= 0; i--)
    {
        c.MyNum1 += result[i];
    }
    temp = 0;
    result = "";


    if (add)
    {
        remain = 1;
        for (int i = c.MyNum1.length() - 1; i >= 0; i--)
        {
            temp = (c.MyNum1[i] - 48) + remain;

            if (temp >= 10)
            {
                temp -= 10;
                remain = 1;
            }
            else
                remain = 0;

            result += (char)(temp + 48);

            temp = 0;
        }

        if (remain == 1)
            result += '1';

        //result += '-';
        c.MyNum1 = "";

        for (int i = result.length() - 1; i >= 0; i--)
            c.MyNum1 += result[i];
    }

    if (a.sign == 1 && b.sign == 1)
        c.sign = 1;
    else if (a.sign == -1 && b.sign == -1)
        c.sign = -1;


    //cout << c.MyNum1 << " " << c.MyNum2 << endl;

    c.MyNum = "-";

    if (c.sign == -1)
        c.MyNum += c.MyNum1;
    else
        c.MyNum = c.MyNum1;

    if (c.MyNum2.size())
        c.MyNum += '.' + c.MyNum2;
    return c;
}