#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    ll sum = 0;
    rep(mask, (1 << n))
    {
        ll tmp = 0;
        rep(i, n)
        {
            if ((mask >> i) & 1)
            {
                tmp *= 10;
                tmp += s[i] - '0';
            }
            else
            {
                sum += tmp;
                tmp = 0;
            }
        }
        sum += tmp;
    }
    cout << sum << endl;
}