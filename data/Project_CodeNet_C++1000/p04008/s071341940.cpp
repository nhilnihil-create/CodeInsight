#include<iostream>
#include<vector>
using namespace std;
vector<int>G[1<<17];
int n,K,a[1<<17];
int cnt;
int dfs(int u,int p)
{
	int d=0;
	for(int i=0;i<G[u].size();i++)
	{
		d=max(d,dfs(G[u][i],u));
	}
	if(d==K-1&&p!=0)cnt++,d=-1;
	return d+1;
}
main()
{
	cin>>n>>K;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		a[i]--;
		if(i)G[a[i]].push_back(i);
	}
	dfs(0,0);
	cout<<cnt+!!a[0]<<endl;
}