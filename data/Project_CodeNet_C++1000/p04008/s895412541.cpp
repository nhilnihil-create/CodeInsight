#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 100005;
int a[MAXN],n,k;
struct Edge{
	int to,next;
}e[MAXN];
int head[MAXN],cnt;
inline void insert(int u,int v)
{
	e[++cnt].to=v,e[cnt].next=head[u],head[u]=cnt;
}
int ans=0,dep[MAXN],root;
bool vis[MAXN];
void dfs(int x,int fa)
{
	vis[x]=true;
	for(int i=head[x];i;i=e[i].next){
		int v=e[i].to;
		dfs(v,x);
		dep[x]=max(dep[x],dep[v]);
	}
	++dep[x];
	if(dep[x]>=k && fa && fa!=root){
		dep[x]=0;
		++ans;
	}		
}
int in[MAXN];
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1,to;i<=n;++i){
		scanf("%d",&to);
		if(i!=1)insert(to,i);
		if(i==1 && to!=1)++ans;
	}
	root=1,dfs(1,0);
	printf("%d\n",ans);
	return 0;
}
