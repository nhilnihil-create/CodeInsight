#include<bits/stdc++.h>

using namespace std;

#define int long long

const int N = 5005, mod = 1e9 + 7;
int n, m, dp[N][N];
string s;

int binpow(int _a, int _m) {
    int res = 1, now = _a;
    for (; _m; _m >>= 1, now = (now * now) % mod) if(_m & 1) res = (res * now) % mod;
    return res;
}

signed main () {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> s; m = s.size();
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            if(j) dp[i][j - 1] += dp[i - 1][j], dp[i][j - 1] %= mod;
            else dp[i][j] += dp[i - 1][j], dp[i][j] %= mod;
            dp[i][j + 1] += dp[i - 1][j] * 2; dp[i][j + 1] %= mod;
        }
    }

    cout << (dp[n][m] * binpow( binpow(2, m), mod - 2 )) % mod;

    return 0;
}
