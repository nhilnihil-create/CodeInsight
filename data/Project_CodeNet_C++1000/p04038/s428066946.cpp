#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define Vector point
using namespace std;
inline int read()
{
	int x=0,fl=1;char st=getchar();
	while(st<'0'||st>'9'){ if(st=='-')fl=-1; st=getchar();}
	while(st>='0'&&st<='9') x=x*10+st-'0',st=getchar();
	return x*fl;
}
const int N=2005,mod=1e9+7;
int n,k;
ll f[N<<1][N],fac[N*N],invfac[N*N];
inline ll ksm(int x,int y)
{
	ll res=1;
	while(y)
	{
		if(y&1) res=res*x%mod;
		x=(ll)x*x%mod;
		y>>=1;
	}
	return res;
}
inline ll C(int x,int y)
{
	if(y==0) return 1ll;
	return fac[x]*invfac[x-y]%mod*invfac[y]%mod;
}
int main()
{
	n=read();k=read();
	if(k==1)
	{
		puts("1");
		return 0;
	}
	fac[0]=1;invfac[0]=1;
	for(int i=1;i<=n*k;i++)
		fac[i]=(ll)fac[i-1]*i%mod,invfac[i]=ksm(fac[i],mod-2);
	f[0][0]=1;
	for(int i=1;i<=2*n;i++)
		for(int j=0;j<=min(n,i);j++)
		{
			if(j) f[i][j]=(f[i][j]+f[i-1][j-1])%mod;
			if(j+1<=i-1)
			{
				int numc=(i-1-j-1)/2;
				f[i][j]=(f[i][j]+f[i-1][j+1]*(n-numc)%mod*C(n*k-i-numc*(k-2),k-2)%mod)%mod;
			}
		}
	printf("%lld",f[n<<1][0]);
	return 0;
}