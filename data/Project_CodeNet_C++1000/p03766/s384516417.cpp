#include <bits/stdc++.h>
#define all(vec) vec.begin(), vec.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
constexpr ll INF = (1LL << 30) - 1LL;
constexpr ll LINF = (1LL << 60) - 1LL;
constexpr ll MOD = 1e9 + 7;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<ll> dp(n + 1), sum(n + 1);
    dp[0] = 1;
    sum[0] = 1;
    for (int i = 1; i <= n; i++) {
        dp[i] += dp[i - 1];
        if (i >= 3) {
            dp[i] += sum[i - 3];
        }
        dp[i] %= MOD;
        sum[i] = sum[i - 1] + dp[i] % MOD;
        // cout << i << " " << dp[i] << endl;
    }
    ll res = dp[n - 1] * n % MOD;
    if (n >= 2) {
        res += dp[n - 2] * (n - 1LL) % MOD * n % MOD;
    }
    res %= MOD;
    for (ll i = 0; i <= n - 3; i++) {
        res += dp[i] * (i + 2LL) % MOD;
        res += dp[i] * (n - 1LL) % MOD * (n - 1LL) % MOD;
        res %= MOD;
    }
    cout << res << endl;
}