#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long LL;
const int N=1e6;
int n,m,vis[N+10],head[N+10],tot;
LL cnt1=0,cnt2=0,cnt3=0;
struct data {
    int next,num;
}edge[N+10];
void Add(int u,int v) {
    edge[++tot].next=head[u];
    edge[tot].num=v;
    head[u]=tot;
}
int dfs(int x,int k) {
    if (vis[x]!=-1&&vis[x]!=k) return 0;
    if (vis[x]!=-1) return 1;
    vis[x]=k;
    int ans=1;
    for (int i=head[x];i!=-1;i=edge[i].next) {
	int kx=edge[i].num;
	int nowk=dfs(kx,k^1);
	if (nowk==0) ans=0;
    }
    return ans;
}
int main() {
    memset(head,-1,sizeof(head));
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;i++) {
	int u,v;
	scanf("%d%d",&u,&v);
	Add(u,v);
	Add(v,u);
    }
    memset(vis,-1,sizeof(vis));
    for (int i=1;i<=n;i++) {
	if (vis[i]!=-1) continue;
	if (head[i]==-1) {
	    cnt3++;
	    continue;
	}
	int k=dfs(i,1);
	if (k==0) cnt1++;
	else cnt2++;
    }
    LL ans=(LL)n*n-(n-cnt3)*(n-cnt3);
    ans+=cnt1*cnt1+cnt1*cnt2*2+cnt2*cnt2*2;
    printf("%lld\n",ans);
    return 0;
}
