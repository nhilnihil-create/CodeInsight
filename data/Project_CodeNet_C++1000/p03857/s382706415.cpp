/*Lucky_Glass*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
using namespace std;
const int MAXN=int(2e5);
int n,p,q;
int fa[2][MAXN+5];
map< pair<int,int> ,int> cnt;
int Find(int x,int y)
{
	if(fa[y][x]==x) return x;
	return fa[y][x]=Find(fa[y][x],y);
}
int main()
{
	scanf("%d%d%d",&n,&p,&q);
	for(int i=1;i<=n;i++)
		fa[0][i]=fa[1][i]=i;
	for(int i=0,u,v;i<p;i++)
	{
		scanf("%d%d",&u,&v);
		if(Find(u,0)!=Find(v,0))
			fa[0][fa[0][u]]=fa[0][v];
	}
	for(int i=0,u,v;i<q;i++)
	{
		scanf("%d%d",&u,&v);
		if(Find(u,1)!=Find(v,1))
			fa[1][fa[1][u]]=fa[1][v];
	}
	for(int i=1;i<=n;i++)
		cnt[make_pair(Find(i,0),Find(i,1))]++;
	for(int i=1;i<=n;i++)
	{
		if(i!=1) printf(" ");
		printf("%d",cnt[make_pair(fa[0][i],fa[1][i])]);
	}
	printf("\n");
	return 0;
}
