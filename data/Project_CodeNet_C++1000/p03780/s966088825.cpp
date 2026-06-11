// start fold
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<cstring>
#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<bitset>
using namespace std;
#define ri register int
#define il inline
#define LL long long
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define enter putchar('\n')
#define size(x) ((int)x.size())
#define mem0(x) memset(x,0,sizeof(x))
template<class T>il void in(T &x)
{
	x=0; short f=1; char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') x=x*10+(c^'0'),c=getchar();
	x*=f;
}
template <typename T,typename ...Args>il void in(T &x, Args &...args)
{
	in(x); in(args...);
}
template<class T>il void out(T x,const char c='\n')
{
	static short st[30];
	short m=0;
	if(x<0) putchar('-'),x=-x;
	do st[++m]=x%10,x/=10; while(x);
	while(m) putchar(st[m--]|'0');
	putchar(c);
}
template <typename T,typename ...Args>il void out(const T &x,const Args &...args)
{
	out(x,' '); out(args...);
}
template<class T>il void print(T a[],int n)
{
	if(n<=0) return;
	for(ri i=0; i<n; ++i) out(a[i],' ');
	enter;
}
namespace i207M
{
// end fold
#define N 5005
int n,m;
int a[N],sum[N];
bitset<5000>b;
signed main()
{
#ifdef M207
	freopen("in.in","r",stdin);
	// freopen("out.out","w",stdout);
#endif
	in(n,m);
	for(ri i=1; i<=n; ++i) in(a[i]),a[i]=min(m,a[i]);
	sort(a+1,a+1+n);
	for(ri i=1; i<=n; ++i) sum[i]=sum[i-1]+a[i];
	b[0]=1;
	for(ri i=n; i>=0; --i)
	{
		int mx=m-1;
		while(!b[mx]) --mx;
		if(mx+sum[i]<m)
		{
			out(i);
			return 0;
		}
		b|=b<<a[i];
	}
	return 0;
}
// start fold
}
signed main()
{
	i207M::main();
	return 0;
}
// end fold