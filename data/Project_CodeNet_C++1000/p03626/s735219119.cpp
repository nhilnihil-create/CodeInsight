#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios :: sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; string s1, s2;
    cin >> n >> s1 >> s2;
    int dp[55][3][3];
    memset(dp, 0, sizeof(dp));
    int mod = 1000000007;
    for (int i = 0; i < n; ++ i) {
        for (int c1 = 0; c1 < 3; ++ c1) {
            for (int c2 = 0; c2 < 3; ++ c2) {
                if ((c1 == c2) ^ (s1[i] == s2[i])) continue;
                if (!i) dp[i][c1][c2] = 1;
                else
                for (int c3 = 0; c3 < 3; ++ c3) {
                    for (int c4 = 0; c4 < 3; ++ c4) {
                        if ((c1 == c3) ^ (s1[i] == s1[i - 1])) continue;
                        if ((c2 == c4) ^ (s2[i] == s2[i - 1])) continue;
                        (dp[i][c1][c2] += dp[i - 1][c3][c4]) %= mod;
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int c1 = 0; c1 < 3; ++ c1) {
        for (int c2 = 0; c2 < 3; ++ c2) {
            (ans += dp[n - 1][c1][c2]) %= mod;
        }
    }
    cout << ans << endl;
    return 0;
}
