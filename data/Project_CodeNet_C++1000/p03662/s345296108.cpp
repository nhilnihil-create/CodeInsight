#include <bits/stdc++.h>
using namespace std;
int n;
int dist[2][100000],id,s;
vector<int>g[100000];
bool dfs(int idx,int par=-1)
{
	if(~par)dist[id][idx]=dist[id][par]+1;
	for(auto &to:g[idx])
	{
		if(to!=par)dfs(to,idx);
	}
}
int main()
{
	cin>>n;
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		cin>>a>>b;
		a--;
		b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	id=0;
	dfs(0);
	id=1;
	dfs(n-1);
	for(int i=0;i<n;i++)
	{
		if(dist[0][i]<=dist[1][i])s++;
	}
	if(s>=(n+2)/2)cout<<"Fennec\n";else cout<<"Snuke\n";
	return 0;
}
