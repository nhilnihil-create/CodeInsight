#include <bits/stdc++.h>
using namespace std;

int n,l;
char s[5010];
long long dp[5010][5010];
const long long mod=1e9+7;
inline long long ksm(long long x,long long y,long long mod)
{
	long long res=1;
	while(y)
	{
		if(y&1)
		res=res*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return res;
}
int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	l=strlen(s+1);
	dp[0][0]=1;
	for(int i=1;i<=n;++i)
	{
		for(int j=0;j<=i;++j)
		{
			dp[i][j]=(dp[i][j]+dp[i-1][j-1]*2)%mod;
			if(j==0)
			dp[i][j]=(dp[i][j]+dp[i-1][j])%mod;
			else
			dp[i][j-1]=(dp[i][j-1]+dp[i-1][j])%mod;
		}
	}
	long long ans=ksm(2,l,mod);
	ans=ksm(ans,mod-2,mod);
	ans=ans*dp[n][l]%mod;
	printf("%lld\n",ans); 
	return 0;
}