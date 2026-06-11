#include<bits/stdc++.h>
using namespace std;
const int maxn=(1e5+10);
int n,dis[maxn],dis2[maxn],cntf=0,cnts=0;
vector<int> edge[maxn];
void dfs(int x,int f)
{
	for(int i=0;i<edge[x].size();i++)
	{
		int to=edge[x][i];
		if(f!=to)
		{
			dis[to]=dis[x]+1;
			dfs(to,x);
		}
	}
}
void dfs2(int x,int f)
{
	for(int i=0;i<edge[x].size();i++)
	{
		int to=edge[x][i];
		if(f!=to)
		{
			dis2[to]=dis2[x]+1;
			dfs2(to,x);
		}
	}
}
int main()
{
	cin>>n;
	for(int i=0;i<n-1;i++)
	{
		int x,y;
		cin>>x>>y;
		--x,--y;
		edge[x].push_back(y);
		edge[y].push_back(x);	
	}
	dfs(0,-1);
	dfs2(n-1,-1);
	for(int i=0;i<n;i++)
		if(dis[i]<=dis2[i])
			++cntf;
		else
			++cnts;
	puts(cntf<=cnts?"Snuke":"Fennec");
	return 0;
}