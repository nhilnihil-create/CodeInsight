#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    int k = 0;
    cin >> s;
    if (s.length() == 2)
    {
        if (s[0] != s[1]) cout << "-1 -1";
        else cout << "1 2";
    }
    else
    {
        if (k == 0)
        {
            for (long unsigned i = 0; i < s.length() - 1; ++i)
            {
                if (s[i] == s[i + 1])
                {
                    k++;
                    cout << i + 1 << ' ' << i + 2;
                    break;
                }
            }
        }
        if (k == 0)
        {
            for (long unsigned i = 0; i < s.length() - 2; ++i)
            {
                if (s[i] == s[i + 2])
                {
                    k++;
                    cout << i + 1 << ' ' << i + 3;
                    break;
                }
            }
        }
        if (k == 0)
        {
            for (long unsigned i = s.length() - 1; i > 0; --i)
            {
                if (s[i] == s[i - 1])
                {
                    k++;
                    cout << i << ' ' << i + 1;
                    break;
                }
            }
        }
        if (k == 0)
        {
            for (long unsigned i = s.length() - 2; i > 1; --i)
            {
                if (s[i] == s[i - 2])
                {
                    k++;
                    cout << i - 1 << ' ' << i + 1;
                    break;
                }
            }
        }
        if (k == 0) cout << "-1 -1";
    }
}