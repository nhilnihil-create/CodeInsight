#include <bits/stdc++.h>
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; ++i)
const int MOD = 1000000007;
using namespace std;

void solve(void)
{
    ll a, b, c;
    cin >> a >> b >> c;
    if (a % 2 == 0 || b % 2 == 0 || c % 2 == 0)
        cout << 0 << endl;
    else
    {
        ll x = min(a * b, min(a * c, b * c));
        cout << x << endl;
    }
}
int main(void)
{
    solve();
}