#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <iomanip>
#include <cmath>
typedef long long ll;
using namespace std;
void solve(){
  ll n, q, k; cin >> n;
  vector<vector<pair<ll, ll> > > v(n + 1);
  vector<ll> dis(n + 1);
  vector<bool> visited(n + 1);
  for(int i = 0; i < n - 1; i++){
    ll a, b, c; cin >> a >> b >> c;
    v[a].push_back(make_pair(b, c));
    v[b].push_back(make_pair(a, c));
  }
  cin >> q >> k;
  vector<ll> x(q), y(q);
  for(int i = 0; i < q; i++){
    cin >> x[i] >> y[i];
  }

  queue<ll> qu;
  qu.push(k);
  visited[k] = true;
  dis[k] = 0;
  while(qu.size() > 0){
    ll c = qu.front();
    qu.pop();
    for(int i = 0; i < v[c].size(); i++){
      ll nx = v[c][i].first;
      if(visited[nx] == false){
        qu.push(nx);
        visited[nx] = true;
        dis[nx] = dis[c] + v[c][i].second;
      }
    }
  }
  for(int i = 0; i < q; i++){
    cout << dis[x[i]] + dis[y[i]] << endl;
  }

  return;
}

int main(){
  solve();
  return 0;
}
