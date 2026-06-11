#include<bits/stdc++.h>
using namespace std;

#define int long long 

void read(int &x) {
    x=0;int f=1;char ch=getchar();
    for(;!isdigit(ch);ch=getchar()) if(ch=='-') f=-f;
    for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';x*=f;
}
 
void print(int x) {
    if(x<0) putchar('-'),x=-x;
    if(!x) return ;print(x/10),putchar(x%10+48);
}
void write(int x) {if(!x) putchar('0');else print(x);putchar('\n');}

#define lf double
#define ll long long 

const int maxn = 1e5+10;
const int inf = 1e9;
const lf eps = 1e-8;

int p[maxn],d[maxn],n,m,k,fa[maxn][61],a[maxn],b[maxn];

signed main() {
	read(n);for(int i=1;i<=n;i++) read(p[i]),d[i]=p[i]-p[i-1],a[i]=i;
	for(int i=1;i<=n;i++) b[i]=i;
	read(m),read(k);
	for(int i=1,x;i<=m;i++) read(x),swap(a[x],a[x+1]);
	for(int i=1;i<=n;i++) fa[i][0]=a[i];
	for(int i=1;i<=60;i++)
		for(int x=1;x<=n;x++)
			fa[x][i]=fa[fa[x][i-1]][i-1];
	for(int t=k,x=1;x<=n;x++,t=k)
		for(int i=60;~i;i--)
			if(t>=(1ll<<i)) t-=(1ll<<i),b[x]=fa[b[x]][i];
	for(int i=1;i<=n;i++) a[i]=d[b[i]];
	for(int i=1;i<=n;i++) a[i]+=a[i-1],printf("%lld.0\n",a[i]);
	return 0;
}
