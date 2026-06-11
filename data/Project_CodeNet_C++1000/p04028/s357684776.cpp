#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); i++)

const ll mod = 1e9 + 7;

int main() {
    int n;
    string s;
    cin >> n >> s;
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (j - 1 >= 0) dp[i][j] += dp[i - 1][j - 1];
            if (j + 1 <= n) dp[i][j] += 2 * dp[i - 1][j + 1];
            if (j == 0) dp[i][j] += dp[i - 1][j];
            dp[i][j] %= mod;
        }
    }
    int m = s.size();
    cout << dp[n][m] << endl;
}