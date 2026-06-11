#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
long long dp[5001][5001] = {};

long long powmod(long long x, long long n) {
    long long ret = 1;
    while(n > 0) {
        if(n & 1) ret = ret * x % MOD;
        x = x * x % MOD;
        n >>= 1;
    }
    return ret;
}

int main() {
    int N; string s;
    cin >> N >> s;

    dp[0][0] = 1;
    for(int n=0; n<N; ++n) {
        for(int x=0; x<N; ++x) {
            dp[n + 1][x + 1] = (dp[n + 1][x + 1] + 2 * dp[n][x]) % MOD;
            dp[n + 1][max(x - 1, 0)] = (dp[n + 1][max(x - 1, 0)] + dp[n][x]) % MOD;
        }
    }

    long long res = dp[N][s.size()] * powmod((MOD + 1) / 2, s.size()) % MOD;
    cout << res << endl;
}