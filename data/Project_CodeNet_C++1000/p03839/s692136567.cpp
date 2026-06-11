#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(ll i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(ll i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(ll i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define len(x) ((ll)(x).length())

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // std::ifstream in("input.txt");
    // std::cin.rdbuf(in.rdbuf());
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    vector<ll> dp(n + 1, 0), dpz(n + 1, 0);
    rep(i, n) {
        dp[i + 1] = dp[i] + a[i];
        dpz[i + 1] = dpz[i] + ((a[i] > 0) ? a[i] : 0);
    }
    ll ans = 0;
    rep(i, n - k + 1) {
        ll val = dp[i + k] - dp[i];
        ll lsum = dpz[i];
        ll rsum = dpz[n] - dpz[i + k];
        ans = max(ans, val + lsum + rsum);
        ans = max(ans, lsum + rsum);
    }
    cout << ans << endl;
    return 0;
}
