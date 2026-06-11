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
int parent[100005][20];
void dfs(int ver,int pr)
{
  parent[ver][0]=pr;
  for(auto i:adj[ver])
  {
    dfs(i,ver);
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
  adj.resize(n+2);
  int x[n+1];
  set<pair<int,int> >s;
  for(int i=1;i<=n;i++)
  {
    cin>>x[i];
    s.insert({x[i],i});
  }
  int len;
  cin>>len;
  for(int i=1;i<=n;i++)
  {
    auto j=s.lower_bound({x[i]+len+1,-1});
    j--;
    if(j->second==i)
    {
      adj[n+1].push_back(i);
      // cout<<n+1<<" "<<i<<"\n";
    }
    else
    {
      adj[j->second].push_back(i);
      // cout<<j->second<<" "<<i<<"\n";
    }    
  }
  dfs(n+1,n+1);
  for(int i=1;i<=19;i++)
    for(int j=1;j<=n+1;j++)
      parent[j][i]=parent[parent[j][i-1]][i-1];

  int q;
  cin>>q;
  int l,r;
  while (q--)
  {
    cin>>l>>r;
    if(l>r)
      swap(l,r);
    if(l==r)
    {
      continue;
      cout<<0<<"\n";
    }
    int ans=1;
    for(int i=19;i>=0;i--)
    {
      if(parent[l][i]<r)
      {
        ans+=(1<<i);
        l=parent[l][i];
      }
    }
    cout<<ans<<"\n";
  }
  

}