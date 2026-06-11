#pragma GCC optimize ("O3")

#include <bits/stdc++.h>
#include <string>
#include <queue>

#define endl '\n'
#define int long long
    
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, a;
    cin >> n >> a;
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    int s = 0;
    for (int i = 0; i < n; i++) {
        s += x[i];
    }
    s = max(n*a, s);
    int dp[n + 1][s + 1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= s; j++) {
            dp[i][j] = 0;
        }
    }
    dp[0][0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = n; j > 0; j--) {
            for (int k = 0; k <= s; k++) {
                if (x[i] <= k) {
                    dp[j][k] += dp[j - 1][k - x[i]];
                }
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += dp[i][i*a];
    }
    cout << ans;
}