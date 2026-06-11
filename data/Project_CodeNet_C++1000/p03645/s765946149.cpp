#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (ll i = 0; i < (n); ++i)

int main() {
  ll n,m;
  cin >> n >> m;
  vector<pair<ll,ll>> g(m);
  rep(i,m){
    ll a,b;
    cin >> a >> b;
    a--;
    b--;
    g[i] = make_pair(a,b);
  }

  sort(g.begin(),g.end());
  
  vector<ll> start,goal;
  
  rep(i,m){
    if(g[i].first == 0){
      start.push_back(g[i].second);
    }
    if(g[i].second == n-1){
      goal.push_back(g[i].first);
    }
  }
  
  sort(start.begin(),start.end());
  sort(goal.begin(),goal.end());
  
  ll s=start.size(),t=goal.size();
  rep(i,s){
    ll x = start[i];
    if(binary_search(goal.begin(),goal.end(),x)){
      cout << "POSSIBLE" << endl;
      return(0);
    }
  }
  
  cout << "IMPOSSIBLE" << endl;
  
  return(0);
}
