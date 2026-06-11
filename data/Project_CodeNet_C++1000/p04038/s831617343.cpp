#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<math.h>
using namespace std;

const int N=2005;
const int mod=1e9+7;
int n,k,dp[N][N];
int fac[N*N],inv[N*N],infac[N*N];

namespace MATHEMATICS
{
	int add(int x,int y)
	{
		int ret=x+y;
		if(ret>=mod) ret-=mod;
		return ret;
	}
	int mi(int x,int y)
	{
		int ret=x-y;
		if(ret<0) ret+=mod;
		return ret;
	}
	
	void inc(int &x,int y)
	{
		x+=y;
		if(x>=mod) x-=mod;
	}
	void dec(int &x,int y)
	{
		x-=y;
		if(x<0) x+=mod;
	}
	
	int mul(int x,int y)
	{
		return 1LL*x*y%mod;
	}
}
using namespace MATHEMATICS;

int C(int x,int y)
{
	return mul(fac[x],mul(infac[y],infac[x-y]));
}

int main()
{
	int i,j;
	scanf("%d%d",&n,&k);
	if(k==1)
	{
		printf("%d\n",1);
		return 0;
	}
	fac[0]=1;for(i=1;i<=n*k;++i) fac[i]=mul(fac[i-1],i);
	inv[1]=1;for(i=2;i<=n*k;++i) inv[i]=mul(inv[mod%i],mod-mod/i);
	infac[0]=1;for(i=1;i<=n*k;++i) infac[i]=mul(infac[i-1],inv[i]);
	
	dp[0][0]=1;
	for(i=0;i<=n;++i)
		for(j=i;j<=n;++j)
		{
			if(i) inc(dp[i][j],dp[i-1][j]);
			if(j) inc(dp[i][j],mul(dp[i][j-1],C(i+(j-1)*(k-1)+k-2,k-2)));
		}
	printf("%d\n",mul(dp[n][n],fac[n]));
	
	return 0;
}