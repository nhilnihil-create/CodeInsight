#include<bits/stdc++.h>
using namespace std;
int n,k;
const int maxn=2010;
vector<int> ed[maxn];
int mdis[maxn][maxn];
void bfs(int k)
{
	queue<int> q;
	q.push(k);
	while(!q.empty())
	{
		int now=q.front();
		q.pop();
		for(int i=0;i<ed[now].size();i++)
		{
			int to=ed[now][i];
			if(mdis[k][to] || k==to)continue;
			mdis[k][to]=mdis[k][now]+1;
			q.push(to);
		}
	}
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		ed[u].push_back(v);
		ed[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
		bfs(i);
	int ans=n;
	if(k%2)
	{
		for(int u=1;u<=n;u++)
			for(int i=0;i<ed[u].size();i++)
			{
				int now=0,v=ed[u][i];
				for(int j=1;j<=n;j++)
					if(min(mdis[u][j],mdis[v][j])>k/2)
						now++;
				ans=min(ans,now);
			}
	}
	else
	{
		for(int u=1;u<=n;u++)
		{
			int now=0;
			for(int v=1;v<=n;v++)
				if(mdis[u][v]>k/2)
					now++;
			ans=min(ans,now);
		}
	}
	printf("%d\n",ans);
	return 0;
}
/*
6 3
1 2
3 2
4 2
1 6
5 6
*/