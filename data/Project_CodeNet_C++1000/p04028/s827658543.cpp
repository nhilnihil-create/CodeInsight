#include <bits/stdc++.h>
#define WHOLE(v) (v).begin(), (v).end()
#define REV_WHOLE(v) (v).rbegin(), (v).rend()
using i64 = int64_t;
using namespace std;

const i64 MOD = 1e9 + 7;

// O(log a)
int64_t powmod(int64_t a, int64_t p) {
    int64_t value = 1;
    for (int64_t mul = a; p > 0; p >>= 1, mul = (mul * mul) % MOD) {
        if (p & 1) value = (value * mul) % MOD;
    }
    return value;
}

int64_t invmod(int64_t x) {
    return powmod(x, MOD - 2);
}

i64 dp[5001][5001];

int main() {
    int K, C;
    cin >> K;
    string s;
    cin >> s;
    C = s.size();
    i64 ans = 0;
    for(int k = 0; k <= K; k++) {
        for(int t = 0; t <= 5000; t++) {
            if(k == 0) {
                dp[k][t] = t == 0 ? 1 : 0;
            } else {
                dp[k][t] = 0;
                if(t < 5000) {
                    dp[k][t] += dp[k - 1][t + 1];
                }
                if(t > 0) {
                    dp[k][t] += 2 * dp[k - 1][t - 1];
                } else {
                    dp[k][t] += dp[k - 1][t];
                }
                dp[k][t] %= MOD;
            }
        }
    }
    ans = (dp[K][C] * invmod(powmod(2, C))) % MOD;
    cout << ans << endl;
    return 0;
}