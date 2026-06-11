#include<bits/stdc++.h>
using namespace std;
int dp[5555][5555],n,m;
long long ans;
const int mod=1e9+7;
char s[5555];
int main()
{
	scanf("%d",&n);
	scanf("%s",s);
	m=strlen(s);
	dp[0][0]=1;
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<=i;j++)
		{
			if (!dp[i][j]) continue;
			dp[i+1][j+1]=(dp[i+1][j+1]+(dp[i][j]*2%mod))%mod;
			if (j>=1) dp[i+1][j-1]=(dp[i+1][j-1]+dp[i][j])%mod;
			else dp[i+1][j]=(dp[i+1][j]+dp[i][j])%mod;
		}
	}
	ans=(long long)dp[n][m];
	for (int i=1;i<=m;i++)
	{
		ans=(ans*(long long)((mod+1)/2))%mod;
	}
	printf("%lld\n",ans);
	return 0;
}