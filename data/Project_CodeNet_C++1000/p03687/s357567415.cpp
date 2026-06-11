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

string change(string s, int n)
{
    string ret = "";
    rep(i, s.size() - 1)
    {
        if (s[i] == n || s[i + 1] == n)
        {
            ret.push_back(n);
        }
        else
        {
            ret.push_back(s[i]);
        }
    }
    return ret;
}
bool is_monochar(string s)
{
    int n = s[0];
    rep(i, s.size())
    {
        if (s[i] != n)
        {
            return false;
        }
    }
    return true;
}

signed main()
{
    string s;
    cin >> s;
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    int ans = 1000;
    for (auto &a : alphabet)
    {
        string ss = s;
        bool f = true;
        int cnt = 0;
        while (!is_monochar(ss))
        {
            cnt++;
            ss = change(ss, a);
        }
        chmin(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}