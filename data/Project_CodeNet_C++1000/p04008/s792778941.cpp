#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N=100005;
int Head[N],Next[N],Adj[N],tot=0;
inline void addedge(int u,int v){
	Next[++tot]=Head[u];
	Head[u]=tot;
	Adj[tot]=v;
}
int fa[N];
int n,k,ans=0;
int dis[N],dep[N];
inline void dfs(int x,int las) {
	dis[x]=dep[x];
	for (int e=Head[x];e;e=Next[e]) {
		dep[Adj[e]]=dep[x]+1,dfs(Adj[e],x);
		dis[x]=max(dis[x],dis[Adj[e]]);
	}
	if(las!=1&&x!=1&&dis[x]-dep[x]==k-1) ++ans,dis[x]=0;
}
int main (){
	scanf ("%d%d",&n,&k);
	for (int i=1;i<=n;i++) scanf ("%d",&fa[i]);
	if (fa[1]!=1) ans=fa[1]=1;
	for (int i=2;i<=n;i++) addedge(fa[i],i);
	dfs(1,0);
	printf ("%d",ans);
	return 0;
}
