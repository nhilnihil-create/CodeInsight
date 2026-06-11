// Etavioxy
#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>
#include<cmath>
#define il inline
#define ll long long
#define rep(i,s,t) for(register int i=(s);i<=(t);i++)
#define rev_rep(i,s,t) for(register int i=(s);i>=(t);i--)
#define each(i,u) for(int i=head[u];i;i=bow[i].nxt)
#define file(s) freopen(s".in" ,"r",stdin),freopen(s".out","w",stdout)
#define pt(x) putchar(x)
using namespace std;
il int ci(){
	register char ch;int f=1;
	while(!isdigit(ch=getchar()))f=ch=='-'?-1:1;
	register int x=ch^'0';
	while(isdigit(ch=getchar()))x=(x*10)+(ch^'0');
	return f*x;
}

// 20:49

enum{N=100023};

ll a[N];

int main(){
	ll n=ci();
	ll sum=0;
	rep(i,1,n) sum+= a[i]=ci();
	ll t=sum/(n*(n+1)/2);
	if( sum!=t*n*(n+1)/2 ){ puts("NO"); return 0; }
	ll tmp= a[n];
	rev_rep(i,n,2) a[i]=a[i-1]-a[i]+t;
	a[1]= tmp-a[1]+t;
	rep(i,1,n) if( a[i]<0 || a[i]%n!=0 ){ puts("NO"); return 0; }
	puts("YES");
	return 0;
}
