#include<bits/stdc++.h>
using namespace std;
const int maxn=(1e5+10);
int n,id,dist[2][maxn];
vector<int> edge[maxn];
void dfs(int ind,int par=-1)
{
	if(~par)
		dist[id][ind]=dist[id][par]+1;
	for(int i=0;i<edge[ind].size();i++)
	{
		int to=edge[ind][i];
		if(to!=par)
			dfs(to,ind);
	}
}
int main()
{
	cin>>n;
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		cin>>a>>b;
		--a,--b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	id=0;
	dfs(0);
	id=1;
	dfs(n-1);
	int cnt=0;
	for(int i=0;i<n;i++)
		cnt+=(dist[0][i]<=dist[1][i]?1:0);
	puts(cnt>=(n+2)/2?"Fennec":"Snuke");
	return 0;
}