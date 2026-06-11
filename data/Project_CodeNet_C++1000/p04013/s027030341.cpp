#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N, A;
    cin >> N >> A;
    int x[N + 1];
    long long ans = 0;
    int M = 0;
    x[0] = 0;
    for (int i = 1; i <= N; ++i)
    {
        cin >> x[i];
        M = max(x[i], M);
    }
    int X = max(M, A);
    long long dp[N + 5][N + 5][N * X + 5] = {};
    dp[0][0][0] = 1;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            for (int s = 0; s <= N*X+1; ++s)
            {
                if (i >= 1 && s < x[i])
                {
                    dp[i][j][s] = dp[i - 1][j][s];
                }
                else if (i >= 1 && j >=1 && x[i] <= s)
                {
                    dp[i][j][s] = dp[i - 1][j][s] + dp[i - 1][j - 1][s - x[i]];
                }
                // cout << "From i: "<< " How many j:"<< j <<"個選ぶ。"<<" s: " << s <<" dp[i][j][s]: " << dp[i][j][s] << endl;
            }
        }
    }
    for(int i = 1; i <= N; ++i){
        ans += dp[N][i][i * A];
        // cout << dp[N][i][i * A] <<endl;
    }
    cout << ans << endl;
}

int main()
{
    solve();
    return 0;
}