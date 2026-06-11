#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
#define mod 1000000007LL

ll f[2010][2010],fac[4000010],inv[4000010],n,m;

inline ll rd()
{
	ll x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline ll ksm(ll x,ll y) { ll res=1;for (;y;y>>=1,x=x*x%mod) if (y&1) res=res*x%mod;return res; }

inline ll C(ll x,ll y)
{
	if (x<y) return 0;
	return fac[x]*inv[x-y]%mod*inv[y]%mod;
}

int main()
{
	n=rd();m=rd();
	if (m==1) { puts("1");return 0; }
	fac[0]=1LL;
	for (int i=1;i<=n*m;i++) fac[i]=fac[i-1]*i%mod;
	inv[n*m]=ksm(fac[n*m],mod-2);
	for (int i=n*m;i;i--) inv[i-1]=inv[i]*i%mod;
	f[0][0]=1LL;
	for (int i=1;i<=n;i++) for (int j=i;~j;j--)
	{
		f[i][j]=f[i][j+1];
		if (j) f[i][j]=(f[i][j]+f[i-1][j-1]*C(i*m-j-1,m-2))%mod;
	}
	printf("%lld\n",f[n][0]*fac[n]%mod);
	return 0;
}