#include <bits/stdc++.h>
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; ++i)
const int MOD = 1000000007;
const ll INF = 10000000000;
using namespace std;

void solve(void)
{
    ll x, y;
    cin >> x >> y;
    ll a = abs(-x - y) + 1;
    ll b = INF;
    if (x < y)
        b = abs(x - y);
    ll c = abs(x - y) + 2;
    cout << min(a, min(b, c)) << endl;
}
int main(void)
{
    solve();
}