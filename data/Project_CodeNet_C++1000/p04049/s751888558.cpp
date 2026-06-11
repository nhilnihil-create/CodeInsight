#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N=2005;
int Head[N],Next[N<<1],Adj[N<<1],tot=0,dis[N];
int u[N],v[N];
inline void addedge(int u,int v){
	Next[++tot]=Head[u];
	Head[u]=tot;
	Adj[tot]=v;
	Next[++tot]=Head[v];
	Head[v]=tot;
	Adj[tot]=u;
}
inline void dfs(int x,int f){
	for (int e=Head[x];e;e=Next[e])
		if (Adj[e]!=f) dis[Adj[e]]=dis[x]+1,dfs(Adj[e],x);
}
int main (){
	int n,k;
	scanf ("%d%d",&n,&k);
	for (int i=1;i<n;i++){
		scanf ("%d%d",&u[i],&v[i]);
		addedge(u[i],v[i]);
	}
	int ans=n;
	if (k&1){
		for (int i=1;i<n;i++){
			dis[u[i]]=dis[v[i]]=0;dfs(u[i],v[i]),dfs(v[i],u[i]);
			int cnt=0;
			for (int j=1;j<=n;j++) if (dis[j]>(k/2)) cnt++;
			ans=min(ans,cnt);
		}
	}else{
		for (int i=1;i<=n;i++){
			dis[i]=0;int cnt=0;dfs(i,0);
			for (int j=1;j<=n;j++) if (dis[j]>(k/2)) cnt++;
			ans=min(ans,cnt);
		}
	}
	printf ("%d",ans);
	return 0;
}
