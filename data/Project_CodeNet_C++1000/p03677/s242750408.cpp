#include <bits/stdc++.h>

typedef long long LL;

const int N=2e5+10;

int n,m,a[N];
LL p[N],k[N];

void Init() {
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i) scanf("%d",&a[i]);
}

void add(int l,int r) {
	k[l]++; k[r+1]--; p[r+1]-=r-l+1; 
}

void Solve() {
	LL tot=0ll;
	for (int i=1;i<n;++i) {
		int l=a[i],r=a[i+1]; if (r<l) r+=m;
		tot+=r-l;
		add(l+2,r);
	}
	for (int i=1;i<=m*2;++i) k[i]+=k[i-1];
	for (int i=1;i<=m*2;++i) p[i]+=p[i-1]+k[i];
	LL ans=1e18;
	for (int i=1;i<=m;++i) ans=std::min(ans,tot-p[i]-p[i+m]);
	printf("%lld\n",ans);
}

int main() {
	Init();
	Solve();
	return 0;
}