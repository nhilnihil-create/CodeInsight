#include<bits/stdc++.h>
using namespace std;
const int maxn=(1e5+10);
int n,frst=-1,cnt[maxn];
vector<int> edge[maxn],vv;
void dfs(int v,int par)
{
	cnt[v]=1;
	vv.push_back(v);
	if(v==n-1)
		frst=vv[((int)vv.size()+1)/2];
	for(int i=0;i<edge[v].size();i++)
	{
		int to=edge[v][i];
		if(par==to)
			continue;
		dfs(to,v);
		cnt[v]+=cnt[to];
	}
	vv.pop_back();
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
	dfs(0,0);
	bool win=cnt[frst]*2<n;
	puts(win?"Fennec":"Snuke");
	return 0;
}