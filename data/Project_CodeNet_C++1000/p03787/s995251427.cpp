#include <cstdio>
#include <cstring>
#define MAXN 200010
#define LL long long

struct edge{
	int to,next;
	edge(int _to=0,int _next=0):to(_to),next(_next){}
}e[MAXN<<1];

LL n,m;
int g[MAXN],nume;
int c[MAXN],nowc,d[MAXN],tag[MAXN];

void addEdge(int u,int v){
	e[nume]=edge(v,g[u]);
	g[u]=nume++;
}

void dfs(int x){
	c[x]=nowc;
	for(int i=g[x];~i;i=e[i].next)
		if(!c[e[i].to]){
			d[e[i].to]=!d[x];
			dfs(e[i].to);
		}
}

int main(){
	memset(g,-1,sizeof g);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		addEdge(u,v); addEdge(v,u);
	}
	LL c0=0,c1=0,c2=0;
	for(int i=1;i<=n;i++)
		if(!c[i]){
			if(g[i]==-1){
				c0++;
				continue;
			}
			nowc=i;
			d[i]=0;
			dfs(i);
		}
	for(int x=1;x<=n;x++)
		for(int i=g[x];~i;i=e[i].next)
			if(d[x]==d[e[i].to])
				tag[c[x]]=1;
	for(int i=1;i<=n;i++)
		if(c[i]==i){
			if(tag[i]) c2++;
			else c1++;
		}
	LL ans=0;
	ans+=c0*c0+2*c0*(n-c0);
	ans+=(c1+c2)*(c1+c2)+c1*c1;
	printf("%lld\n",ans);
}
