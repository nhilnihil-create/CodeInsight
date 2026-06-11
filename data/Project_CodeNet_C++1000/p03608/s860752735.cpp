#include <bits/stdc++.h>
#define rep(i,n) for (ll i = 0; i < n; ++i)
#define sz(x) int(x.size())
#define ALL(c) (c).begin(), (c).end()
#define SUM(x) std::accumulate(ALL(x), 0LL)
#define MIN(v) *std::min_element(v.begin(), v.end())
#define MAX(v) *std::max_element(v.begin(), v.end())
#define EXIST(v, x) (std::find(v.begin(), v.end(), x) != v.end())
#define FORV(i, v) for (auto i = v.begin(); i != v.end(); i++)
using namespace std;

using ll = long long;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
const int INF = 1001001001;
const long long INFLL = LLONG_MAX / 3;
const double eps = (1e-9);

void warshall_floyd(const int& n, vector<vector<int>>& d) {
  rep(k, n) rep(i, n) rep(j, n) chmin(d[i][j], d[i][k] + d[k][j]);
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, m, R;
  cin >> n >> m >> R;
  vector<int> r(R);
  rep(i, R) {
    cin >> r[i];
    r[i]--;
  }

  vector<vector<int>> d(n, vector<int>(n, INF));
  rep(i, m) {
    int a, b, c;
    cin >> a >> b >> c;
    a--; b--;
    d[a][b] = c; d[b][a] = c;
  }

  warshall_floyd(n, d);

  sort(ALL(r));

  int ans = INF;
  do {
    int tmp = 0;
    for (int i = 0; i < r.size()-1; i++) {
      tmp += d[r[i]][r[i+1]];
    }
    chmin(ans, tmp);
  } while (next_permutation(ALL(r)));

  cout << ans << endl;

  return 0;
}
