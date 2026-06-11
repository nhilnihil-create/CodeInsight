#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
int d[101010],ansd[101010];
int to[101010],to1[101010];
int p[101010];
int q[101010],qn;
bool vis[101010];
int main()
{
	int n,la=0,m,x;
	long long k;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		d[i]=x-la;
		la=x;
	}
	for(int i=1;i<=n;i++)
		p[i]=to[i]=i;
	scanf("%d%lld",&m,&k);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&x);
		swap(p[x],p[x+1]);
		to[p[x]]=x;
		to[p[x+1]]=x+1;
	}
	qn=0;
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++)
		if(!vis[i])
		{
			qn=0;
			q[qn++]=i;
			vis[q[qn-1]]=true;
			while(!vis[to[q[qn-1]]])
			{
				q[qn]=to[q[qn-1]];
				vis[q[qn]]=true;
				qn++;
			}
			for(int j=0;j<qn;j++)
				to1[q[j]]=q[(j+k)%qn];
		}
	for(int i=1;i<=n;i++)
		ansd[to1[i]]=d[i];
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		ans+=ansd[i];
		printf("%lld\n",ans);
	}
	return 0;
}