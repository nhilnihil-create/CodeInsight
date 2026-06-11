#include<iostream>
#include<string.h>
#include<string>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<bitset>
#include<math.h>
#include<stack>
#include<queue>
#include<set>
#include<map>
using namespace std;
typedef long long ll;
typedef long double db;
typedef pair<int,int> pii;
const int N=100000;
const db pi=acos(-1.0);
#define lowbit(x) (x)&(-x)
#define sqr(x) (x)*(x)
#define rep(i,a,b) for (register int i=a;i<=b;i++)
#define per(i,a,b) for (register int i=a;i>=b;i--)
#define go(u,i) for (register int i=head[u];i;i=sq[i].nxt)
#define fir first
#define sec second
#define mp make_pair
#define pb push_back
#define maxd 998244353
#define eps 1e-8
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while ((ch<'0') || (ch>'9')) {if (ch=='-') f=-1;ch=getchar();}
    while ((ch>='0') && (ch<='9')) {x=x*10+(ch-'0');ch=getchar();}
    return x*f;
}

namespace My_Math{
	#define N 100000

	int fac[N+100],invfac[N+100];

	int add(int x,int y) {return x+y>=maxd?x+y-maxd:x+y;}
	int dec(int x,int y) {return x<y?x-y+maxd:x-y;}
	int mul(int x,int y) {return 1ll*x*y%maxd;}
	ll qpow(ll x,int y)
	{
		ll ans=1;
		while (y)
		{
			if (y&1) ans=mul(ans,x);
			x=mul(x,x);y>>=1;
		}
		return ans;
	}
	int inv(int x) {return qpow(x,maxd-2);}

	int C(int n,int m)
	{
		if ((n<m) || (n<0) || (m<0)) return 0;
		return mul(mul(fac[n],invfac[m]),invfac[n-m]);
	}

	int math_init()
	{
		fac[0]=invfac[0]=1;
		rep(i,1,N) fac[i]=mul(fac[i-1],i);
		invfac[N]=inv(fac[N]);
		per(i,N-1,1) invfac[i]=mul(invfac[i+1],i+1);
	}
	#undef N
}
using namespace My_Math;

int n;
ll ans[100100];
pii a[100100];

int main()
{
	n=read();
	rep(i,1,n) 
	{
		a[i].fir=read();a[i].sec=i;
	}
	sort(a+1,a+1+n);
	reverse(a+1,a+1+n);
	int mn=n+1;
	rep(i,1,n)
	{
		mn=min(mn,a[i].sec);
		if (a[i].fir!=a[i+1].fir) ans[mn]+=1ll*(a[i].fir-a[i+1].fir)*i;
	}
	rep(i,1,n) printf("%lld\n",ans[i]);
	return 0;
}

