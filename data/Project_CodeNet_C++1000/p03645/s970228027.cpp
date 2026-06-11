#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  ll n,m;
  cin >> n >> m;
  vector<vector<ll>> G(n);
  rep(i,m){
    ll a,b;
    cin >> a >> b;
    a--;
    b--;
    G.at(a).push_back(b);
    G.at(b).push_back(a);
  }
  queue<ll> que;
  que.push(0);
  vector<ll> dist(n,-1);
  dist.at(0)=0;
  while(!que.empty()){
    ll v=que.front();
    que.pop();
    for(ll p: G[v]){
      if(dist.at(p)!=-1){
        continue;
      }
      dist.at(p)=dist.at(v)+1;
      que.push(p);
    }
  }
  string ans="IMPOSSIBLE";
  if(dist.at(n-1)==2){
    ans="POSSIBLE";
  }
  cout << ans;
}
