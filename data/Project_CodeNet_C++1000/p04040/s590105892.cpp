#include<iostream>
#include<string.h>
#include<string>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<math.h>
#include<queue>
#include<set>
#include<map>
using namespace std;
typedef long long ll;
typedef long double db;
typedef pair<int,int> pii;
const int N=200000;
const db pi=acos(-1.0);
#define lowbit(x) (x)&(-x)
#define sqr(x) (x)*(x)
#define rep(i,a,b) for (register int i=a;i<=b;i++)
#define per(i,a,b) for (register int i=a;i>=b;i--)
#define go(u,i) for (register int i=head[u];i;i=sq[i].nxt)
#define fir first
#define sec second
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define maxd 1000000007
#define eps 1e-8
int n,m,x,y;
ll fac[N+10],invfac[N+10];

int read()
{
    int x=0,f=1;char ch=getchar();
    while ((ch<'0') || (ch>'9')) {if (ch=='-') f=-1;ch=getchar();}
    while ((ch>='0') && (ch<='9')) {x=x*10+(ch-'0');ch=getchar();}
    return x*f;
}

ll qpow(ll x,int y)
{
	ll ans=1;
	while (y)
	{
		if (y&1) ans=ans*x%maxd;
		x=x*x%maxd;y>>=1;
	}
	return ans;
}

ll C(int n,int m)
{
	if ((n<m) || (n<0) || (m<0)) return 0;
	return fac[n]*invfac[m]%maxd*invfac[n-m]%maxd;
}

ll calc(int xa,int ya,int xb,int yb)
{
	//printf("calc %d %d %d %d\n",xa,ya,xb,yb);
	int n=xb-xa,m=yb-ya;
	return C(n+m,n);
}

int main()
{
	n=read();m=read();x=read();y=read();
	fac[0]=invfac[0]=1;
	rep(i,1,N) fac[i]=fac[i-1]*i%maxd;
	invfac[N]=qpow(fac[N],maxd-2);
	per(i,N-1,1) invfac[i]=invfac[i+1]*(i+1)%maxd;
	ll ans=0;
	rep(i,1,n-x)
		ans=(ans+calc(1,1,i,y)*calc(i,y+1,n,m)%maxd)%maxd;
	printf("%lld",ans);
	return 0;
}
