#include<bits/stdc++.h>
using namespace std;
const double pi=acos(-1);
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};
#define ll long long
#define inf int(1e9+7)
#define pb push_back
#define mp make_pair
vector<int>g[2005];
int dfs(int v,int f,int k)
{
	if(k==0)
		return 0;
	int ans=1;
	for(int i=0;i<g[v].size();i++)
		if(g[v][i]!=f)
			ans+=dfs(g[v][i],v,k-1);
	return ans;
}
int main()
{
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		cin>>a>>b;
		a--;
		b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	int ans=0;
	for(int i=0;i<n;i++)
	{
		int maxn=0,sum=1;
		for(int j=0;j<g[i].size();j++)
		{
			int t1=dfs(g[i][j],i,k/2);
			int t2=dfs(g[i][j],i,(k+1)/2);
			sum+=t1;
			maxn=max(maxn,t2-t1);
		}
		ans=max(ans,sum+maxn);
	}
	cout<<n-ans;
	return 0;
}