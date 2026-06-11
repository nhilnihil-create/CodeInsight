#include<bits/stdc++.h>
using namespace std; 
const int N=100005;
int n,m,q,d,c,u,v; 
pair<int,int>dp[N][15]; 
vector<int>a[N]; 
int main()
{ 
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{ 
		scanf("%d%d",&u,&v); 
		a[u].push_back(v); 
		a[v].push_back(u);
	} 
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{	
		scanf("%d%d%d",&v,&d,&c);
		dp[v][d]=make_pair(i,c); 
	} 
	for(int k=9;k>=0;k--) 
		for(int i=1;i<=n;i++)
		{ 
			dp[i][k]=max(dp[i][k],dp[i][k+1]); 
			for(int j=0;j<a[i].size();j++)
			{ 
				v=a[i][j]; 
				dp[i][k]=max(dp[i][k],dp[v][k+1]); 
			} 
		} 
	for(int i=1;i<=n;i++) 
		printf("%d\n",dp[i][0].second); 
	return 0;
} 
