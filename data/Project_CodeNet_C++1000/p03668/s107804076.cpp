#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

const int N=100005;

struct EDGE{
	int from,to,next;
} e[N*2];

int n,cnt;
int head[N],f[N];

void addedge(int u,int v){
	e[++cnt].from=u;e[cnt].to=v;e[cnt].next=head[u];
	head[u]=cnt;
}

void dfs(int x,int fa){
	f[x]=0;
	for (int i=head[x];i;i=e[i].next){
		if (e[i].to==fa) continue;
		dfs(e[i].to,x);
		f[x]^=f[e[i].to]+1;
	}
}

int main(){
	scanf("%d",&n);
	for (int i=1;i<n;++i){
		int u,v;
		scanf("%d%d",&u,&v);
		addedge(u,v);addedge(v,u);
	}
	dfs(1,0);
	if (f[1]==0) puts("Bob");else puts("Alice");
}