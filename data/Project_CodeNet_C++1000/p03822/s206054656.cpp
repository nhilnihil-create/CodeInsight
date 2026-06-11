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

vector<int> dp(100100, -1);
vector<int> G[100100];

int dfs(int v = 0) {
  if (dp[v] != -1) return dp[v];
  if (G[v].empty()) return dp[v] = 0;
  vector<int> vs;
  for (int u: G[v]) {
    vs.push_back(dfs(u));
  }
  sort(vs.begin(), vs.end(), greater<int>());
  int ans = 0;
  rep(i, vs.size()) chmax(ans, vs[i] + i + 1);
  return dp[v] = ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(25);

  int n;
  cin >> n;
  vector<int> a(n, 0);
  FOR(i, 1, n) {
    cin >> a[i];
    a[i]--;
  }

  FOR(i, 1, n) {
    G[a[i]].push_back(i);
  }
  cout << dfs() << '\n';






  
  return 0;
}