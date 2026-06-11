#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
int n,cnt,fir[101010];
int dep[101010],nxt[202020],to[202020];
void add(int x,int y)
{
	nxt[++cnt]=fir[x];fir[x]=cnt;
	to[cnt]=y;
}
void dfs(int x)
{
	priority_queue<int> q;
	dep[x]=0;
	for(int i=fir[x];i;i=nxt[i])
	{
		dfs(to[i]);
		q.push(dep[to[i]]);
	}
	int k=1;
	while(!q.empty())
	{
		dep[x]=max(dep[x],q.top()+k);
		q.pop();k++;
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=2;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		add(x,i);
	}
	dfs(1);
	printf("%d\n",dep[1]);
	return 0;
}