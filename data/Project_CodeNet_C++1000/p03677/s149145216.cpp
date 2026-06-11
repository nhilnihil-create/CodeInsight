#include <stdio.h>
#include <string.h>
#include <algorithm>

#define rep(i,st,ed) for (int i=st;i<=ed;++i)
#define drp(i,st,ed) for (int i=st;i>=ed;--i)

typedef long long LL;
const int N=200005;

LL s[N],a[N],r[N],p[N],n;
LL w[N],q[N];

int read() {
	int x=0,v=1; char ch=getchar();
	for (;ch<'0'||ch>'9';v=(ch=='-')?(-1):v,ch=getchar());
	for (;ch<='9'&&ch>='0';x=x*10+ch-'0',ch=getchar());
	return x*v;
}

void dbg(LL m) {
	rep(j,1,m+1) w[j]=w[j-1]+s[j];
	rep(j,1,m+1) w[j]=w[j-1]+w[j];
	rep(j,1,m+1) q[j]=q[j-1]+p[j];
	rep(j,1,m+1) w[j]+=q[j];
	LL tmp=0;
	rep(j,1,m) printf("%lld ", w[j]); puts("");
	// rep(j,1,m) {
		// printf("%lld ", r[j]);
	// } puts("");
}

void add(LL l,LL r) {
	if (l>r) return ;
	s[l]++,s[r+1]--;
	p[r+1]-=r-l+1;
}

int main(void) {
	n=read(); LL m=read(),ans=0,mx=0;
	rep(i,1,n) a[i]=read();
	rep(i,2,n) {
		if (a[i-1]+1<=a[i]) {
			ans+=a[i]-a[i-1];
			add(a[i-1]+2,a[i]);
		} else {
			ans+=a[i]+m-a[i-1];
			add(a[i-1]+2,m);
			add(1,a[i]);
			p[1]+=m-a[i-1]-1,p[a[i]+1]-=m-a[i-1]-1;
		}
//		dbg(m);
	//	int ggg=0;
	}
	rep(i,1,m) s[i]+=s[i-1];
	rep(i,1,m) s[i]+=s[i-1];
	rep(i,1,m) p[i]+=p[i-1],s[i]+=p[i];
	rep(i,1,m) if (s[i]>mx) mx=s[i];
	printf("%lld\n", ans-mx);
//	for (int i=1;i<=m;++i) printf("%lld ", s[i]); puts("");
	return 0;
}