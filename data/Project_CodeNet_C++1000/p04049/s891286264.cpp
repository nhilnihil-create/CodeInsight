#include<bits/stdc++.h>
using namespace std;
const double pi=acos(-1);
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};
const int inf=1e9+7;
#define ll long long
#define inf int(1e9+7)
#define pb push_back
#define mp make_pair
int main()
{
	int n,k;
	cin>>n>>k;
	vector<vector<int> >g(n);
	for(int i=1;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		a--;
		b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	vector<vector<int> >mat(n,vector<int>(n,inf));
	for(int r=0;r<n;r++)
	{
		auto &row=mat[r];
		queue<int>q;
		row[r]=0;
		q.push(r);
		while(!q.empty())
		{
			int u=q.front();
			q.pop();
			for(const int v:g[u])
			{
				if(row[v]<inf)
					continue;
				row[v]=row[u]+1;
				q.push(v);
			}
		}
	}
	int ans=inf;
	if(k&1)
		for(int u=0;u<n;u++)
			for(const int v:g[u])
			{
				int cnt=0;
				for(int i=0;i<n;i++)
					if(mat[u][i]+mat[v][i]<=k)
						cnt++;
				ans=min(ans,n-cnt);
			}
	else
		for(int i=0;i<n;i++)
		{
			int cnt=0;
			for(int j=0;j<n;j++)
				if(mat[i][j]<=k/2)
					cnt++;
				ans=min(ans,n-cnt);
		}
	cout<<ans;
	return 0;
}