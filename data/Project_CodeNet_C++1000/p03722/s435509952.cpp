#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll max_n = 1e4;
ll d[max_n]={0};
const ll INF = 1e18;
ll n,m;
struct edge{
  ll from, to;
  ll cost;
};
edge es[max_n];
bool vellman(int s){
  fill(d, d+n, INF);
  d[s] = 0;
  for(int i=0 ; i<n ; i++){
    bool update = false;
    bool upn = false;
    for(int j=0 ; j<m ; j++){
      edge e = es[j];
      if(d[e.from] != INF && d[e.to] > d[e.from] + e.cost){
        d[e.to] = d[e.from] + e.cost;
        update = true;
        if(e.to==n-1) upn = true;
      }
    }
    if(!update) break;
    if(upn && i == n-1)return false;

  }
  return true;
}
int main(){
  cin >> n >> m;
  for(int i=0 ; i<m ; i++){
    ll x,y; ll z;
      cin >> x >> y >> z;
    --x;  --y;
    es[i].from=x; es[i].to=y; es[i].cost=-z;
  }
  if(!vellman(0)){
    cout << "inf" << endl;

  }else{
    cout << -d[n-1] << endl;
  }
  return 0;
}
