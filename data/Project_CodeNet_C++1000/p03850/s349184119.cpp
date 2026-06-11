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
#define maxn 100010
#define inf 0x3f3f3f3f3f3f3f3f
#define int long long
using namespace std;
void write(int x){if(x<0){putchar('-');x=-x;}if(x>9) write(x/10);putchar(x%10+'0');}
int read(){int d=0,w=1;char c=getchar();for(;c<'0'||c>'9';c=getchar())if(c=='-')
w=-1;for(;c>='0'&&c<='9';c=getchar())d=(d<<1)+(d<<3)+c-48;return d*w;}
void wln(int x){write(x);putchar('\n');}
void wrs(int x){write(x);putchar(' ');}
int reac()
{
	char c=getchar();
	for(;c!='-'&&c!='+';c=getchar());
	return c=='+'?1:-1;
}
int n,a[maxn],c[maxn],f[maxn][3];
signed main()
{
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	n=read();
	c[1]=1;
	a[1]=read();
	for(int i=2;i<=n;a[i++]=read())
		c[i]=reac();
	f[1][0]=a[1];
	f[1][1]=f[1][2]=-inf;
	for(int i=2;i<=n;i++)
	{
		f[i][0]=max(f[i-1][0],f[i-1][1])+a[i]*c[i];
		f[i][1]=max(max((c[i]==-1?f[i-1][0]:-inf)+a[i]*c[i],f[i-1][1]+(c[i]==-1?abs(a[i]*c[i]):a[i]*c[i]*-1)),f[i-1][2]+a[i]*c[i]*-1);
		f[i][2]=max((c[i]==-1?f[i-1][1]:-inf)+a[i]*c[i]*-1,f[i-1][2]+(c[i]==-1?abs(a[i]*c[i]):a[i]*c[i]));
		// wrs(f[i][0]);
		// wrs(f[i][1]);
		// wln(f[i][2]);
	}
	write(max(f[n][0],f[n][1]));
	return 0;
}
