#include<bits/stdc++.h>
using namespace std;
int n,ww;
int w[105],v[105];
int dp[110][110][305];
int w1;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>ww;
	for(int i=1;i<=n;i++)
	{
		cin>>w[i]>>v[i];
	}
	w1=w[1];
	
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			for(int mov=0;mov<=3*i;mov++)
			{
				if(j>=1&&mov>=w[i]-w[1])
				    dp[i][j][mov]=max(dp[i-1][j][mov],dp[i-1][j-1][mov-w[i]+w[1]]+v[i]);
				else dp[i][j][mov]=dp[i-1][j][mov];
			}
		}
	}
	int ans=0;
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=3*n;j++)
		{
			long long we=(long long)i*w[1]+j;
			if(we<=ww)ans=max(ans,dp[n][i][j]);
		}
	}
	cout<<ans<<'\n';
	
	return 0;
}