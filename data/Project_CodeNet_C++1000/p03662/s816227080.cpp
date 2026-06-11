#include<bits/stdc++.h>
using namespace std;
int dis[100005];
int n;
vector<int>vec[100005];
void dfs(int i)
{
	dis[i]=1;
	for(int j=0;j<vec[i].size();j++)
		if(dis[vec[i][j]]==0)
		{
			dfs(vec[i][j]);
			dis[i]+=dis[vec[i][j]];
		}
}
vector<int>ans;
bool vis[100005],ok;
void dfs2(int x)
{
	vis[x]=1;
	if(!ok)ans.push_back(x);
	if(x==n)
	{
		ok=1;
		return;
	}
	for(int i=0;i<vec[x].size();i++)
		if(!vis[vec[x][i]])
			dfs2(vec[x][i]);
	if(!ok)ans.pop_back();
}
int main()
{
	cin>>n;
	for(int i=0;i<n-1;i++)
	{
		int x,y;
		cin>>x>>y;
		vec[x].push_back(y);
		vec[y].push_back(x);
	}
	dfs(1);
//	for(int i=1;i<=n;i++)
//		cout<<dis[i]<<' ';
//	cout<<endl;
	dfs2(1);
	int x=ans[(ans.size()+1)/2];
//	for(int i=0;i<ans.size();i++)
//		cout<<ans[i]<<' ';
//	cout<<endl;
	x=dis[x];
	if(x>=n-x)cout<<"Snuke";
	else cout<<"Fennec";
	return 0;
}
