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
int N, K;
vec< int > a;
#define MAXN 5000
#define MAXK 5000
bool l[MAXN + 1][MAXK + 1];
bool r[MAXN + 1][MAXK + 1];

bool isOK(int id) {
  if (id == -1)
    return true;
  if (id == N)
    return false;
  bool flg[MAXK + 1] = {false};
  FORS(v0, 0, K) {
    if (!l[id][v0])
      continue;
    FORS(v1, 0, K) {
      if (!r[N - 1 - id][v1])
        continue;
      if (v0 + v1 <= K)
        flg[v0 + v1] = true;
    }
  }
  int begin = K - a[id];
  chmax(begin, 0ll);
  chmin(begin, K);
  int end = K;
  chmax(end, 0ll);
  chmin(end, K);
  int pos = count(flg + begin, flg + end, true);
  return pos <= 0;
}
signed main() {
  cin.tie(0), ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  cin >> N >> K;
  a.resize(N);

  REP(i, N) { cin >> a[i]; }
  sort(ALL(a));
  l[0][0] = true;
  r[0][0] = true;
  REP(i, N) {
    FORS(j, 0, K) { l[i + 1][j] = l[i][j]; }
    FORS(j, 0, K) {
      if (l[i][j]) {
        int val = j + a[i];
        if (val <= K) {
          l[i + 1][val] = true;
        }
      }
    }
  }

  REP(i, N) {
    FORS(j, 0, K) { r[i + 1][j] = r[i][j]; }
    FORS(j, 0, K) {
      if (r[i][j]) {
        int val = j + a[N - 1 - i];
        if (val <= K) {
          r[i + 1][val] = true;
        }
      }
    }
  }

  int left = -1, right = N;
  while (right - left > 1) {
    int mid = (left + right) / 2;
    if (isOK(mid)) {
      left = mid;
    } else {
      right = mid;
    }
  }
  print(right);
}
// https://pyteyon.hatenablog.com/entry/2019/02/20/194140