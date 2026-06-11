#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5005;
const int mod=1000000007;
int n,m,rev[maxn];
char s[maxn];
ll f[maxn][maxn],g[maxn];
inline void mul(ll *a,ll *b,ll *c)
{
	static ll ans[maxn];
	for(int i=0;i<=n;i++) ans[i]=0;
	for(int i=0;i<=n;i++)
		for(int j=0;j<=i;j++)
			(ans[i]+=a[j]*b[i-j])%=mod;
	for(int i=0;i<=n;i++) c[i]=ans[i];
}
inline void solve()
{
	static ll a[maxn],b[maxn];
	for(int i=0;i<n;i++) a[i+1]=f[i][0];
	b[0]=1;
	int t=m;
	for(;t;t>>=1,mul(a,a,a))
		if(t&1) mul(b,a,b);
	for(int i=0;i<=n;i++) g[i]=b[i];
}
int main()
{
	scanf("%d%s",&n,s+1); m=strlen(s+1);
	f[0][0]=1;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(f[i][j])
			{
				(f[i+1][j+1]+=2*f[i][j])%=mod;
				if(j>0) (f[i+1][j-1]+=f[i][j])%=mod;
			}
	/*
	g[0][0]=1;
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			if(g[i][j])
				for(int k=0;j+k+1<=n;k+=2)
					(g[i+1][j+k+1]+=g[i][j]*f[k][0])%=mod;
	*/
	solve();
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n+1;j++) f[i][j]=0;
	f[0][1]=1;
	for(int i=0;i<n;i++)
		for(int j=0;j<=n;j++)
			if(f[i][j])
			{
				(f[i+1][(j==0)?2:j+1]+=2*f[i][j])%=mod;
				(f[i+1][max(j-1,0)]+=f[i][j])%=mod;
			}
	ll ans=0;
	for(int i=0;i<=n-m;i++) (ans+=(f[i][0]+f[i][1])*g[n-i])%=mod;
	printf("%lld\n",ans);
	return 0;
}