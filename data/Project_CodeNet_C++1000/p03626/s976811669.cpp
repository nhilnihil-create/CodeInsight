#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define sz(s) (int)s.size()

int dp[55][3][3];
const int MOD = 1000000007;

int main() {
    int n;
    string s, f;
    cin >> n >> s >> f;
    int start = 1;
    if (s[0] == f[0]) {
        rep(i, 0, 3) dp[0][i][i] = 1;
    } else {
        rep(i, 0, 3) rep(j, 0, 3) if (i != j) dp[1][i][j] = 1;
        start = 2;
    }
    for (int i = start; i < n;) {
        if (s[i] == f[i]) {
            if (s[i - 1] == f[i - 1]) {
                rep(c1, 0, 3) rep(c2, 0, 3) if (c1 != c2) {
                    (dp[i][c1][c1] += dp[i - 1][c2][c2]) %= MOD;
                }
            } else {
                rep(c, 0, 3)
                rep(c1, 0, 3) rep(c2, 0, 3) if (c != c1 && c != c2 && c1 != c2)
                    (dp[i][c][c] += dp[i - 1][c1][c2]) %= MOD;
            }
            ++i;
        } else {
            if (s[i - 1] == f[i - 1]) {
                rep(c1, 0, 3) rep(c2, 0, 3) rep(c, 0, 3) if (c1 != c2 && c1 != c && c2 != c)
                    (dp[i + 1][c1][c2] += dp[i - 1][c][c]) %= MOD;
            } else {
                rep(c1, 0, 3) rep(c2, 0, 3)
                rep(p1, 0, 3) rep(p2, 0, 3)
                if (c1 != p1 && c2 != p2 && c1 != c2 && p1 != p2)
                    (dp[i + 1][c1][c2] += dp[i - 1][p1][p2]) %= MOD;
            }
            i += 2;
        }
    }
    int ans = 0;
    if (s[n - 1] == f[n - 1]) {
        rep(c, 0, 3) (ans += dp[n - 1][c][c]) %= MOD;
    } else {
        rep(c1, 0, 3) rep(c2, 0, 3) (ans += dp[n - 1][c1][c2]) %= MOD;
    }
    cout << ans << '\n';
}