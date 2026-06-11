#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repr(i, n) for (int i = (n); i >= 0; --i)
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define FORR(i, m, n) for (int i = (m); i >= (n); --i)
#define equals(a, b) (fabs((a) - (b)) < EPS)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ll mod = 1000000007;
//const ll mod = 998244353;
const int inf = 1e9 + 10;
const ll INF = 1e18;
const ld EPS = 1e-10;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }



int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(25);

  int n, m;
  cin >> n >> m;
  vector<vector<int>> G(n);
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  vector<vector<int>> dp(n, vector<int>(11, -1));
  int q;
  cin >> q;
  vector<int> c(q);
  rep(i, q) {
    int v, d;
    cin >> v >> d >> c[i];

    v--;
    dp[v][d] = i;
  }
  FORR(j, 10, 1) {
    rep(i, n) {
      if (dp[i][j] == -1) continue;
      chmax(dp[i][j - 1], dp[i][j]);
      for (int v: G[i]) {
        chmax(dp[v][j - 1], dp[i][j]);
      }
    }
  }
  rep(i, n) cout << (dp[i][0] == -1 ? 0 : c[dp[i][0]]) << '\n';


  


  




  
  return 0;
}