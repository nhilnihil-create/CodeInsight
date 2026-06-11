#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(n), c(m), d(m);
  rep(i, n) cin >> a[i] >> b[i];
  rep(i, m) cin >> c[i] >> d[i];
  
  vector<vector<P>> dist(n, vector<P>(m));
  rep(i, n) rep(j, m) dist[i][j] = make_pair(abs(a[i] - c[j]) + abs(b[i] - d[j]), j+1);
  rep(i, n) sort(dist[i].begin(), dist[i].end());
  rep(i, n) cout << dist[i][0].second << endl;
  return 0;
}