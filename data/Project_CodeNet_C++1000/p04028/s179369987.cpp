#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MOD = 1e9 + 7;

int sum(int a, int b, int mod=MOD) {
    int c = a + b;
    if (c >= mod) {
        c -= mod;
    }

    return c;
}

inline int prod(int a, int b, int mod=MOD) {
    return (1LL * a * b) % mod;
}

int modpow(int base, int exp, int mod=MOD) {
    int res = 1;
    int cur = base;
    for (int p = 1; p <= exp; p <<= 1) {
        if (p & exp) {
            res = prod(res, cur, mod);
        }

        cur = prod(cur, cur, mod);
    }

    return res;
}

inline int inv(int x, int mod=MOD) {
    return modpow(x, mod - 2, mod);
}

constexpr int MAXN = 5003;
int m;
// how many ways are there to write j characters in exactly i steps?
int dp[2][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    string s;
    cin >> s;
    m = s.size();

    int row = 0;
    dp[row][0] = 1;

    for (int i = 1; i <= n; ++i) {
        row ^= 1;
        memset(dp[row], 0, sizeof(dp[row]));

        dp[row][0] = sum(dp[row][0], sum(dp[row ^ 1][0], dp[row ^ 1][1]));
        for (int j = 1; j <= n; ++j) {
            // add a character
            dp[row][j] = sum(dp[row][j], prod(2, dp[row ^ 1][j - 1]));

            // delete a character
            dp[row][j] = sum(dp[row][j], dp[row ^ 1][j + 1]);
        }
    }

    int res = prod(dp[row][m], inv(modpow(2, m)));
    cout << res << '\n';

    return 0;
}
