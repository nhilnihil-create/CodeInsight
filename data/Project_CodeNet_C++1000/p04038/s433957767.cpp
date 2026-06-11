#include<bits/stdc++.h>
#define re register
#define int long long
#define ll long long
using namespace std;
const int maxn=2001;
const int mmd=4000010;
const int mod=1e9+7;
inline int read()
{
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9') {x=x*10+(ch^48); ch=getchar();}
	return x*f;
}
int n,k;
ll f[maxn+10][maxn+10],inv[mmd],fac[mmd];
ll qpow(ll a,ll b)
{
	ll base=1;
	a%=mod;
	while(b)
	{
		if(b&1) base=base*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return base;
}
inline ll C(int n,int m){ return (((fac[m]*inv[n])%mod)*inv[m-n])%mod; }
signed main()
{
	n=read(); k=read();
	if(k==1) 
	{
		cout<<1<<endl;
		return 0;
	}
	fac[0]=1;
//	inc(i,1,maxn) 
	for(int i=1;i<=mmd;i++)
	fac[i]=(fac[i-1]*i)%mod;
	inv[mmd]=qpow(fac[mmd],mod-2);
//	dec(i,maxn-1,0) 
	for(int i=mmd-1;i>=0;--i)
	inv[i]=(inv[i+1]*(i+1))%mod;
	f[0][0]=1;
	for(int i=1;i<=n;++i)
	{
		for(int j=0;j<=i;++j)
		{
			f[i][j]=f[i-1][j];
			if(j==0) continue;
			(f[i][j]+=f[i][j-1]*(n-j+1)%mod*C(k-2,n-i+(n-j+1)*(k-1)-1)%mod)%=mod;
		}
	}
	cout<<f[n][n]<<endl;
}