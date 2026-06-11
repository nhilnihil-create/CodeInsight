#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define fo(i,a,b) for(i=a;i<=b;i++)
const int maxn=100000+10;
int a[maxn],dis[maxn],co[maxn],h[maxn],go[maxn],nxt[maxn],cnt[maxn];
bool bz[maxn],pd[maxn];
int i,j,k,l,t,n,m,tot,top,ans,mi;
void add(int x,int y) {
	go[++tot]=y;
	nxt[tot]=h[x];
	h[x]=tot;
}
void travel(int x) {
	int t=h[x];
	while (t) {
		if (!bz[go[t]]) {
			bz[go[t]]=1;
			co[go[t]]=(co[x]+1)%k;
			cnt[(k-co[go[t]])%k]++;
			travel(go[t]);
		}
		t=nxt[t];
	}
}
void dfs(int x) {
	dis[x]=1;
	int t=h[x];
	while (t) {
		dfs(go[t]);
		dis[x]=max(dis[x],dis[go[t]]+1);
		t=nxt[t];
	}
	if (dis[x]>=k&&a[x]>1) {
		ans++;
		dis[x]=0;
	}
}
int sleep() {
	int j=0;
	for(int i=1; i<2000001; i++) j++;
	return j;
}
int main() {
	scanf("%d%d",&n,&k);
	fo(i,1,n) scanf("%d",&a[i]);
	if (a[1]!=1) {
		ans++;
		a[1]=1;
	}
	fo(i,2,n) add(a[i],i);
	dfs(1);
	printf("%d\n",ans);
	sleep();
	return 0;
}