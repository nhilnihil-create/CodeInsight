#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pi 3.141592653589793238
#define int long long
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

vector<int>temp[205];
vector<vector<int> >adj;
int mx=0;
void dfs(int ver,int pr,int x)
{	
	mx=max(mx,x);
	for(auto i:adj[ver])
	{
		if(i!=pr)
			dfs(i,ver,x+1);
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

	int n;
	cin>>n;
	adj.resize(n+1);
	pair<int,int> a[n+1];
	int pp[n+1];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].first;
		pp[i]=a[i].first;
		a[i].second=i;
		temp[a[i].first].push_back(i);
	}
	sort(a+1,a+n+1);
	int x,y;
	x=1,y=2;
	vector<pair<int,int>> ans;

	if(a[1].first==a[2].first)
	{
		ans.push_back({a[1].second,a[2].second});
		x=a[1].second;
		y=a[2].second;
		for(int i=a[1].first+1;i<=n;i++)
		{
			if(!temp[i].empty())
			{
				ans.push_back({temp[i].back(),y});
				y=temp[i].back();
				temp[i].pop_back();
				int z=1;
				while (!temp[i].empty())
				{
					z=temp[i].back();
					ans.push_back({x,z});
					temp[i].pop_back();
				}
				x=z;
			}
		}
	}
	else if(n>2)
	{
		for(auto i:temp[a[1].first+1])
		{
			ans.push_back({a[1].second,i});	
			y=x;
			x=i;					
		}

		for(int i=a[1].first+2;i<=n;i++)
		{
			if(!temp[i].empty())
			{
				ans.push_back({temp[i].back(),y});
				y=temp[i].back();
				temp[i].pop_back();
				int z=1;
				while (!temp[i].empty())
				{
					z=temp[i].back();
					ans.push_back({x,z});
					temp[i].pop_back();
				}
				x=z;
			}
		}		
	}

	for(auto i:ans)
	{
		adj[i.first].push_back(i.second);
		adj[i.second].push_back(i.first);
	}	

	for(int i=1;i<=n;i++)
	{
		mx=0;
		dfs(i,0,0);
		if(pp[i]!=mx)
		{
			cout<<"Impossible";
			return 0;
		}
	}
	cout<<"Possible";
}
