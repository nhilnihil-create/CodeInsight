#include <iostream>
using namespace std;

const int MOD = 1000000007;
long long dp[1100000], sum[1100000];

int main () {
    long long n; cin >> n;
    dp[0] = 1; sum[1] = 1;
    dp[1] = 1; sum[2] = 2;
    for (long long i = 2; i < n; ++i) {
        dp[i] = (dp[i-1] + sum[i-2]) % MOD;
        sum[i+1] = sum[i] + dp[i];
    }
    long long res = 0;
    for (long long i = 0; i < n; ++i) {
        if (i <= n-3) res += dp[i] * (n * (n-2) % MOD+i+3) % MOD;
        else if (i == n-2) res += dp[i] * n % MOD * (n-1) % MOD;
        else if (i == n-1) res += dp[i] * n % MOD;
        res %= MOD;
    }
    cout << res << endl;
}