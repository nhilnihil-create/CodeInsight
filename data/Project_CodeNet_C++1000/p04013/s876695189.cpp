#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[51][51][2501];
int main()
{
    int n, a;
    cin >> n >> a;
    vector<int> x(n);
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
        max += x[i];
    }
    dp[0][0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            for (int k = 0; k <= max; k++)
            {
                if (k < x[i - 1] || j == 0)
                    dp[i][j][k] = dp[i - 1][j][k];
                else
                    dp[i][j][k] = dp[i - 1][j][k] + dp[i - 1][j - 1][k - x[i - 1]];
            }
        }
    }
    ll ans = 0;
    for (int i = 1; i * a <= max && i <= n; i++)
    {
        ans += dp[n][i][i * a];
    }
    cout << ans << endl;
}
