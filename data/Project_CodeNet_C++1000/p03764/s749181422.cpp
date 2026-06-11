#include <bits/stdc++.h>

using namespace std;
#define int long long
const int N = 1e5 + 10, MOD = 1e9 + 7;
int dp[N], dp2[N], x[N], y[N];

int32_t main()
{
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i ++) cin >> x[i];
    for (int i = 0; i < m; i ++) cin >> y[i];
    sort(x, x + n);
    sort(y, y + m);
    for (int i = 1; i < n; i ++)
        dp[i] = (dp[i - 1] + (x[i] - x[i - 1]) * i) % MOD;
    for (int i = 1; i < n; i ++)
        dp[i] = (dp[i] + dp[i - 1]) % MOD;
    for (int i = 1; i < m; i ++)
        dp2[i] = (dp2[i - 1] + (y[i] - y[i - 1]) * i) % MOD;
    for (int i = 1; i < m; i ++)
        dp2[i] = (dp2[i] + dp2[i - 1]) % MOD;
    cout << ( dp[n - 1] * dp2[m - 1] ) % MOD << "\n";
}
