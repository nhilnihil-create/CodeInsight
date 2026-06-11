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
signed main() {
  cin.tie(0), ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  string s;
  cin >> s;
  int N = (int)s.size();
  string ans[2] = {"First", "Second"};
  // vec< vec< int > > a(26, vec< int >());
  // vec< pair< int, int > > E;
  // REP(i, N) { a[s[i] - 'a'].pb(i); }
  // REP(i, 26) {
  //   REP(j, (int)a[i].size() - 1) { E.pb(mp(a[i][j + 1], a[i][j])); }
  // }
  // sort(ALL(E));

  // // REP(i, (int)E.size()) { cout << E[i].fst << " " << E[i].snd << "\n"; }
  // int begin = -1;
  // int counttmp = 0;
  // set< int > count;
  // count.insert(0);
  // count.insert(N - 1);
  // REP(i, (int)E.size()) {
  //   if (begin <= E[i].snd) {
  //     begin = E[i].fst;
  //     count.insert(E[i].fst);
  //     count.insert(E[i].snd);
  //     counttmp++;
  //   }
  // }
  // DEBUG((N - count.size() - counttmp));
  // print(ans[(1 + N - count.size() - counttmp) % 2]);
  if (s[0] == s.back()) {
    print(ans[N % 2]);
  } else {
    print(ans[(1 + N) % 2]);
  }
}