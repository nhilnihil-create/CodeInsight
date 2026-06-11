//BadWaper gg
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#include<deque>
#include<bitset>
#include<map>
#include<set>
#define inf 1e9
#define eps 1e-6
#define mp make_pair
#define N 2010
#define M 4000010
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
inline ll read()
{
	char ch=getchar();
	ll s=0,w=1;
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){s=s*10+ch-'0';ch=getchar();}
	return s*w;
}
int f[N][N];
int fac[M],inv[M];
int n,k;
const int mod=1e9+7;
inline int C(int n,int m){if(n<m)return 0;return 1LL*fac[n]*inv[m]%mod*inv[n-m]%mod;}
inline int Z(int x){return x>=mod?x-mod:x;}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read(),k=read();
	if(k==1){printf("1\n");return 0;}
	fac[0]=1;
	for(register int i=1;i<=n*k;i++)fac[i]=1LL*fac[i-1]*i%mod;
	inv[0]=inv[1]=1;
	for(register int i=2;i<=n*k;i++)inv[i]=1LL*(mod-mod/i)*inv[mod%i]%mod;
	for(register int i=2;i<=n*k;i++)inv[i]=1LL*inv[i]*inv[i-1]%mod;
	f[0][0]=1;
	for(register int i=1;i<=n;i++)
	{
		f[i][0]=1;
		for(register int j=1;j<=i;j++)
		{
			f[i][j]=f[i-1][j];
			f[i][j]=Z(f[i][j]+1LL*f[i][j-1]*(n-j+1)%mod*C(n*k-(j-1)*(k-1)-i-1,k-2)%mod);
		}
	}
	printf("%d\n",f[n][n]);
	return 0;
}
