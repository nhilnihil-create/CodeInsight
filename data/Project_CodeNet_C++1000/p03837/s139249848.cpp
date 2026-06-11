// 2020-08-24 18:56:04
#include<bits/stdc++.h>
#ifdef LOCAL
#include "lib/debug.hpp"
#else
#define debug(...) 1
#endif
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define rep(i, n) REP(i, 0, (n))
#define repc(i, n) REPC(i, 0, (n))
#define REP(i, n, m) for (int i = (int)(n); i < (int)(m); i++)
#define REPC(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define REPCM(i, n, m) for (int i = (int)(n); i >= (int)(m); i--)
using namespace std;
using ll = long long;
using ld = long double;
using pr = pair<ll, ll>;
using vll = vector<ll>;
using vpr = vector<pr>;
using P = pair<int, int>;
template<class T> inline bool chmin(T& a, const T& b) { if (a > b) { a = b; return true; } else return false; }
template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } else return false; }

const int V = 105;
const int inf = 1e9;
int E[V][V], D[V][V];
void answer() {
  int n, m;
  cin >> n >> m;
  rep(i, n) rep(j, n) {
    E[i][j] = D[i][j] = inf;
    if(i == j) E[i][j] = D[i][j] = 0;
  }
  rep(i, m) {
    int a, b, c;
    cin >> a >> b >> c;
    a--; b--;
    E[a][b] = D[a][b] = E[b][a] = D[b][a] = c;
  }
  rep(k, n) {
    rep(i, n) {
      rep(j, n) {
        chmin(D[i][j], D[i][k] + D[k][j]);
      }
    }
  }
  int ans = 0;
  rep(i, n) {
    rep(j, n) {
      if(i < j && E[i][j] != inf && D[i][j] < E[i][j]) {
        ans++;
      }
    }
  }
  cout << ans << '\n';
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  answer();
  return 0;
}