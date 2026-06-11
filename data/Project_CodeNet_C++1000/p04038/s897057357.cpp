#include<bits/stdc++.h>
#define M 2005
using namespace std;
int n,m;
const int mod=1e9+7; 
long long ans=1,res=1,a[M*M],inv[M*M],f[M][M];
inline long long ksm(long long k,long long x)
{
	long long y=1;
	while(x)
	{
		if(x&1)y=y*k%mod;
		x>>=1;
		k=k*k%mod;
	}
	return y;
}
inline long long c(int n,int m)
{
	return a[n]*inv[m]%mod*inv[n-m]%mod;
}
int main()
{
	register int i,j;
	scanf("%d%d",&n,&m);
	if(m==1)
	{
		puts("1");
		return 0;
	}
	a[0]=1;inv[0]=1;
	for(i=1;i<=n*m;i++)a[i]=a[i-1]*i%mod,inv[i]=inv[i-1]*ksm(i,mod-2)%mod;
	for(i=1;i<=n;i++)
	{
		f[i][0]=1;
		for(j=1;j<=i;j++)
		{
			f[i][j]=(f[i-1][j]+f[i][j-1]*(n-j+1)%mod*c(n*m-i-(j-1)*(m-1)-1,m-2)%mod)%mod;
		}
	}
	printf("%lld",f[n][n]);
	return 0;
}