#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#define MAX_N 100005

using namespace std;

int n;
vector<int> v;
vector<int> edge[MAX_N];

bool dfs1(int x,int p)
{
	v.push_back(x);
	if(x==n) return true;
	for(int i=0;i<edge[x].size();i++)
	{
		int t=edge[x][i];
		if(t!=p && dfs1(t,x)) return true;
	}
	v.pop_back();
	return false;
}

int dfs2(int x,int p)
{
	int ans=1;
	for(int i=0;i<edge[x].size();i++)
	{
		int t=edge[x][i];
		if(t!=p) ans+=dfs2(t,x);
	}
	return ans;
}

int main()
{
	scanf("%d",&n);
	int x,y;
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	dfs1(1,0);
	int md=(v.size()-1)>>1;
	x=dfs2(v[md],v[md+1]);
	y=dfs2(v[md+1],v[md]);
	printf("%s\n",x>y ? "Fennec" : "Snuke");
}
