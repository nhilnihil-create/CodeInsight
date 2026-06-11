#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;
int fa[200005],fb[200005];
map<int,map<int,int> >mp;
inline int find(int x)
{
	if(fa[x]==x)
		return x;
	return fa[x]=find(fa[x]);
}
inline int fd(int x)
{
	if(fb[x]==x)
		return x;
	return fb[x]=fd(fb[x]);
}
inline void U(int x,int y)
{
	fa[find(x)]=find(y);
}
inline void U1(int x,int y)
{
	fb[fd(x)]=fd(y);
}
int main()
{
	int n,k,l;
	scanf("%d%d%d",&n,&k,&l);
	for(int i=1;i<=n;i++)
		fa[i]=fb[i]=i;
	for(int i=1;i<=k;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		U(x,y);
	}
	for(int i=1;i<=l;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		U1(x,y);
	}
	for(int i=1;i<=n;i++)
		mp[find(i)][fd(i)]++;
	for(int i=1;i<n;i++)
		printf("%d ",mp[find(i)][fd(i)]);
	printf("%d\n",mp[find(n)][fd(n)]);
	return 0;
}