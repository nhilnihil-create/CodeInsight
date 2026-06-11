#include<cstdio>
#include<map>
#define maxn 200005
using namespace std;
typedef pair<int,int> PII;
int n,k,l,fa[2][maxn],siz[maxn];
int find(int i,int x)
{
	if(fa[i][x]==x) return x;
	return fa[i][x]=find(i,fa[i][x]);
}
map<PII,int> mp;
int main()
{
	scanf("%d%d%d",&n,&k,&l);
	for(int i=1;i<=n;i++) fa[0][i]=fa[1][i]=i,siz[i]=1;
	while(k--)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		int r1=find(0,u),r2=find(0,v);
		if(r1!=r2) fa[0][r2]=r1;
	}
	while(l--)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		int r1=find(1,u),r2=find(1,v);
		if(r1!=r2) fa[1][r2]=r1;
	}
	for(int i=1;i<=n;i++)
	{
		int r1=find(0,i),r2=find(1,i);
		mp[PII(r1,r2)]++;
	}
	for(int i=1;i<=n;i++)
	{
		int r1=find(0,i),r2=find(1,i);
		printf("%d",mp[PII(r1,r2)]);
		if(i!=n) printf(" ");
	}
}