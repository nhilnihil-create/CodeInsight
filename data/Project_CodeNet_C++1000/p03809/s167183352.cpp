#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#define MAXN 100010
#define LL long long
using namespace std;

struct edge{
	int to,next;
	edge(int _to=0,int _next=0):to(_to),next(_next){}
}e[MAXN<<1];

int n,root;
int g[MAXN],nume;
int d[MAXN];
LL a[MAXN],delta[MAXN];

void addEdge(int u,int v){
	e[nume]=edge(v,g[u]);
	g[u]=nume++;
}

bool dfs(int x,int p){
	if(d[x]==1){
		delta[x]=a[x];
		return 1;
	}
	LL temp=0,ts=0,tmax=0;
	for(int i=g[x];~i;i=e[i].next)
		if(e[i].to^p){
			if(!dfs(e[i].to,x)) return 0;
			temp+=delta[e[i].to];
			tmax=max(tmax,delta[e[i].to]);
		}
	ts=temp;
	if(ts-tmax<tmax) ts-=tmax-(ts-tmax);
	ts/=2;
	temp-=a[x];
	if(temp<0) return 0;
	if(temp>ts) return 0;
	delta[x]=a[x]-temp;
	return 1;
}

int main(){
#ifdef DEBUG
	freopen("C.in","r",stdin);
#endif
	memset(g,-1,sizeof g);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld",a+i);
	if(n==2){
		if(a[1]==a[2]) puts("YES");
		else puts("NO");
		return 0;
	}
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		addEdge(u,v);
		addEdge(v,u);
		d[u]++; d[v]++;
	}
	for(int i=1;i<=n;i++)
		if(d[i]!=1){
			root=i;
			break;
		}
	if(!dfs(root,0) || delta[root]!=0) puts("NO");
	else puts("YES");
	return 0;
}
