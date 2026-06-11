#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;
typedef long long ll;
#define N 100050
#define GG puts("NO");exit(0)
int head[N],to[N<<1],nxt[N<<1],cnt,n,root;
int f[N],val[N],du[N],a[N],la;
inline void add(int u,int v) {
	to[++cnt]=v; nxt[cnt]=head[u]; head[u]=cnt;
}
void dfs(int x,int y) {
	int i;
	if(du[x]==1) {f[x]=val[x]; return ;}
	for(i=head[x];i;i=nxt[i]) if(to[i]!=y) dfs(to[i],x);
	ll s=0;
	int mx=0;
	for(i=head[x];i;i=nxt[i]) if(to[i]!=y) {
		mx=max(mx,f[to[i]]);
		s+=f[to[i]];
	}
	int k=s-val[x];
	if(k<0) {GG;}
	if(s-mx<mx&&s-mx<k) {GG;}
	if(s-mx>=mx&&s/2<k) {GG;}
	f[x]=2*val[x]-s;
}
int main() {
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++) scanf("%d",&val[i]);
	if(n==2) {puts(val[1]==val[2]?"YES":"NO"); return 0;}
	int x,y;
	for(i=1;i<n;i++) scanf("%d%d",&x,&y),add(x,y),add(y,x),du[x]++,du[y]++;
	for(i=1;i<=n;i++) if(du[i]>1){root=i; break;}
	dfs(root,0);
	puts(f[root]?"NO":"YES");
}
