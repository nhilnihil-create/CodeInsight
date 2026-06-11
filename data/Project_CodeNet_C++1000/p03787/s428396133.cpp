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
#define MOD 1000000007
#define INF (1LL<<25)     //33554432
#define PI 3.14159265359
#define EPS 1e-12
//#define int ll

VI g[100010];
int n, m, color[100010], d = 0;
bool e = true;

void dfs(int v, int c) {
  color[v] = c;
  d++;
  for(int i: g[v]) {
    if(color[i] == 0)
      dfs(i, -c);
    if(color[i] == c)
      e = false;
  }
}

signed main(void)
{
  cin >> n >> m;
  REP(i, m) {
    int u, v;
    cin >> u >> v;
    g[u-1].push_back(v-1);
    g[v-1].push_back(u-1);
  }

  ll a = 0, b = 0, c = 0;
  REP(i, n) {
    d = 0; e = true;
    if(color[i] == 0) {
      dfs(i, 1);
      if(d == 1) a++;
      else if(e) b++;
      else c++;
    }
  }
  //cout << a << " " << b << " " << c << endl;
  cout << 2*b*b + 2*b*c + c*c + a*a + 2*a*(n-a) << endl;
  return 0;
}
