# include <iostream>
# include <cmath>
# include <set>
# include <map>
# include <algorithm>

using namespace std;

int main()
{
    long long n, a;
    long long x[55];
    cin >> n >> a;
    long long dp[55][55][n*a+10];
    x[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> x[i];
    }
    sort(x, x + n + 1);
    for (int j = 0; j <= n; ++j)
    {
        for (int k = 0; k <= n; ++k)
        {
            for (int s = 0; s <= k*a; ++s)
            {
                if(j + k + s == 0)
                    dp[j][k][s] = 1;
                else if (j >= 1 && s < x[j])
                    dp[j][k][s] = dp[j-1][k][s];
                else if (j >= 1 && k >= 1 && s >= x[j])
                    dp[j][k][s] = dp[j-1][k][s] + dp[j-1][k-1][s - x[j]];
                else
                    dp[j][k][s] = 0;
            }
        }
    }
    long long ans = 0;
    for (int i = 1; i <= n; ++i)
        ans += dp[n][i][i*a];
    cout << ans;
}
