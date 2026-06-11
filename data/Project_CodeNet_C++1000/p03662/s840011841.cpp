#include<iostream>
using namespace std;
#include<algorithm>
#include<iomanip>
#include<vector>
#include<map>
#include<queue>
#include<unordered_map>
#include<set>
#include<cmath>
#define mod 1000000007
#define inf 1000000000000000
#define int long long int
void dfs(int src,vector<int> adj[],int arr[],bool visited[],int d)
{
	if(visited[src])
	    return ;
	else
	{
		visited[src]=true;
		arr[src]=d;
		for(int x:adj[src])
		   dfs(x,adj,arr,visited,d+1);
	}
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	bool visited[n+1]={false},visited2[n+1]={false};
	vector<int> adj[n+1];
	int j;
	for(j=1;j<n;j++)
	{
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int arr1[n+1],arr2[n+1];
	dfs(1,adj,arr1,visited,0);
	dfs(n,adj,arr2,visited2,0);
	int f=0,s=0;
	for(j=1;j<=n;j++)
	{
		if(arr1[j]<=arr2[j])
		{
			f++;
		}
		else
		   s++;
	}
	if(f>s)
	  cout<<"Fennec"<<endl;
	else
	  cout<<"Snuke"<<endl;
}
