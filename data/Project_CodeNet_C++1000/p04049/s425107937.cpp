#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define N 2005
using namespace std;
typedef long long ll;
int n,k,a,b,tot,Maxde,deep[N],sum,ans=0x7fffffff;
int head[N],to[N<<1],nex[N<<1],fa[N],de[N];
int leaves[N],tmp;
void add(int x,int y)
{
	to[++tot]=y;
	nex[tot]=head[x];
	head[x]=tot;
}
void dfs(int x,int fath)  //O(n)
{
	fa[x]=fath;
	de[x]=de[fath]+1;
	deep[de[x]]++;
	Maxde=max(Maxde,de[x]);
	for(int i=head[x];i;i=nex[i])
	{
		if(to[i]==fath) continue;
		dfs(to[i],x);
	}
}
int main()
{
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n-1;i ++)
	{
		scanf("%d %d",&a,&b);
		add(a,b);add(b,a);
	}
	de[0]=-1;
	if(k&1)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=head[i];j;j=nex[j])
			{
				memset(deep,0,sizeof(deep));
				Maxde=sum=0;
				de[to[j]]=-1; dfs(i,to[j]);
				de[i]=-1; dfs(to[j],i);
				for(int j=k/2+1;j<=Maxde;j++)
				{
					sum+=deep[j];
				}
				ans=min(ans,sum);
			}
		}
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			memset(deep,0,sizeof(deep));
			sum=Maxde=0;
			dfs(i,0);
			for(int j=k/2+1;j<=Maxde;j++)
			{
				sum+=deep[j];
			}
			ans=min(sum,ans);
		}
	}
	printf("%d",ans);
	return 0;
}