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

ll mod = 1000000007;

signed main()
{
    int n, m;
    cin >> n >> m;
    vector<string> as(n);
    vector<string> bs(m);
    rep(i, n)
    {
        cin >> as[i];
    }
    rep(i, m)
    {
        cin >> bs[i];
    }
    rep(i, n - m + 1)
    {
        rep(j, n - m + 1)
        {
            bool f = true;
            rep(k, m)
            {
                rep(l, m)
                {
                    if (as[i + k][j + l] != bs[k][l])
                    {
                        f = false;
                        break;
                    }
                }
            }
            if (f)
            {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}