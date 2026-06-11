#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri,x,n) for(int ri = (int)(n-1); ri >= (int)(x); ri--)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<vector<pair<int, int>>> tree(n, vector<pair<int, int>>());
  rep(i, n-1){
    int a, b, c;
    cin >> a >> b >> c;
    a--; b--;
    tree.at(a).push_back({b, c});
    tree.at(b).push_back({a, c});
  }

  queue<int> q;
  vector<ll> d(n, -1);
  int qe, k;
  cin >> qe >> k;
  k--;
  d.at(k) = 0;
  q.push(k);
  while(!q.empty()){
    auto now = q.front(); q.pop();
    for(auto p : tree.at(now)){
      if(d.at(p.first) != -1) continue;
      d.at(p.first) = d.at(now) + p.second;
      q.push(p.first);
    }
  }

  rep(_q, qe){
    int x, y;
    cin >> x >> y;
    x--; y--;
    ll ans = d.at(x) + d.at(y);
    cout << ans << endl;
  }
  return 0;
}