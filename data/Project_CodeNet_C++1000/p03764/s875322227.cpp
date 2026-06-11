#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

typedef long long ll;

const ll MOD = 1000000007;

int main()
{
    ll n, m;
    cin >> n >> m;

    vector<ll> xs(n);
    for (auto &v : xs) cin >> v;
    vector<ll> ys(m);
    for (auto &v : ys) cin >> v;

    ll ansX = 0;
    for (ll x = 0; x < n - 1; x++)
    {
        ll num = ((x + 1) * (n - 1 - x)) % MOD;
        ansX += (num * (xs[x + 1] - xs[x])) % MOD;
        ansX %= MOD;
    }

    ll ansY = 0;
    for (ll y = 0; y < m - 1; y++)
    {
        ll num = ((y + 1) * (m - 1 - y)) % MOD;
        ansY += (num * (ys[y + 1] - ys[y])) % MOD;
        ansY %= MOD;
    }
    
    cout << (ansX * ansY % MOD) << endl;
}