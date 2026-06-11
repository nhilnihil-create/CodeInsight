#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

long long dp[1000010][2];

int main() {
    long long n; cin >> n;
    vector<long long> c(2*n+2, 0);
    long long ans = 0;
    dp[0][0] = 1;
    for (long long i = 0; i < n; i++) {
        c[i+1] = (c[i+1] + c[i]) % mod;
        dp[i+1][0] = (dp[i][0] + c[i+1]) % mod;
        dp[i+1][1] = dp[i][0];
        c[i+2] = (c[i+2] + dp[i][1]) % mod;
        c[i+n+1] = (c[i+n+1] + (mod - dp[i][1])) % mod;
        if (i > 0) ans += (dp[i][1] * ((n-1) * (n-1) % mod)) % mod;
        ans %= mod;
    }
    ans += dp[n][0] + dp[n][1] * (n-1) % mod;
    ans %= mod;
    for (long long i = n; i < 2*n+1; i++) {
        c[i+1] = (c[i+1] + c[i]) % mod;
        ans = (ans + c[i+1]) % mod;
    }
    cout << ans << endl;
    return 0;
}