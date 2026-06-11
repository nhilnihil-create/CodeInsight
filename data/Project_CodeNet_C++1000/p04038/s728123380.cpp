#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=1000000007;
int fac[4040404];
int ifac[4040404];
int dp[2020][2020];
int C(int n,int m)
{
	if(n<m)
		return 0;
	return (long long)fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}
int main()
{
	int n,k,h;
	scanf("%d%d",&n,&k);
	if(k==1)
	{
		printf("1");
		return 0;
	}
	fac[0]=1;
	h=n*k;
	k--;
	for(int i=1;i<=h;i++)
		fac[i]=(long long)fac[i-1]*i%mod;
	ifac[0]=ifac[1]=1;
	for(int i=2;i<=h;i++)
		ifac[i]=(long long)(mod-mod/i)*ifac[mod%i]%mod;
	for(int i=2;i<=h;i++)
		ifac[i]=(long long)ifac[i-1]*ifac[i]%mod;
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	for(int i=0;i<=n;i++)
		for(int j=max(i,1);j<=n;j++)
		{
			if(i)
				(dp[i][j]+=dp[i-1][j])%=mod;
			(dp[i][j]+=(long long)dp[i][j-1]*C(i+j*k-1,k-1)%mod)%mod;
		}
	printf("%d",(long long)dp[n][n]*fac[n]%mod);
	return 0;
}