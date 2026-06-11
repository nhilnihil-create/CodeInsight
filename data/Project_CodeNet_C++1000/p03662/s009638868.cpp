#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define MN 100005
using namespace std;
int n,num,fa[MN],sz[MN],head[MN];
struct edge{int to,next;}g[MN<<1];
void dfs(int u,int f){
	fa[u]=f;sz[u]=1;
	for(int i=head[u];i;i=g[i].next)if(g[i].to!=f)dfs(g[i].to,u),sz[u]+=sz[g[i].to];
}
void ins(int u,int v){g[++num].next=head[u];head[u]=num;g[num].to=v;}
int main(){
	scanf("%d",&n);int x,y;
	for(int i=1;i<n;i++)scanf("%d%d",&x,&y),ins(x,y),ins(y,x);dfs(1,1);
	int tmp=n,cnt=0,cnt2=0;while(tmp!=1)tmp=fa[tmp],cnt++;cnt--;tmp=n;
	while(cnt2<cnt/2)tmp=fa[tmp],cnt2++;
	printf("%s\n",sz[tmp]<sz[1]-sz[tmp]?"Fennec":"Snuke");
}