#include<cstdio>
#include<iostream>
using namespace std;
int n,k,doe,ans;
int now[101010],pre[202020],son[202020];
int deep[101010];
void add(int x,int y)
{
	++doe;
	pre[doe]=now[x];
	now[x]=doe;
	son[doe]=y;
}
void dfs(int x,int fa)
{
	deep[x]=1;
	int p=now[x];
	while (p)
	{
		int y=son[p];
		if (y!=fa)
		{
			dfs(y,x);
			deep[x]=max(deep[x],deep[y]+1);
		}
		p=pre[p];
	}
	if (deep[x]==k && x!=1 && fa!=1) deep[x]=0,++ans;
}
int main()
{
	scanf("%d%d",&n,&k);
	int x;
	scanf("%d",&x);
	if (x!=1) ++ans;
	for (int i=2;i<=n;++i)
	{
		scanf("%d",&x);
		add(x,i);
	}
	dfs(1,0);
	printf("%d\n",ans);
	return 0;
}