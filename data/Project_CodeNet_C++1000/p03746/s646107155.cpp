#include <bits/stdc++.h>
#define int long long
#define iris 19260817
using namespace std;

bool v[100010];
vector<int> edge[100010],ans;

void dfs(int a,int f)
{
	if(!v[a])
	{
		ans.emplace_back(a);
	}
	v[a]=1;
	for(int b:edge[a])
	{
		if(!v[b] && b!=f)
		{
			dfs(b,a);
			return;
		}
	}
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n,m,i,a,b;
	cin>>n>>m;
	for(i=0;i<m;i++)
	{
		cin>>a>>b;
		edge[a].emplace_back(b);
		edge[b].emplace_back(a);
	}
	dfs(1,0);
	reverse(ans.begin(),ans.end());
	dfs(1,0);
	cout<<ans.size()<<'\n';
	for(i=0;i<ans.size();i++)
	{
		if(i)
		{
			cout<<' ';
		}
		cout<<ans[i];
	}
	cout<<'\n';
	
	return 0;
}
