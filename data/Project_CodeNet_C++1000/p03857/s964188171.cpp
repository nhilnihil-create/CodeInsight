#include<cstdio>
#include<vector>
#include<cstring>
#include<map>
#include<algorithm>
using namespace std;
const int MAXN=200005;
int n,k,l,fa[MAXN],zfa[MAXN];
map<pair<int,int>,int>M;
int find(int x)
{
	if(fa[x]==x)
		return x;
	return fa[x]=find(fa[x]);
}
int zfind(int x)
{
	if(zfa[x]==x)
		return x;
	return zfa[x]=zfind(zfa[x]);
}
struct node
{
	int u,v;
	node(){}
}A[MAXN];
int main()
{
	scanf("%d %d %d",&n,&k,&l);
	for(int i=0;i<=n;i++)
		fa[i]=zfa[i]=i;
	for(int i=1;i<=k;i++)
	{
		int u,v;
		scanf("%d %d",&u,&v);
		int a=find(u),b=find(v);
		if(a!=b)
		{
			fa[a]=b;
		}
	}
	for(int i=1;i<=l;i++)
	{
		scanf("%d %d",&A[i].u,&A[i].v);
		int a=zfind(A[i].u),b=zfind(A[i].v);
		if(a!=b)
		{
			zfa[a]=b;
		}
	}
	for(int i=1;i<=n;i++)
	{
		pair<int,int> c;
		c.first=find(i);
		c.second=zfind(i);
		M[c]++;
	}
	for(int i=1;i<=n;i++)
	{
		pair<int,int> c;
		c.first=find(i);
		c.second=zfind(i);
		printf("%d%c",M[c],i==n?'\n':' ');
	}
}