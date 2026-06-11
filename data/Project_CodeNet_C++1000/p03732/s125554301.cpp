#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define chmin(i, j) i = min(i, j);
#define chmax(i, j) i = max(i, j);
#define rep(i, n) for(int i=0;i<n;i++)
int main() {
  int n;
  ll W;
  ll w0;
  cin >> n >> W;
  vector<vector<int>> b(4);
  rep(i, n) {
    int w, v;
    cin >> w >> v;
    if(i == 0) w0 = w;
    b[w-w0].emplace_back(v);
  }
  vector<vector<int>> d(4);
  rep(i, b.size()) {
    if(b[i].size() == 0) {
      d[i].emplace_back(0);
      continue;
    }
    sort(b[i].rbegin(), b[i].rend());
    d[i].resize(b[i].size()+1);
    rep(j, b[i].size()+1) {
      if(j == 0) continue;
      d[i][j] = d[i][j-1] + b[i][j-1];
    }
  }
  int ans = 0;
  rep(i, d[0].size()) {
    rep(j, d[1].size()) {
      rep(k, d[2].size()) {
        rep(l, d[3].size()) {
          ll w1 = w0 * (ll)i;
          ll w2 = (w0+1) * (ll)j;
          ll w3 = (w0+2) * (ll)k;
          ll w4 = (w0+3) * (ll)l;
          if(w1+w2+w3+w4 > W) continue;
          chmax(ans, d[0][i] + d[1][j] + d[2][k] + d[3][l]);
        }
      }
    }
  }
  cout << ans << endl;
}

