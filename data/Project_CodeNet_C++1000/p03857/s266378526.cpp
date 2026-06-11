#include<cstdio>
#include<map>
#define maxn 200005
using namespace std;
int n,m,k,f[maxn],scc[maxn],x,y;
int find(int x){return x==f[x]?x:f[x]=find(f[x]);}
int f2(int x){return x==scc[x]?x:scc[x]=f2(scc[x]);}
map<pair<int,int>,int>cnt;
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++) f[i]=scc[i]=i;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		x=find(x),y=find(y);
		if(x!=y) f[y]=x;
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%d%d",&x,&y);
		x=f2(x),y=f2(y);
		if(x!=y) scc[y]=x;
	}
	for(int i=1;i<=n;i++) f[i]=find(f[i]),scc[i]=f2(scc[i]);
	for(int i=1;i<=n;i++) cnt[make_pair(f[i],scc[i])]++;
	for(int i=1;i<=n;i++) printf("%d ",cnt[make_pair(f[i],scc[i])]);
}