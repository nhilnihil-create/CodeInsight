// #pragma GCC optimize(3)
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <vector>
#include <cstdio>
#include <bitset>
#include <cstring>
#include <iostream>
#include <algorithm>
#define maxn 2010
#define int long long
#define MOD 1000000007
using namespace std;
void write(int x){if(x<0){putchar('-');x=-x;}if(x>9) write(x/10);putchar(x%10+'0');}
int read(){int d=0,w=1;char c=getchar();for(;c<'0'||c>'9';c=getchar())if(c=='-')
w=-1;for(;c>='0'&&c<='9';c=getchar())d=(d<<1)+(d<<3)+c-48;return d*w;}
void wln(int x){write(x);putchar('\n');}
void wrs(int x){write(x);putchar(' ');}
int n,k,f[maxn][maxn],jc[maxn*maxn],ni[maxn*maxn],jcn[maxn*maxn];
int calc(int x,int y)
{
	return x>=y?jc[x]*jcn[y]%MOD*jcn[x-y]%MOD:0;
}
signed main()
{
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	n=read();
	k=read();
	if(k==1)
	{
		write(1);
		return 0;
	}
	jc[0]=1;
	for(int i=1;i<=k*n;i++)
		jc[i]=jc[i-1]*i%MOD;
	ni[0]=0;
	ni[1]=1;
	for(int i=2;i<=n*k;i++)
		ni[i]=(-MOD/i*ni[MOD%i]%MOD+MOD)%MOD;
	jcn[0]=1;
	for(int i=1;i<=n*k;i++)
		jcn[i]=jcn[i-1]*ni[i]%MOD;
	f[0][1]=1;
	for(int i=2;i<=n;i++)
		f[0][i]=f[0][i-1]*calc(i*(k-1)-1,k-2)%MOD;
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			f[i][j]=(f[i-1][j]+f[i][j-1]*calc(i+j*(k-1)-1,k-2)%MOD)%MOD;
	write(f[n][n]*jc[n]%MOD);
	return 0;
}
