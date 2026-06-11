#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
constexpr ll INF = (1LL << 60);

int main(){ 
  int n, m, r;
  cin >> n >> m >> r;
  vector<int> a(r);
  rep(i,r) cin >> a[i], --a[i];
  vector<vector<ll>> dist(n, vector<ll>(n, INF));

  rep(i,m) {
    int u, v, c;
    cin >> u >> v >> c;
    u--; v--;
    dist[u][v] = c;
    dist[v][u] = c;
  }
  rep(i,n) dist[i][i] = 0;

  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    }
  }

  sort(a.begin(), a.end());

  ll res = INF;

  do {

    ll tmp = 0;

    for (int i = 0; i < r - 1; i++) {
      tmp += dist[a[i]][a[i + 1]];
    }
    res = min(res, tmp);
  } while (next_permutation(a.begin(), a.end()));
  cout << res << endl;
  return 0;
} 