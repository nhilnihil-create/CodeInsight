#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool ask (ll x)
{
    cout << "? " << x << endl;
    char c;
    cin >> c;
    return c == 'Y';
}

int main()
{
    ios_base::sync_with_stdio(0);
    ll cp = 1;
    while (ask (cp) && cp < 2e12)
    {
        cp *= 10;
    }

    if (cp > 1e12)
    {
        ll cp = 9;
        while (true)
        {
            if (ask (cp))
            {
                cout << "! " << cp / 10 + 1 << "\n";
                return 0;
            }
            cp = 10 * cp + 9;
        }
    }
    ll rp = cp / 10;

    ll lo = rp, hi = cp - 1;
    while (lo < hi)
    {
        ll mid = (lo + hi) / 2;
        if (ask (10 * mid))
        {
            hi = mid;
        }
        else
        {
            lo = mid + 1;
        }
    }
    cout << "! " << lo << "\n";
}