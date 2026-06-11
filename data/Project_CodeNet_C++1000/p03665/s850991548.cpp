#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int odd, even;

ll dp[51][51];

ll bino(int n, int r)
{
    if (n < r || n < 0 || r < 0)
        return 0;
    
    ll &ret = dp[n][r];

    if (ret == -1)
        ret = bino(n - 1, r) + bino(n - 1, r - 1);

    return ret;
}

ll po(ll a, int b)
{
    if (!b)
        return 1;

    if (b == 1)
        return a;
    
    if (b & 1)
        return po(a, b - 1) * a;
    
    return po(a * a, b / 2);
}

int main()
{
    memset(dp, -1, sizeof dp);
    ios::sync_with_stdio(false); cin.tie(0);
    dp[0][0] = dp[1][0] = dp[1][0] = 1;

    int n, p;
    cin >> n >> p;

    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;

        if (x & 1)
            ++odd;
        else
            ++even;
    }

    int factor;
    ll res = 0;

    if (!p)
    {
        factor = 0;

        while (factor <= odd)
        {
            res += po(2, even) * bino(odd, factor);
            factor += 2;
        }
    }
    else
    {
        factor = 1;

        while (factor <= odd)
        {
            res += po(2, even) * bino(odd, factor);
            factor += 2;
        }    
    }

    cout << res;
}