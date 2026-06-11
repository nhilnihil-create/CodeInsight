//#define __USE_MINGW_ANSI_STDIO 0
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VL;
typedef vector<VL> VVL;
typedef pair<int, int> PII;

#define FOR(i, a, n) for (ll i = (ll)a; i < (ll)n; ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(x) x.begin(), x.end()
#define IN(a, b, x) (a<=x&&x<b)
#define MP make_pair
#define PB push_back
#ifdef int
const ll INF = (1LL<<60);
#else
const int INF = (1LL<<30);
#endif
const double PI = 3.14159265359;
const double EPS = 1e-12;
const int MOD = 1000000007;

template <typename T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template <typename T> T &chmax(T &a, const T &b) { return a = max(a, b); }

int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

VI g[100010];
int a[100010], root;

int dfs(int v, int p) {
  int res = (g[v].size()>1) ? 2*a[v] : a[v];
  for(int i: g[v]) {
    if(i == p) continue;
    int tmp = dfs(i, v);
    if(tmp>a[v]) {
      cout << "NO" << endl;
      exit(0);
    }
    res -= tmp;
  }
  if(res < 0 || res > a[v]) {cout << "NO" << endl; exit(0);}
  return res;
}

signed main(void)
{
  int n;
  cin >> n;
  REP(i, n) cin >> a[i];
  REP(i, n-1) {
    int p, q;
    cin >> p >> q;
    p--, q--;
    g[p].PB(q);
    g[q].PB(p);
  }
  if(n == 2) {
    if(a[0] == a[1]) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
  }
  root = 0;
  while(g[root].size() == 1) root++;
  if(dfs(root, -1)) cout << "NO" << endl;
  else cout << "YES" << endl;

  return 0;
}
