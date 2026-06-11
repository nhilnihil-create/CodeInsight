#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;

typedef long long LL;

inline int read()
{
	char c=getchar();int num=0,f=1;
	for(;!isdigit(c);c=getchar())
		f=c=='-'?-1:f;
	for(;isdigit(c);c=getchar())
		num=num*10+c-'0';
	return num*f;
}

const int N=2e3+5;
const int M=N*N;
const int mod=1e9+7;

inline void add(int &x,int y){(x+=y)>=mod?x-=mod:0;}

int ksm(int x,int k)
{
	int res=1;
	for(;k;k>>=1,x=1ll*x*x%mod)
		if(k&1) res=1ll*res*x%mod;
	return res;
}

int n,k;
int f[N][N],fac[M],ifac[M];

int C(int n,int m){return 1ll*fac[n]*ifac[m]%mod*ifac[n-m]%mod;}

int main()
{
	n=read(),k=read();
	if(k==1)
	{
		cout<<1;
		return 0;
	}
	fac[0]=1;
	for(int i=1;i<=n*k;++i) fac[i]=1ll*fac[i-1]*i%mod;
	ifac[n*k]=ksm(fac[n*k],mod-2);
	for(int i=n*k-1;~i;--i) ifac[i]=1ll*ifac[i+1]*(i+1)%mod;
	f[0][0]=1;
	for(int i=0;i<=n;++i)
	{
		for(int j=0;j<=i;++j)
		{
			if(i) add(f[i][j],f[i-1][j]);
			if(j) add(f[i][j],1ll*f[i][j-1]*C(n-i+(n-j+1)*(k-1)-1,k-2)%mod);
		}
	}
	cout<<1ll*f[n][n]*fac[n]%mod;
	return 0;
}