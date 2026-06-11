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
void chmax(t &a, u b)
{
    if (a < b)
        a = b;
}
template <class t, class u>
void chmin(t &a, u b)
{
    if (b < a)
        a = b;
}

int main()
{
    int n;
    cin >> n;
    int c[9] = {0};
    rep(i, n)
    {
        int a;
        cin >> a;
        if (a <= 399)
        {
            c[0] = 1;
        }
        else if (a <= 799)
        {
            c[1] = 1;
        }
        else if (a <= 1199)
        {
            c[2] = 1;
        }
        else if (a <= 1599)
        {
            c[3] = 1;
        }
        else if (a <= 1999)
        {
            c[4] = 1;
        }
        else if (a <= 2399)
        {
            c[5] = 1;
        }
        else if (a <= 2799)
        {
            c[6] = 1;
        }
        else if (a <= 3199)
        {
            c[7] = 1;
        }
        else
        {
            c[8]++;
        }
    }
    int cnt = 0;
    rep(i, 8)
    {
        if (c[i] == 1)
        {
            cnt++;
        }
    }
    cout << max(1, cnt) << " " << cnt + c[8] << endl;

    return 0;
}