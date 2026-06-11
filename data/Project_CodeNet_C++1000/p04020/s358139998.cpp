 #pragma GCC optimize("O3")
 #pragma GCC optimize("unroll-loops")
 #pragma GCC optimize("fast-math")
#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;

#define int long long
#define F first
#define S second
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

void accell() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
}
const int N = 1e5 + 5;

int dp[N][4];

signed main() {
    accell();
    int n;
    cin >> n;
    vector<int>a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < N; ++i)
        for (int j = 0; j <= 3; ++j)
            dp[i][j] = -1;
    dp[0][a[0] % 2] = a[0] / 2;
    if (a[0] >= 2)
        dp[0][a[0] % 2 + 2] = a[0] / 2 - 1;
    for (int i = 0; i + 1 < n; ++i) {
        for (int j = 0; j <= 3; ++j) {
            if (dp[i][j] == -1)
                continue;
            int c1 = a[i + 1] % 2;
            int v1 = a[i + 1] / 2;
            int cur1 = min(c1, j);
            c1 -= cur1;
            dp[i + 1][c1] = max(dp[i + 1][c1], dp[i][j] + cur1 + v1);
            if (a[i + 1] >= 2) {
                int c2 = a[i + 1] % 2 + 2;
                int v2 = v1 - 1;
                int cur2 = min(c2, j);
                c2 -= cur2;
                dp[i + 1][c2] = max(dp[i + 1][c2], dp[i][j] + cur2 + v2);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= 3; ++i)
        ans = max(ans, dp[n - 1][i]);
    cout << ans << '\n';
    return 0;
}
