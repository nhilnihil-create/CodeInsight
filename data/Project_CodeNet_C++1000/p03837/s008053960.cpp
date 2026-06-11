#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

const int INF = 1001001001;

int main(){
  int n, m;
  cin >> n >> m;
  vector<vector<int>> d(n, vector<int>(n, INF));
  rep(i, n) d.at(i).at(i) = 0;
  vector<tuple<int, int, int>> edge(m);
  rep(i, m){
    int a, b, c;
    cin >> a >> b >> c;
    a--; b--;
    d.at(a).at(b) = c;
    d.at(b).at(a) = c;
    edge.at(i) = make_tuple(a, b, c);
  }
  rep(k, n)rep(i, n)rep(j, n)d.at(i).at(j) = min(d.at(i).at(j), d.at(i).at(k) + d.at(k).at(j));
  // rep(i, n){
  //   rep(j, n){
  //     int o;
  //     if(d.at(i).at(j) == INF) o = -1;
  //     else o = d.at(i).at(j);
  //     cerr << o << " ";
  //   }
  //   cerr << endl;
  // }
  int ans = 0;
  rep(i, m){
    int a, b, c;
    tie(a, b, c) = edge.at(i);
    bool add = true;
    rep(j, n){
      rep(k, n){
        int f = d.at(j).at(k);
        int g = c;
        g += d.at(j).at(a);
        g += d.at(b).at(k);
        // cerr << i << " " << j << " " << k << " " << f << " " << g << endl;
        if(f == g) add = false;
      }
    }
    if(add == true) ans++;
  }
  cout << ans << endl;
  return 0;
}