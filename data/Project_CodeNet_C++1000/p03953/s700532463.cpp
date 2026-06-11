//by OIerC
//Forca Barcelona!
#include<cstdio>
#include<algorithm>
#define int long long
#define rep(i, a, b) for (register int i=(a); i<=(b); ++i)
#define per(i, a, b) for (register int i=(a); i>=(b); --i)
using namespace std;
const int N=100005, P=998244353;
int a[N], b[N], c[N], n, ans;

inline int read()
{
 	int x=0,f=1;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') f=-1;
	for (;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+ch-'0';
	return x*f;
}

void redouble(int x)
{
	for (; x; x>>=1)
	{
		if (x&1)
		{
			rep(i, 1, n) c[i]=a[b[i]];
			rep(i, 1, n) a[i]=c[i];
		}
		rep(i, 1, n) c[i]=b[b[i]];
		rep(i, 1, n) b[i]=c[i];
	}
}

signed main()
{
	n=read();
	rep(i, 1, n) a[i]=read(), b[i]=i;
	per(i, n, 1) a[i]-=a[i-1];
	int m=read(), k=read();
	rep(i, 1, m) 
	{
		int x=read();
		swap(b[x], b[x+1]);
	}
	redouble(k);
	rep(i, 1, n) printf("%lld\n", a[i]+=a[i-1]);
	return 0;
}
