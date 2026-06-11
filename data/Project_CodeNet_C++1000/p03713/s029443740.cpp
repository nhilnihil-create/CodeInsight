#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define _ << ' ' <<
using namespace std;
using ll = long long;

ll df(ll a, ll b)
{
    if (b < 0) a = -a, b = -b;
    return a / b - (a % b < 0);
}

ll dc(ll a, ll b)
{
    if (b < 0) a = -a, b = -b;
    return a / b + (a % b > 0);
}

int main()
{
    ll w, h;
    cin >> w >> h;
    ll sol = 2e9;
    ll s1 = (w / 3) * h;
    ll s2 = df(w - w / 3, 2) * h;
    ll s3 = dc(w - w / 3, 2) * h;
    ll mx = max(max(s1, s2), s3);
    ll mi = min(min(s1, s2), s3);
    sol = min(sol, mx - mi);
    s1 = (h / 3) * w;
    s2 = df(h - h / 3, 2) * w;
    s3 = dc(h - h / 3, 2) * w;
    mx = max(max(s1, s2), s3);
    mi = min(min(s1, s2), s3);
    sol = min(sol, mx - mi);
    for (ll i = 1; i < h; ++i)
    {
        ll s1 = i * w;
        ll s2 = df(w, 2) * (h - i);
        ll s3 = dc(w, 2) * (h - i);
        ll mx = max(max(s1, s2), s3);
        ll mi = min(min(s1, s2), s3);
        sol = min(sol, mx - mi);
    }
    for (ll i = 1; i < w; ++i)
    {
        ll s1 = i * h;
        ll s2 = df(h, 2) * (w - i);
        ll s3 = dc(h, 2) * (w - i);
        ll mx = max(max(s1, s2), s3);
        ll mi = min(min(s1, s2), s3);
        sol = min(sol, mx - mi);
    }
    cout << sol;
}
