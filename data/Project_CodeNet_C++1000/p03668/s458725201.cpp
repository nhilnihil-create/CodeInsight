//#define __USE_MINGW_ANSI_STDIO 0
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
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
#define INF (1LL<<30)
#define LLINF (1LL<<60)
#define PI 3.14159265359
#define EPS 1e-12
//#define int ll

template <typename T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template <typename T> T &chmax(T &a, const T &b) { return a = max(a, b); }

int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

VI g[100010];
bool used[100010];
int dfs(int num) {
  // cout << num << endl;
  used[num] = true;
  bool update = false;
  int res = 0;
  for(int i: g[num]) {
    if(used[i]) continue;
    update = true;
    res ^= dfs(i)+1;
  }
  // 葉
  if(!update) return 0;
  return res;
}

signed main(void)
{
  int n;
  cin >> n;
  REP(j, n) g[j].clear();
  memset(used, false, sizeof(used));
  REP(j, n-1) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].PB(v);
    g[v].PB(u);
  }
  // cout << dfs(0) << endl;
  if(dfs(0)) cout << "Alice" << endl;
  else cout << "Bob" << endl;

  return 0;
}
