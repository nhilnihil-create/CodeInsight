#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(c) (c).begin(),(c).end()
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
#define MINF(a) memset(a,0x3f,sizeof(a))
#define POW(n) (1LL<<(n))
#define IN(i,a,b) (a <= i && i <= b)
using namespace std;
template <typename T> inline bool CHMIN(T& a,T b) { if(a>b) { a=b; return 1; } return 0; }
template <typename T> inline bool CHMAX(T& a,T b) { if(a<b) { a=b; return 1; } return 0; }
template <typename T> inline void SORT(T& a) { sort(ALL(a)); }
template <typename T> inline void REV(T& a) { reverse(ALL(a)); }
template <typename T> inline void UNI(T& a) { sort(ALL(a)); a.erase(unique(ALL(a)),a.end()); }
const int MOD = 1000000007;
const int INF = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-10;
/* ---------------------------------------------------------------------------------------------------- */

template <typename T>
struct edge {
  int s, t;
  T c;
  edge() {}
  edge(int t, T c) : s(-1), t(t), c(c) {}
  edge(int s, int t, T c) : s(s), t(t), c(c) {}
};

template <typename T> using Edges = vector<edge<T>>;
template <typename T> using WeightedGraph = vector<Edges<T>>;
using UnWeightedGraph = vector<vector<int>>;
template <typename T> using Matrix = vector<vector<T>>;

template <typename T>
void warshall_floyd(Matrix<T> &g, T inf) {
  for (int k = 0; k < g.size(); k++) {
    for (int i = 0; i < g.size(); i++) {
      for (int j = 0; j < g.size(); j++) {
        if (g[i][k] == inf || g[k][j] == inf) continue;
        g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
      }
    }
  }
}

signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(10);

  int N;
  cin >> N;
  Matrix<int> A(N,vector<int>(N,INF)), G(N,vector<int>(N,INF));
  REP(i,N) REP(j,N) cin >> A[i][j];
  int ans = 0;
  REP(i,N) G[i][i] = 0;
  REP(i,N) REP(j,N) if (i < j) {
    bool ok = true;
    REP(k,N) if (k != i && k != j) {
      if (A[i][j] == A[i][k] + A[k][j]) ok = false;
    }
    if (ok) G[i][j] = G[j][i] = A[i][j], ans += A[i][j];
  }
  warshall_floyd(G,INF);
  REP(i,N) REP(j,N) {
    if (G[i][j] != A[i][j]) {
      cout << -1 << endl;
      return 0;
    }
  }
  cout << ans << endl;

  return 0;
}