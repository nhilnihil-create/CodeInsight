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
    vector<ll> a(3 * n), f(3 * n);
    rep(i, 3 * n) cin >> a[i];
    sort(a.begin(), a.end());
    ll ans = 0;
    for (int i = 2; i <= 2 * n; i += 2)
        ans += a[3 * n - 1 + 1 - i];
    cout << ans << endl;
}
int main(void)
{
    solve();
}