#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,tot,x,y,z,clr[100010],head[100010],vis[100010],nxt[400010],to[400010];
void add_edge(int u,int v){
	nxt[++tot]=head[u];
	to[tot]=v;
	head[u]=tot;
	return;
}
int dfs(int u){
	vis[u]=1;
	int flg=0;
	for(int i=head[u];~i;i=nxt[i]){
		if(!flg)
			flg=2;
		int v=to[i];
		if(vis[v]){
			if(clr[v]!=clr[u]^1)
				flg=1;
			continue;
		}
		clr[v]=clr[u]^1;
		if(dfs(v)==1)
			flg=1;
	}
	return flg;
}
int main(){
	memset(head,-1,sizeof(head));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			int flg=dfs(i);
			if(!flg)
				x++;
			else if(flg==1)
				y++;
			else z++;
		}
	}
	printf("%lld",1ll*x*x+2ll*x*(n-x)+1ll*y*(y+z*2ll)+2ll*z*z);
	return 0;
}