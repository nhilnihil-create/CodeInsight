#include <bits/stdc++.h>
#define BIT(n) (1LL << (n))
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPB(i, n) for (int i = 0; i < BIT(n); i++)
#define REPS(i, x) for (int i = 1; i <= (int)(x); i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define FORA(i, n) for (auto &&i : n)
#define FORS(i, m, n) for (int i = m; i <= n; i++)
#define DEBUG(x) cerr << #x << ": " << x << "\n"
#define PRINTALL(V)                                                            \
  for (auto v : (V)) {                                                         \
    cerr << v << " ";                                                          \
  }                                                                            \
  cerr << "\n";
#define ALL(v) v.begin(), v.end()
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
#define epb emplace_back
#define int long long
using namespace std;
template < class T > bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template < class T > bool chmin(T &a, const T &b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template < class T > using vec = std::vector< T >;
template < class T > void print(const T &x) { cout << x << "\n"; }
const int MOD = 1000000007, INF = 1061109567, INF2 = INF * INF;
const double EPS = 1e-10, PI = acos(-1.0);
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const int CALCSIZE = 51;
int C[CALCSIZE][CALCSIZE];
signed main() {
  for (int i = 0; i < CALCSIZE; ++i) {
    C[i][i] = C[i][0] = 1;
    for (int j = 1; j < i; ++j) {
      C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]);
    }
  }

  cin.tie(0), ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  int N, A, B;
  cin >> N >> A >> B;
  map< int, int > a;
  REP(i, N) {
    int p;
    cin >> p;
    a[-p]++;
  }

  int count = A;
  int sum = 0;
  int comb = 0;
  bool flg = true;
  FORA(e, a) {
    if (count - e.second <= 0) {
      sum += e.first * count;
      if (!flg) {
        comb = C[e.second][count];

      } else {
        FORS(i, count, min(e.second, B)) { comb += C[e.second][i]; }
      }
      break;
    }
    flg = false;
    count -= e.second;
    sum += e.first * e.second;
  }
  print(-sum * 1.0 / A);
  print(comb);
}
//勝手に1e9+7にしない。