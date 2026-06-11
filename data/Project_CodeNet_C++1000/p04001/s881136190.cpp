#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using P = pair<int, int>;
using ll = long long;

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    ll ans = 0;
    rep(bit, 1 << n - 1)
    {
        string t;
        rep(i, n - 1)
        {
            t += s[i];
            if ((bit >> i) & 1)
            {
                t += "+";
            }
        }
        t += s[n - 1];
        t += "+";
        ll sum = 0;
        rep(i, t.size())
        {
            if (t[i] == '+')
            {
                ans += sum;
                sum = 0;
            }
            else
            {
                sum *= 10;
                sum += t[i] - '0';
            }
        }
    }
    cout << ans << endl;
}

int main()
{
    solve();
    return 0;
}