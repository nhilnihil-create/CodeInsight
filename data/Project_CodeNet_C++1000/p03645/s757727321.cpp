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

signed main()
{
    int n, m;
    cin >> n >> m;
    set<int> atox;
    set<int> xton;
    rep(i, m)
    {
        int a, b;
        cin >> a >> b;
        if (a == n)
        {
            xton.insert(b);
        }
        else if (b == n)
        {
            xton.insert(a);
        }
        if (a == 1)
        {
            atox.insert(b);
        }
        if (b == 1)
        {
            atox.insert(a);
        }
    }
    for (auto &i : atox)
    {
        if (xton.find(i) != xton.end())
        {
            cout << "POSSIBLE" << endl;
            return 0;
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}