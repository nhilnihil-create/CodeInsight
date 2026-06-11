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

int main()
{
    int n;
    int b = -2;
    int c = 0;
    int ans = 0;
    cin >> n;
    rep(i, n)
    {
        int a;
        cin >> a;
        if (b == -2)
        {
            c = a;
            b = 0;
        }
        else if (b == 0)
        {
            if (a < c)
            {
                b = -1;
                c = a;
            }
            else if (c < a)
            {
                b = 1;
                c = a;
            }
        }
        else if (b == -1)
        {
            if (a <= c)
            {
                c = a;
            }
            else
            {
                b = 0;
                c = a;
                ans++;
            }
        }
        else if (b == 1)
        {
            if (a < c)
            {
                b = 0;
                c = a;
                ans++;
            }
            else
            {
                c = a;
            }
        }
    }
    cout << ans + 1 << endl;
    return 0;
}