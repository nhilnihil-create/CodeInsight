#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN=4000+10;
int head[MAXN],e[MAXN],nxt[MAXN],tot,cnt;
pair<int,int> ed[MAXN];

inline void addedge(int u,int v)
{
	e[++tot]=v;nxt[tot]=head[u];head[u]=tot;
	e[++tot]=u;nxt[tot]=head[v];head[v]=tot;
}

void dfs(int u,int fa,int lim)
{
	++cnt;if(!lim) return ;
	for(int i=head[u];i;i=nxt[i])
		if(e[i]!=fa) dfs(e[i],u,lim-1);
}

int main()
{
	int n,k;scanf("%d %d",&n,&k);
	for(int i=1,u,v;i<n;++i) scanf("%d %d",&u,&v),addedge(u,v),ed[i]=make_pair(u,v);
	int ans=n;
	if(k&1)
	{
		for(int i=1;i<n;++i) 
		{
			cnt=0;
			dfs(ed[i].first,ed[i].second,(k-1)>>1);
			dfs(ed[i].second,ed[i].first,(k-1)>>1);
			ans=min(ans,n-cnt);
		};
	}else
	{
		for(int i=1;i<=n;++i)
		{
			cnt=0;
			dfs(i,-1,k>>1);
			ans=min(ans,n-cnt);
		};
	};
	printf("%d\n",ans);
	return 0;
}