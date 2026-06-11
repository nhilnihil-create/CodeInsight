#include <bits/stdc++.h>
#define ll long long int
#define mod_ceil(a, b) (a % b) ? a / b + 1 : a / b
using namespace std;

ll mod_abs(ll x)
{
    if (x < 0)
        return x * -1;
    return x;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll h, w, tmp, ans = LONG_LONG_MAX, x, y, z, mn, mx;
    cin >> h >> w;
    for (ll i = 1; i <= w; i++)
    {
        x = i * h;
        y = ((w - i) / 2) * h;
        z = ((w - i + 1) / 2) * h;
        mn = min(x, min(y, z));
        mx = max(x, max(y, z));
        ans = min(ans, mx - mn);
    }
    for (ll i = 1; i <= h; i++)
    {
        x = i * w;
        y = ((h - i) / 2) * w;
        z = ((h - i + 1) / 2) * w;
        mn = min(x, min(y, z));
        mx = max(x, max(y, z));
        ans = min(ans, mx - mn);
    }
    tmp = h / 2;
    for (ll i = 1; i <= w; i++)
    {
        x = i * h;
        y = (w - i) * tmp;
        z = (w - i) * (h - tmp);
        mn = min(x, min(y, z));
        mx = max(x, max(y, z));
        ans = min(ans, mx - mn);
    }
    tmp = w / 2;
    for (ll i = 1; i <= h; i++)
    {
        x = i * w;
        y = (h - i) * tmp;
        z = (h - i) * (w - tmp);
        mn = min(x, min(y, z));
        mx = max(x, max(y, z));
        ans = min(ans, mx - mn);
    }
    cout << ans << endl;
}