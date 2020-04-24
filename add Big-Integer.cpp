#include <bits/stdc++.h>

using namespace std;

string fillstr(string str, int l);
string addstr(string a, string b);

int main()
{
    string a, b;

    while(cin >> a >> b)
    {
        cout << addstr(a, b) << endl;
    }

    return 0;
}


string addstr(string a, string b)
{
    string ans = "";
    int lena, lenb, i;

    lena = a.size();
    lenb = b.size();
    int c = 0, x, y, l;
    l = min(lena, lenb);

    if(lena < lenb)
    {
        a = fillstr(a, lenb-lena);
    }
    else
    {
        b = fillstr(b, lena-lenb);
    }

    l = a.size();

    for(i = l-1; i >= 0; i--)
    {
        x = (a[i] - '0') + (b[i] - '0') + c;
        c = x / 10;
        x = x % 10;

        ans += x + '0';
    }

    if(c)
    {
        ans += c + '0';
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

string fillstr(string str, int l)
{
    string x = "";
    for(int i = 0; i < l; i++)
    {
        x += "0";
    }
    return x+str;
}

