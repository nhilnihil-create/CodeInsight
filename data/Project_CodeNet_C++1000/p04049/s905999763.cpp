#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;
#define N 2050
int head[N],to[N<<1],nxt[N<<1],cnt,n,K,ans=1<<30;
inline void add(int u,int v) {
	to[++cnt]=v; nxt[cnt]=head[u]; head[u]=cnt;
}
int tot,vis[N];
void df1(int x,int y,int d) {
	int i; tot++;
	if(d==K/2) return ;
	for(i=head[x];i;i=nxt[i]) if(to[i]!=y&&!vis[to[i]]) {
		df1(to[i],x,d+1);
	}
}
int main() {
	scanf("%d%d",&n,&K);
	int i,x,y;
	for(i=1;i<n;i++) {
		scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
	}
	if(!(K&1)) {
		int i;
		for(i=1;i<=n;i++) {
			tot=0;
			df1(i,0,0);
			ans=min(ans,n-tot);		
		}
	}else {
		int i;
		for(i=1;i<=cnt;i+=2) {
			tot=0;
			vis[to[i+1]]=1;
			df1(to[i],0,0);
			vis[to[i+1]]=0;

			vis[to[i]]=1;
			df1(to[i+1],0,0);
			vis[to[i]]=0;
			ans=min(ans,n-tot);
		}
	}
	printf("%d\n",ans);
}
