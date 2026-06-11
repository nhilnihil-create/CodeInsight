#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 100010
#define LL long long
int dis[MAXN],id[MAXN],n,m,st[MAXN];
LL k,ans[MAXN];
bool vis[MAXN];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&dis[i]);
		id[i]=i;
	}
	for(int i=n;i;i--)
		dis[i]=dis[i]-dis[i-1];
	scanf("%d%lld",&m,&k);
	for(int i=1,u;i<=m;i++)
	{
		scanf("%d",&u);
		swap(id[u],id[u+1]);
	}
	for(int i=1;i<=n;i++)
		if(!vis[i])
		{
			int c=0;
			for(int j=i;!vis[j];j=id[j]) st[c++]=j,vis[j]=1;
			for(int j=0;j<c;j++) ans[st[j]]=dis[st[(j+k)%c]];
		}
	for(int i=1;i<=n;i++)
	{
		ans[i]+=ans[i-1];
		printf("%lld\n",ans[i]);
	}
}