#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5005;
const int mod = 1e9+7;
int dp[N][N];
// breif solution 
signed main()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	int len = s.length();

	dp[0][0] = 1;
	for(int i=1;i<=n;i++)
	{
		dp[i][0] = ( dp[i-1][0] + dp[i-1][1] ) % mod;
		for(int j=1;j<=i;j++)
		{
			dp[i][j] = ( dp[i-1][j-1]*2 + dp[i-1][j+1] ) % mod;
		}
	}

	for(int i=1;i<=len;i++)
	{
		dp[n][len] = (dp[n][len] * (mod+1)/2) % mod;
	}
	cout<<dp[n][len];
}