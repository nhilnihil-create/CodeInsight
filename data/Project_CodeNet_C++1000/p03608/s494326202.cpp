#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
using namespace std;
typedef long long ll;
typedef pair<int,ll> P;

const ll INF = 10010010010;

void warshall_floyd(int n, vector<vector<ll> > &D) {
  rep(k,n) rep(i,n) rep(j,n) D[i][j] = min(D[i][j], D[i][k]+D[k][j]);
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  int n, m, r;
  cin >> n >> m >> r;
  vector<int> R(r);
  rep(i,r) {
    cin >> R[i];
    R[i]--;
  }
  sort(R.begin(), R.end());
  vector<vector<ll> > dist(n, vector<ll>(n, INF));
  rep(i,m) {
    int a, b;
    ll c;
    cin >> a >> b >> c;
    a--; b--;
    dist[a][b] = c;
    dist[b][a] = c;
  }
  warshall_floyd(n, dist);
  ll ans = INF;
  do {
    ll temp = 0;
    rep(i,r-1) {
      temp += dist[R[i]][R[i+1]];
    }
    ans = min(ans, temp);
  } while (next_permutation(R.begin(), R.end()));
  cout << ans << endl;
  return 0;
}