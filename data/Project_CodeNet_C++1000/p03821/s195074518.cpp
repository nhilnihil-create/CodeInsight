#include <bits/stdc++.h>
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; ++i)
#define repr(i, n) for (ll i = n - 1; i >= 0; --i)
const int MOD = 1000000007;
const ll INF = 10000000000;
using namespace std;

void solve(void)
{
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];
    ll ans = 0;
    repr(i, n)
    {
        ll x = ans + a[i];
        if (x % b[i] != 0)
            ans += b[i] - x % b[i];
    }
    cout << ans << endl;
}
int main(void)
{
    solve();
}