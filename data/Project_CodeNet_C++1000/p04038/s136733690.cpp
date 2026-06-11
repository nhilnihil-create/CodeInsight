#include<bits/stdc++.h>
#define ll long long
using namespace std;
int getint()
{
	int i=0,f=1;char c;
	for(c=getchar();(c!='-')&&(c<'0'||c>'9');c=getchar());
	if(c=='-')f=-1,c=getchar();
	for(;c>='0'&&c<='9';c=getchar())i=(i<<3)+(i<<1)+c-'0';
	return i*f;
}
const int N=2005,mod=1e9+7;
int n,k,m;
ll f[N][N],fac[N*N],invfac[N*N];
ll Pow(ll x,int y)
{
	ll res=1;
	for(;y;y>>=1,x=x*x%mod)
		if(y&1)res=res*x%mod;
	return res;
}
ll C(int x,int y)
{
	if(x<y||x<0||y<0)return 0;
	return fac[x]*invfac[y]%mod*invfac[x-y]%mod;
}
int main()
{
	//freopen("lx.in","r",stdin);
	n=getint(),k=getint(),m=n*k;
	if(k==1){puts("1");return 0;}
	fac[0]=1;for(int i=1;i<=m;i++)fac[i]=fac[i-1]*i%mod;
	invfac[m]=Pow(fac[m],mod-2);
	for(int i=m-1;i>=0;i--)invfac[i]=invfac[i+1]*(i+1)%mod;
	f[0][0]=1;--k;
	for(int i=0;i<=n;i++)
		for(int j=i;j<=n;j++)if(f[i][j])
		{
			f[i+1][j]=(f[i+1][j]+f[i][j])%mod;
			f[i][j+1]=(f[i][j+1]+f[i][j]*C(i+j*k+k-1,k-1))%mod;
		}
	cout<<f[n][n]*fac[n]%mod<<'\n';
	return 0;
}