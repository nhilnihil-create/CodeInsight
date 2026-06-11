#include <iostream>
#include <string>
#include <vector>

using namespace std;
constexpr int64_t MOD = 1'000'000'007;

template< typename T >
T mod_pow(T x, T n) {
    T ret = 1;
    while(n > 0) {
        if(n & 1) (ret *= x) %= MOD;
        (x *= x) %= MOD;
        n >>= 1;
    }
    return ret;
}

int64_t modinv(int64_t a) {
    int64_t b = MOD, u = 1, v = 0;
    while (b) {
        int64_t t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= MOD;
    if (u < 0) u += MOD;
    return u;
}

int main(void) {
    int N;
    string s;
    cin >> N >> s;

    vector< vector<int64_t> > dp(N+1, vector<int64_t>(N+2));
    dp[0][0] = 1;
    for(int i=1; i<=N; i++) {
        dp[i][0] = (dp[i-1][0] + dp[i-1][1]) % MOD;
        for(int j=1; j<=N; j++) {
            dp[i][j] = (2*dp[i-1][j-1] + dp[i-1][j+1]) % MOD;
        }
    }

    cout << (dp[N][s.size()] * modinv(mod_pow(2L, (int64_t)s.size()))) % MOD << endl;
    return 0;
}
