
#pragma GCC optimize ("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse4")
#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll
#define sz(x) (int)(x).size();
#define all(x) x.begin(), x.end()
#define trav(i,a) for(auto &i:a) 
inline int in(){int x;scanf("%lld",&x);return x;}
const int inf=1e18;
int32_t main()
{
	
	int n=in();int m=in();int r=in();
	vector<int> rr(r);
	trav(i,rr)i=in();
	int d[204][204];
	for(int i=0;i<201;i++)
	for(int j=0;j<201;j++)d[i][j]=inf;
	for(int i=0;i<201;i++){d[i][i]=0;}
	int u,v,w;
	for(int i=0;i<m;i++)
	{
		cin>>u>>v>>w;
		d[u][v]=d[v][u]=min(d[u][v],w);
	}
	
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}
	
	
	sort(all(rr));
	int ans=inf;
	do
	{
		int ct=0;
		for(int i=0;i<r-1;i++)
		{
			ct+=d[rr[i]][rr[i+1]];
		}
		ans=min(ans,ct);
		
	}while(next_permutation(all(rr)));
	cout<<ans;
	
	
}