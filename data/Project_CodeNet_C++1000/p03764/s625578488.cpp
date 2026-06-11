#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll MOD = 1e9+7;
ll add(ll a, ll b)
{
    return (a+b) % MOD;
}
int main()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> x(n);
    vector<ll> y(m);
    for(int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    for(int i = 0; i < m; i++)
    {
        cin >> y[i];
    }

    vector<ll> sx(n);
    vector<ll> gx(n);
    sx[0] = 0;
    gx[0] = 0;
    for(int i = 1; i < n; i++)
    {
        ll cand = x[i] - x[i-1];
        gx[i] = add(gx[i-1], i * cand % MOD);
        sx[i] = add(sx[i-1], gx[i]);
    }
    vector<ll> sy(m);
    vector<ll> gy(m);
    sy[0] = 0;
    gy[0] = 0;
    for(int i = 1; i < m; i++)
    {
        ll cand = y[i] - y[i-1];
        gy[i] = add(gy[i-1], i * cand % MOD);
        sy[i] = add(sy[i-1], gy[i]);
    }

    cout << sx[n-1] * sy[m-1] % MOD << endl;
}
