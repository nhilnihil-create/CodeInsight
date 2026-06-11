#include<bits/stdc++.h>
#define N 500005
using namespace std;
bool vis[N];
int n,x,k,ans,kk,dep[N],fat[N],head[N];
struct Tree{int nxt,to;}e[N];
inline void link(int x,int y){e[++kk].nxt=head[x];e[kk].to=y;head[x]=kk;}
void dfs(int u,int fa){
	dep[u]=0;
	for (int i=head[u];i;i=e[i].nxt){
		int v=e[i].to;
		if (v==fa) continue;
		dfs(v,u);
		dep[u]=max(dep[u],dep[v]+1);
	}
	if (dep[u]==k-1&&fa!=1) ans++,dep[u]=-1;
}
int main(){
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++){
		scanf("%d",&x);
		if (i==1&&x!=1) ans++;
		if (i!=1) link(x,i);
	}
	dfs(1,1);
	printf("%d\n",ans);
	return 0;
}