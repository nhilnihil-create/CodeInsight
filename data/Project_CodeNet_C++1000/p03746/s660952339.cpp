#include<bits/stdc++.h>
using namespace std;

int n,m;
bool vi[100100];
vector<int> ed[100100];
queue<int> ans;
stack<int> ans2;

void dfs(int nw)
{
	vi[nw]=true;
	ans.push(nw);
	for(int i=0;i<ed[nw].size();i++)
	{
		if(vi[ed[nw][i]]==false)
		{
			dfs(ed[nw][i]);
			break;
		}
	}
}

void dfs2(int nw)
{
	vi[nw]=true;
	ans2.push(nw);
	for(int i=0;i<ed[nw].size();i++)
	{
		if(vi[ed[nw][i]]==false)
		{
			dfs2(ed[nw][i]);
			break;
		}
	}
}

main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		ed[a].push_back(b);
		ed[b].push_back(a);
	}
	dfs(1);
	for(int i=0;i<ed[1].size();i++)
	{
		if(vi[ed[1][i]]==false)
		{
			dfs2(ed[1][i]);
			break;
		}
	}
	printf("%d\n",ans.size()+ans2.size());
	while(!ans2.empty())
	{
		printf("%d ",ans2.top());
		ans2.pop();
	}
	while(!ans.empty())
	{
		printf("%d ",ans.front());
		ans.pop();
	}
}