#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pi 3.141592653589793238
#define int long long
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

vector<vector<int> >adj;
int dp[2005][2004];
int n,k;
int mn=1e9;

void dfs(int ver,int pr)
{
	for(auto i:adj[ver])
	{
		if(i!=pr)
		{
			dfs(i,ver);
			for(int j=n+1;j>=1;j--)
			{
				dp[ver][j]+=dp[i][j-1];
			}
		}
	}
	dp[ver][0]=dp[ver][1]+1;
}

void dfs2(int ver,int pr)
{
	if(!mn)
		return ;
	mn=min(mn,dp[ver][k/2+1]);
	for(auto i:adj[ver])
	{
		if(k&1)
		mn=min(mn,dp[ver][k/2+1]-(dp[i][k/2]-dp[i][k/2+1]));
	}
	for(auto i:adj[ver])
	{
		if(i!=pr)
		{
			for(int j=n+1;j>=1;j--)
			{
				dp[ver][j]-=dp[i][j-1];
			}
			dp[ver][0]-=dp[i][0];
			for(int j=n+1;j>=1;j--)
			{
				dp[i][j]+=dp[ver][j-1];
			}
			dp[i][0]+=dp[ver][0];

			dfs2(i,ver);

			for(int j=n+1;j>=1;j--)
			{
				dp[i][j]-=dp[ver][j-1];
			}
			dp[i][0]-=dp[ver][0];
			for(int j=n+1;j>=1;j--)
			{
				dp[ver][j]+=dp[i][j-1];
			}
			dp[ver][0]+=dp[i][0];
		}
	}
}


signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);  
  cout.tie(0);   

  #ifndef ONLINE_JUDGE
      if(fopen("INPUT.txt","r"))
      {
      freopen ("INPUT.txt" , "r" , stdin);
      freopen ("OUTPUT.txt" , "w" , stdout);
      }
  #endif  

     cin>>n>>k;
     adj.resize(n+1);
     int x,y;
     for(int i=0;i<n-1;i++)
     {
     	cin>>x>>y;
     	adj[x].push_back(y);
     	adj[y].push_back(x);
     }

    dfs(1,0);
    dfs2(1,0);
	cout<<mn;

}
