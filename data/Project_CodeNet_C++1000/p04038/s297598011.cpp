#include<bits/stdc++.h>
using namespace std;
const long long maxn=5e6,mod=1e9+7;
long long jc[5555555],injc[5555555],n,k,dp[4444][2222];
long long binpow(long long a,long long t)
{
	long long res=1,p=a;
	for (long long i=t;i;i>>=1)
	{
		if (i&1) res=res*p%mod;
		p=p*p%mod;
	}
	return res;
}
void Init()
{
	jc[0]=1;
	for (long long i=1;i<=maxn;i++) jc[i]=jc[i-1]*i%mod;
	injc[maxn]=binpow(jc[maxn],mod-2);
	for (long long i=maxn-1;i>=0;i--) injc[i]=injc[i+1]*(i+1)%mod;
}
long long C(long long n,long long k)
{
	if (n<k) return 0;
	return (jc[n]*injc[k]%mod)*injc[n-k]%mod;
}
long long bino(long long n,long long k)
{
	return C(n+k,k);
}
int main()
{
	cin>>n>>k;
	if (k==1) 
	{
		printf("1\n");
		return 0;
	}
	Init();
	dp[1][1]=1;
	for (long long i=2;i<=2*n;i++)
	{
		for (long long j=1;j<=n;j++)
		{
			if (j<i-j || j>i) continue;
			dp[i][j]=(dp[i-1][j-1]+(dp[i-1][j]*(n-i+1+j)%mod)*bino((n-i+j)*(k-1)+n-j,k-2))%mod;
		}
	}
	cout<<dp[2*n][n]<<endl;
	return 0;
}