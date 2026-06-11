#include <bits/stdc++.h>
using namespace std;
using Int = long long;
const Int MOD = 1000000007;
Int powmod(Int x, Int y) {
    if (y == 0) return 1;
    if (y % 2 == 0) return powmod(x*x%MOD, y/2);
    return x*powmod(x, y-1)%MOD;
}
Int inverse(Int x) {
    return powmod(x, MOD-2);
}
int solve(int N, const string& S) {
    vector<vector<int>> dp(N+1, vector<int>(N+1));
    dp[0][0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            dp[i+1][j+1] += dp[i][j] * 2;
            dp[i+1][j+1] %= MOD;
            dp[i+1][max(0, j-1)] += dp[i][j];
            dp[i+1][max(0, j-1)] %= MOD;
        }
    }
    return dp[N][S.size()] * powmod(inverse(2), S.size()) % MOD;
}
int main() {
    int N; cin >> N;
    string S; cin >> S;
    cout << solve(N, S) << '\n';
    return 0;
}
