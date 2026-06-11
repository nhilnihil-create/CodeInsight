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
    int n;
    cin >> n;
    vi a(n);
    vi b(n);
    rep(i, n)
    {

        cin >> a[i];
    }
    rep(i, n)
    {
        if (n % 2 == 0)
        {
            if (i + 1 <= n / 2)
            {
                cout << a[n - 1 - i * 2] << " ";
            }
            else
            {
                cout << a[2 * (i - n / 2)] << " ";
            }
        }
        else
        {
            if (i <= n / 2)
            {
                cout << a[n - 1 - i * 2] << " ";
            }
            else
            {
                cout << a[2 * (i - n / 2) - 1] << " ";
            }
        }
    }
    cout << endl;
    return 0;
}