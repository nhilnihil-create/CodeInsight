#include <bits/stdc++.h>

using namespace std;
long long dp[5005][5005];
long long mod = 1e9+7;
string s;

signed main()
{
    long long n;
    cin>>n>>s;

    dp[0][0] = 1;
    for(long long j=1;j<=n;j++)
    {
        dp[0][j] += (dp[0][j-1] + dp[1][j-1]*2 )%mod;
        dp[0][j] %= mod;
        for(long long i=1;i<=n;i++)
        {
            dp[i][j] += dp[i-1][j-1] + dp[i+1][j-1]*2 ;
            dp[i][j] %= mod;
        }
    }

    long long sz = s.length();
    cout<<dp[sz][n];
}
