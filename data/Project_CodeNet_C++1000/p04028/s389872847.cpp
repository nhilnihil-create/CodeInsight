#include <bits/stdc++.h>

using namespace std;
#define int long long
const int MAXN = 5040, MOD = 1e9 + 7;
int dp[MAXN][MAXN], DP[MAXN], a[MAXN], b[MAXN];

int mul(int a, int b) {return (a * b) % MOD;}
int sum(int a, int b) {return (a + b) % MOD;}

int32_t main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N, S; string s; cin >> N >> s;
    S = s.size();
    dp[0][0] = 1;
    for (int i = 1; i <= N; i ++) {
        dp[i][0] = dp[i - 1][1] * 2 + dp[i - 1][0];
        for (int j = 1; j <= N; j++) dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1] * 2) % MOD;
    }
    cout << dp[N][S] << "\n";
}
