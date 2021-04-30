#include <bits/stdc++.h>

using namespace std;

string toString(int n);
string fillstr(string str, int l);
string add(string a, string b);
string multiply(string a, string b);
void solve();


int main()
{
    solve();

    return 0;
}

void solve()
{
    int n;
    cin >> n;

    string s = "1";

    for(int i = 2; i <= n; i++)
    {
        s = multiply(s, toString(i));

    }
    cout << s << endl;
}

string multiply(string a, string b)
{
    int x, y, c;

    int al = a.size();
    int bl = b.size();

    string n = "";

    for(int i = al-1; i >= 0; i--)
    {
        c = 0;
        string s = "";

        for(int j = bl-1; j >= 0; j--)
        {
            x = ((a[i] - '0') * (b[j]- '0')) + c;

            s += x%10 + '0';
            c = x / 10;
        }
        if(c)
        {
            s += c%10 + '0';
            c = 0;
        }

        reverse(s.begin(), s.end());

        for(int j = i+1; j < al; j++)
        {
            s += "0";
        }

        //cout << s << endl;

        n = add(n, s);
    }

    return n;

}

string add(string a, string b)
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

string toString(int n)
{
    string s = "";

    while(n)
    {
        s += n%10 + '0';
        n /= 10;
    }

    reverse(s.begin(), s.end());
    //cout << s << endl;

    return s;
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
