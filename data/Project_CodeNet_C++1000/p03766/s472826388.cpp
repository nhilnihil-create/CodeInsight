#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = (ll)1e9 + 7;
const int N = (int)2e6 + 50;

int n;
ll dp[N][4];
ll add[N];
ll cumu = 0;

int main() {
    cin >> n;
    if(n == 1) return cout << 1 << endl, 0;
    dp[1][1] = 1;
    dp[1][2] = 1;
    ll res = 0;
    for(int i = 2; i <= n; i++) {
        cumu += add[i]; cumu %= mod;
        res += ((n - 1) * dp[i-1][2] % mod * (n - 1)) % mod;
        res %= mod;
        add[i + 1] += dp[i-1][2]; add[i + 1] %= mod;

        add[i + n] -= dp[i-1][2]; add[i + n] %= mod;

        dp[i][1] = (dp[i-1][1] + cumu) % mod;
        dp[i][2] = dp[i-1][1];
    }
    for(int i = n + 1; i <= 2 * n; i++) {
        cumu += add[i]; cumu %= mod;
        res += cumu;
        res %= mod;
    }
    res += dp[n][1] + dp[n][2] * (n - 1);
    res = (res % mod + mod) % mod;
    cout << res << endl;

}