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
    ll n, a, b;
    cin >> n >> a >> b;
    if (n == 1 && a != b)
    {
        cout << 0 << endl;
    }
    else if (n == 1)
    {
        cout << 1 << endl;
    }
    else
    {
        if (a > b)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << (b * (n - 1) + a) - (a * (n - 1) + b) + 1 << endl;
        }
    }
    return 0;
}