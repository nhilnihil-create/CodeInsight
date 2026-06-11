#include <bits/stdc++.h>

using namespace std;

struct node
{
	int u,v;
}b[20202];

int n,k,ret,ans,num;
vector <int> vec[20202];

void DFS(int x,int y,int deep)
{
	if(deep>k/2) ret++;
	for(int i=0;i<vec[x].size();i++)
	{
		int nxt=vec[x][i];
		if(nxt==y) continue;
		DFS(nxt,x,deep+1);
	}
}

int main()
{
	scanf("%d%d",&n,&k);ans=n;
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		b[i].u=x;b[i].v=y;
		vec[x].push_back(y);
		vec[y].push_back(x);
	}
	if(!(k&1))
	{
		for(int i=1;i<=n;i++)
		{
			ret=0;DFS(i,-1,0);ans=min(ans,ret);
		}
	}
	else
	{
		for(int i=1;i<n;i++)
		{
			ret=0;
			DFS(b[i].u,b[i].v,0);
			DFS(b[i].v,b[i].u,0);
			ans=min(ans,ret);
		}
	}
	printf("%d\n",ans);
}