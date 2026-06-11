#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

bool check(string s)
{
    bool flag = true;
    for (char c : s)
    {
        if (c != s[0])
            flag = false;
    }
    return flag;
}

int main()
{
    string s;
    cin >> s;
    int m = s.size();
    for (char d = 'a'; d <= 'z'; d++)
    {
        string t = s;
        string _t = "";
        int count = 0;
        while (true)
        {
            if (check(t))
                break;
            for (int i = 0; i < t.size() - 1; i++)
            {
                if (t[i] == d || t[i + 1] == d)
                {
                    _t.push_back(d);
                }
                else
                {
                    _t.push_back(t[i]);
                }
            }
            count++;
            t = _t;
            _t = "";
        }
        m = min(count, m);
    }
    cout << m << endl;
}