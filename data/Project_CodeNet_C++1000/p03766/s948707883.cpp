# include <iostream>
using namespace std;
const int maxn=1e6+2;
int n;
long long dp[maxn], mod=1e9+7, sum=0;

int main()
{
    cin>>n;
    dp[1] = n;
    dp[2] = 1ll*n*n%mod;
    for(int i=3; i<=n; ++i)
    {
        sum = (sum + dp[i-3])%mod;
        dp[i] = (dp[i-1] + sum + 1ll*(n-1)*(n-1)%mod + n-i+2)%mod;
    }
    cout<<dp[n];
}