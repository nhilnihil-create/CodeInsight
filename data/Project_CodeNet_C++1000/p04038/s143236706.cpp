#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<complex>
#include<iostream>
#include<algorithm>
#define N 2001
#define LL long long
#define add_edge(u,v) nxt[++cnt]=head[u],head[u]=cnt,to[cnt]=v
#define open(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
char ch;bool fs;void re(int& x)
{
	while(ch=getchar(),ch<33);
	if(ch=='-')fs=1,x=0;else fs=0,x=ch-48;
	while(ch=getchar(),ch>33)x=x*10+ch-48;
	if(fs)x=-x;	
}
using namespace std;
const int mod=1000000007;
int inv[N*N],ifac[N*N],fac[N*N];
int n,k,f[N][N];
int C(int n,int m)
{
	return 1ll*fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}
int main()
{
	re(n),re(k);
	if(k==1)
	{
		puts("1");
		return 0;
	}
	inv[0]=inv[1]=ifac[0]=fac[0]=1;
	for(int i=1;i<=n*k;++i)
	{
		if(i>1)inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
		fac[i]=1ll*i*fac[i-1]%mod;
		ifac[i]=1ll*inv[i]*ifac[i-1]%mod;
	}
	f[0][0]=1;
	for(int i=1;i<=n;++i)
		for(int j=0;j<=i;++j)
			f[i][j]=(f[i-1][j]+(j?1ll*C(n-i+(n-j+1)*(k-1)-1,k-2)*f[i][j-1]:0))%mod;
	printf("%d\n",1ll*f[n][n]*fac[n]%mod);
}