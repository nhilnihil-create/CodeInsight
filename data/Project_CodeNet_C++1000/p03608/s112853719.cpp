#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = 1; i <= (n); ++i)
#define drep(i, n) for (int i = (n)-1; i >= 0; --i)
#define srep(i, s, t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(), a.end()
#define rrng(a) a.rbegin(), a.rend()
#define maxs(x, y) (x = max(x, y))
#define mins(x, y) (x = min(x, y))
#define limit(x, l, r) max(l, min(x, r))
#define lims(x, l, r) (x = max(l, min(x, r)))
#define isin(x, l, r) ((l) <= (x) && (x) < (r))
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcountll
#define uni(x) x.erase(unique(rng(x)), x.end())
#define show(x) cout << #x << " = " << x << endl;
#define print(x) cout << x << endl;
#define PQ(T) priority_queue<T, v(T), greater<T> >
#define bn(x) ((1 << x) - 1)
#define dup(x, y) (((x) + (y)-1) / (y))
#define newline puts("")
#define v(T) vector<T>
#define vv(T) v(v(T))
using namespace std;
typedef long long int ll;
typedef unsigned uint;
typedef unsigned long long ull;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
typedef vector<T> vt;

ll d[210][210];
int main() {
  int n, m, r;
  cin >> n >> m >> r;
  vi R(r);
  rep(i, r) {
    cin >> R[i];
    R[i]--;
  }
  rep(i, n) {
    rep(j, n) {
      if (i == j)
        d[i][j] = 0;
      else
        d[i][j] = 1LL << 60;
    }
  }
  rep(i, m) {
    int a, b;
    ll c;
    cin >> a >> b >> c;
    a--;
    b--;
    d[a][b] = c;
    d[b][a] = c;
  }

  rep(k, n) {
    rep(i, n) {
      rep(j, n) { d[i][j] = min(d[i][j], d[i][k] + d[k][j]); }
    }
  }
  ll ans = 1LL << 60;
  sort(rng(R));
  do {
    ll cost = 0;
    rep(i, r - 1) { cost += d[R[i]][R[i + 1]]; }
    mins(ans, cost);
  } while (next_permutation(R.begin(), R.end()));
  cout << ans << endl;
  return 0;
}