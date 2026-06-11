#include<bits/stdc++.h>
using namespace std;
int n,k,ans;
vector<int> v[100010];
void init()
{
	int x;
	scanf("%d",&x);
	if (x!=1)
	{
		ans++;
	}
	for (int i=2;i<=n;i++)
	{
		scanf("%d",&x);
		v[x].push_back(i);
	}
}
int dfs(int x)
{
	int mx=0;
	for (int i=0;i<v[x].size();i++)
	{
		int y=v[x][i];
		mx=max(mx,dfs(y));
	}
	if (mx==k-1)
	{
		ans++;
		mx=-1;
	}
	return mx+1;
}
int main()
{
	scanf("%d%d",&n,&k);
	init();
	for (int i=0;i<v[1].size();i++)
	{
		int x=v[1][i];
		for (int j=0;j<v[x].size();j++)
		{
			dfs(v[x][j]);
		}
	}
	cout<<ans<<endl;
	return 0;
}
