#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N; cin >> N;
    vector<int> X(N); for (auto &x : X) cin >> x;
    int L; cin >> L;
    // dp[a][i] := a から 2^i 日で移動できる最大位置
    vector<vector<int>> dp(N, vector<int>(17));
    for (int a = 0; a < N; a++) {
        auto it = upper_bound(begin(X), end(X), X[a]+L) - 1;
        dp[a][0] = it - begin(X);
    }
    for (int i = 1; i <= 16; i++) {
        for (int a = 0; a < N; a++) {
            dp[a][i] = dp[dp[a][i-1]][i-1];
        }
    }
    int Q; cin >> Q;
    for (int i = 0; i < Q; i++) {
        int a, b; cin >> a >> b; a--, b--;
        if (a > b) swap(a, b);
        int ans = 0;
        for (int j = 16; j >= 0; j--) {
            if (dp[a][j] < b) {
                ans += 1 << j;
                a = dp[a][j];
            }
        }
        ans++;
        cout << ans << '\n';
    }
    return 0;
}