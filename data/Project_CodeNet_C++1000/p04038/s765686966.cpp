#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define MX 4000000
int dp[2005][2005];
long long fact[MX+5],inv[MX+5];
long long pow_log(long long x,int y)
{
	if (!y)
	return 1;
	long long ret=pow_log(x,y/2);
	ret=(ret*ret)%mod;
	if (y%2)
	ret=(ret*x)%mod;
	return ret;
}
long long ncr(int n,int r)
{
	return ((fact[n]*inv[r])%mod*inv[n-r])%mod;
}
int n,k;
int solve(int w,int c)
{
	if (w==n && c==n)
	return 1;
	if (dp[w][c]!=-1)
	return dp[w][c];
	int ret=0;
	if (w!=n)
	ret=solve(w+1,c);
	if (c<w)
	ret=(ret+solve(w,c+1)*ncr(n*k-w-c*(k-1)-1,k-2)%mod*(n-c))%mod;
	return dp[w][c]=ret;
}
int main()
{
	fact[0]=1;
	for (int i=1;i<=MX;i++)
	fact[i]=(i*fact[i-1])%mod;
	inv[MX]=pow_log(fact[MX],mod-2);
	for (int i=MX-1;i>=0;i--)
	inv[i]=((i+1)*inv[i+1])%mod;
	scanf("%d%d",&n,&k);
	if (k==1)
	{
		printf("1");
		return 0;
	}
	memset(dp,-1,sizeof(dp));
	printf("%d",solve(0,0));
}