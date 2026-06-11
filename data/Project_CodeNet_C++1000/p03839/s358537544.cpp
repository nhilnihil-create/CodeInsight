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
#define DEBUG2(x, y) cerr << #x << ": " << x << " " << #y << ": " << y << "\n"
#define DEBUG3(x, y, z)                                                        \
  cerr << #x << ": " << x << " " << #y << ": " << y << " " << #z << ": " << z  \
       << "\n"
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
#define pint pair< int, int >
#define ld long double
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
signed main() {
  cin.tie(0), ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  int N, K;
  cin >> N >> K;
  vec< int > a(N);
  REP(i, N) cin >> a[i];
  vec< int > l(N + 1, 0);
  vec< int > r(N + 1, 0);
  REP(i, N) {
    l[i + 1] = l[i] + (a[i] > 0 ? a[i] : 0);
    r[i + 1] = r[i] + (a[N - 1 - i] > 0 ? a[N - 1 - i] : 0);
  }
  int val = 0;
  REP(i, K) val += a[i];
  int ans = (val > 0 ? val : 0) + l[0] + r[N - K];
  REP(i, N - K) {
    val += -a[i] + a[i + K];
    chmax(ans, (val > 0 ? val : 0) + l[i + 1] + r[N - K - i - 1]);
  }
  print(ans);
}