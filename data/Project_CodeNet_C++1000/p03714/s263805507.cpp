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
const int MOD = 1000000007, INF = 1061109567;
const double EPS = 1e-10, PI = acos(-1.0);
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
signed main() {
  cin.tie(0), ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  priority_queue< int, vector< int >, greater< int > > queL;
  priority_queue< int > queR;
  int N;
  cin >> N;
  vec< int > a(3 * N);
  vec< int > sumL(N + 1);
  vec< int > sumR(N + 1);
  REP(i, 3 * N) { cin >> a[i]; }
  int ans = 0;
  REP(i, N) {
    ans += a[i];
    queL.push(a[i]);
  }
  sumL[0] = ans;
  ans = 0;
  REP(i, N) {
    ans += a[i + 2 * N];
    queR.push(a[i + 2 * N]);
  }
  sumR[0] = ans;

  REP(i, N) {
    int v0 = a[N + i];
    queL.push(v0);
    int v1 = queL.top();
    queL.pop();
    sumL[i + 1] = sumL[i] + v0 - v1;
  }
  REP(i, N) {
    int v0 = a[2 * N - 1 - i];
    queR.push(v0);
    int v1 = queR.top();
    queR.pop();
    sumR[i + 1] = sumR[i] + v0 - v1;
  }
  ans = sumL[0] - sumR[N];
  REPS(i, N) { chmax(ans, sumL[i] - sumR[N - i]); }
  print(ans);
}