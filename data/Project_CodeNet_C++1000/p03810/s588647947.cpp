#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#define Rep(i,a,b) for(register int i=(a),i##end=(b);i<=i##end;++i)
#define Repe(i,a,b) for(register int i=(a),i##end=(b);i>=i##end;--i)
#define For(i,a,b) for(i=(a),i<=(b);++i)
#define Forward(i,a,b) for(i=(a),i>=(b);--i)
template<typename T>inline void read(T &x)
{
	T f=1;x=0;char c;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+(c^48);
	x*=f;
}
using namespace std;

const int MAXN=1e5+7;

static int n,a[MAXN],cnt;

inline void init()
{
	read(n);
	Rep(i,1,n)read(a[i]);
	sort(a+1,a+n+1);
}

inline int gcd(int u,int v){return v?gcd(v,u%v):u;}

int getans(int now)
{
	cnt=0;
	Rep(i,1,n)cnt+=(a[i]^1)&1;
	if(cnt&1)return now;
	else
	{
		if(cnt!=n-1||a[1]==1)return now^1;
		static int x;x=0;
		Rep(i,1,n)
		{
			if(a[i]&1)--a[i];
			x=gcd(a[i],x);
		}
		Rep(i,1,n)a[i]/=x;
		return getans(now^1);
	}
}

inline void solve()
{
	if(getans(1))return(void)puts("First");
	puts("Second");
}

int main()
{
	init();
	solve();
	return 0;
}