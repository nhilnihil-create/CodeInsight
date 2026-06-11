#include <bits/stdc++.h>
#define deg ASDASDASDSAD
using namespace std;

string ans;
int len;

void question(int type, string s)
{
    if(type == 0)
    {
        cout << "? " << s << '\n';
        cout.flush();
    }else
    {
        cout << "! " << s << '\n';
        cout.flush();
        exit (0);
    }
}

string intToString(long long x)
{
    string ans;
    while(x)
    {
        ans.push_back(x % 10 + '0');
        x /= 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int strigToInt(string x)
{
    int ans = 0;
    for(int i = 0; i < x.size(); ++i)
        ans = ans * 10 + x[i] - '0';
    return ans;
}

bool get()
{
    char q;
    cin >> q;
    return q == 'Y';
}

void checkZero() /// TODO
{
    for(int i = 1, cur = 1; i <= 10; ++i)
    {
        question(0, intToString(cur * 2));
        if(get())
        {
            question(1, intToString(cur));
            break;
        }
        cur *= 10;
    }
}

string goodQ(string s, char q)
{
    s.push_back(q);
    while(s.size() <= len + 1)
        s.push_back('0');
    return s;
}

string deg(string s)
{
    int cur = s.size() - 1;
    while(cur >= 0 && s[cur] == '0')
    {
        s[cur] = '9';
        --cur;
    }
    --s[cur];
    if(s[0] == '0')
        s.erase(0, 1);
    return s;
}

char get(int pos)
{
    char l = '0';
    char r = '9';
    if(pos == 1)
        l = '1';
    char res = '#';
    while(l <= r)
    {
        char mid = (l + r) / 2;
        string q;
        if(mid == '1')
        {
            if(pos == 1)
                q = goodQ(ans, '1');
            else
                q = deg(goodQ(ans, mid));
        }else
            q = deg(goodQ(ans, mid));

        question(0, q);
        if(!get())
        {
            res = mid;
            l = mid + 1;
        }else
            r = mid - 1;
    }
    /**
    if(res == '#')
        return res;

    if(res != '9')
    {
        string s = goodQ(ans, res + 1);

        question(0, deg(s));

        if(!get())
        {
            question(0, deg(s));
            if(get())
                return '9';
        }
    }*/

    return res;
}



int main()
{
//    ios_base :: sync_with_stdio(false);
//    cin.tie(NULL);

    len = 0;
    for(int i = 1, cur = 1; i <= 10; ++i)
    {
        question(0, intToString(cur));
        if(!get())
        {
            len = i - 1;
            break;
        }
        cur *= 10;
    }

    if(!len)
        checkZero();

    if(len == 1)
    {
        for(int i = 90; i >= 10; i -= 10)
        {
            question(0, intToString(i));
            if(!get())
                question(1, intToString(i / 10 + 1));
        }
        question(1, intToString(1));
    }

    for(int i = 1; i <= len; ++i)
    {
        char q = get(i);
        if(q == '#')
            break;
        else
            ans.push_back(q);
    }

    cout << "! ";
    cout << ans;
    for(int i = 0; i < len - ans.size(); ++i)
        cout << 0;
    cout << '\n';
    cout.flush();

    return 0;
}
