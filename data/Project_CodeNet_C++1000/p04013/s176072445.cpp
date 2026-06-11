#include <bits/stdc++.h>
using namespace std;
 
void solve()
{
    int n, a;
    cin >> n >> a;
    int y[n + 1];
    long long ans = 0;
    int m = 0;
    y[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> y[i];
        m = max(y[i], m);
    }
    int x = max(m, a);
    long long dp[n + 1][n + 1][n * x + 1] = {};
    dp[0][0][0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            for (int s = 0; s <= n * x + 1; ++s)
            {
                if (i >= 1 && s < y[i])
                    dp[i][j][s] = dp[i - 1][j][s];
                else if (i >= 1 && j >= 1 && y[i] <= s)
                    dp[i][j][s] = dp[i - 1][j][s] + dp[i - 1][j - 1][s - y[i]];
            }
        }
    }
    for(int i = 1; i <= n; ++i)
        ans += dp[n][i][i * a];
    cout << ans << endl;
}
 
int main()
{
    solve();
}