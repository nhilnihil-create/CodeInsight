#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rng(i, a, b) for (int i = int(a); i < int(b); i++)
#define rep(i, b) rng(i, 0, b)
#define gnr(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define per(i, b) gnr(i, 0, b)
#define bg begin()
#define ed end()
#define all(x) x.bg, x.ed
#define vi vector<int>
template <class t, class u>
bool chmax(t &a, u b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class t, class u>
bool chmin(t &a, u b)
{
    if (b < a)
    {
        a = b;
        return true;
    }
    return false;
}

//ll mod = 1000000007;
ll mod = 998244353;

signed main()
{
    string s;
    cin >> s;
    bool ans = true;
    vi dp(s.size() + 1);
    dp[0] = 1;
    if (s.size() < 5)
    {
        cout << "NO" << endl;
        return 0;
    }
    for (int i = 5; i <= s.size(); i++)
    {
        if (dp[i - 5] == 1 && s.substr(i - 5, 5) == "dream")
        {
            dp[i] = 1;
        }
        if (dp[i - 5] == 1 && s.substr(i - 5, 5) == "erase")
        {
            dp[i] = 1;
        }
        if (i >= 6)
        {
            if (dp[i - 6] == 1 && s.substr(i - 6, 6) == "eraser")
            {
                dp[i] = 1;
            }
        }
        if (i >= 7)
        {
            if (dp[i - 7] == 1 && s.substr(i - 7, 7) == "dreamer")
            {
                dp[i] = 1;
            }
        }
    }
    if (dp[s.size()] == 1)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
    return 0;
}