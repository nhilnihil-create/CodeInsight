
#include <bits/stdc++.h>  
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;   
using namespace std;
typedef long long ll;
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> 

ll k;

void dfs(ll cur,ll d, vector<vector<pair<ll,ll>>> &adj, vector<ll> &distances){
//   cout<<"INSIDE"<<cur<<endl;
  distances[cur] = d;
  for(auto p:adj[cur])
  	if(!distances[p.first] && p.first!=k)
      dfs(p.first,d+p.second,adj,distances);
  
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
  ll n;
  cin>>n;
  vector<vector<pair<ll,ll>>> adj(n+1);
  for(ll i=0;i<n-1;i++){
  	ll x,y,w;
    cin>>x>>y>>w;
    adj[x].push_back({y,w});
    adj[y].push_back({x,w});
  }
  ll q;
  cin>>q>>k;
  vector<ll> distances(n+1);
  distances[k]=-1;
  dfs(k,0,adj,distances);
//   for(auto i:distances)
//     cout<<i<<" ";
// cout<<endl;
  for(ll i=0;i<q;i++){
  	ll a,b;
    cin>>a>>b;
    cout<<distances[a]+distances[b]<<endl;
  }
    return 0;
}