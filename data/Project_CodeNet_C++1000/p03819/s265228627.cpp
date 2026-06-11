#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#define rep(i,st,ed) for (int i=st;i<=ed;++i)
#define lb(x) (x&-x)

const int N=500005;

struct data {
	int l,r;
} p[N];

int s[N],n,m;

int read() {
	int x=0,v=1; char ch=getchar();
	for (;ch<'0'||ch>'9';v=(ch=='-')?(-1):v,ch=getchar());
	for (;ch<='9'&&ch>='0';x=x*10+ch-'0',ch=getchar());
	return x*v;
}

void add(int x,int v) {
	for (;x<=m;x+=lb(x)) s[x]+=v;
}

int get(int x) {
	int res=0;
	for (;x;x-=lb(x)) res+=s[x];
	return res;
}

bool cmp(data a,data b) {
	return (a.r-a.l<b.r-b.l);
}

int main(void) {
	n=read(),m=read();
	rep(i,1,n) p[i].l=read(),p[i].r=read();
	std:: sort(p+1,p+n+1,cmp);
	int rec=n;
	for (int d=1,j=1;d<=m;++d) {
		while (j<=n&&p[j].r-p[j].l+1<d) {
			add(p[j].l,1),add(p[j].r+1,-1);
			j++,rec--;
		}
		int ans=rec;
		for (int i=0;i<=m;i+=d) {
			ans+=get(i);
		}
		printf("%d\n", ans);
	}
	return 0;
}