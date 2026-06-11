#include <cstdio>
#include <cstring>
#define MAXN 100010

struct edge{
	int to,next;
	edge(int _to=0,int _next=0):to(_to),next(_next){}
}e[MAXN<<1];

int n;
int g[MAXN],nume;
int f[MAXN];

void addEdge(int u,int v){
	e[nume]=edge(v,g[u]);
	g[u]=nume++;
}

void dfs(int x,int p){
	for(int i=g[x];~i;i=e[i].next)
		if(e[i].to^p){
			dfs(e[i].to,x);
			f[x]^=f[e[i].to]+1;
		}
}

int main(){
	memset(g,-1,sizeof g);
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		addEdge(u,v);
		addEdge(v,u);
	}
	dfs(1,0);
	if(f[1]) puts("Alice");
	else puts("Bob");
}
