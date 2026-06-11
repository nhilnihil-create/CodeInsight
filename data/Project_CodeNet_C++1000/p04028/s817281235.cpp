#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 1000000007;

int main() {
    int n; cin >> n;
    string s; cin >> s;
    int k = (int)s.length();
    vector<vector<ll>> dp(n+1,vector<ll>(n+1,0ll));
    dp[0][0] = 1ll;
    for (int i = 0; i < n; i++) {
        ( dp[i+1][0] += dp[i][0] ) %= MOD;
        ( dp[i+1][1] += dp[i][0] ) %= MOD;
        for (int j = 1; j <= i; j++) {
            ( dp[i+1][j-1] += dp[i][j] * 2 ) %= MOD;
            ( dp[i+1][j+1] += dp[i][j] ) %= MOD;
        }
    }
    cout << dp[n][k] << endl;
    return 0;
}