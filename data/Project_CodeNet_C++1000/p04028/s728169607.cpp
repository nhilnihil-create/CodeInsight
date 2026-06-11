#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vii vector<pair<int, int> >
#define fi first
#define se second
#define int long long
const int mod = 1e9+7;
int dp[5005][5005];
int binpow(int a, int b)
{
	if(!b) return 1;
	int t=binpow(a, b/2);
	if(b&1) return t*t%mod*a%mod;
	return t*t%mod;
}
int inv(int x)
{
	return binpow(x, mod-2);
}
signed main()
{
	int n; string s;
	cin>>n>>s;
	dp[0][0]=1;
	for(int i=1; i<=n; i++)
	{
		for(int j=0; j<=n; j++)
		{
			dp[i][j]+=dp[i-1][max(j - 1, 0ll)];
			dp[i][j]+=2*dp[i-1][j+1];
			dp[i][j]%=mod;
		}
	}
	int ans = dp[n][s.length()];
	cout<<ans; 
}
