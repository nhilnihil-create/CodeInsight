#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <math.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ll, ll> P;
typedef vector<int> vi;
typedef vector<vi> vvi;

#define REP(i, n) for (ll i = 0; i < (n); ++i)
#define REPR(i, n) for (ll i = (n) - 1; i >= 0; --i)
#define FOR(i, n, m) for (ll i = (n); i < (m); ++i)
#define FORR(i, n, m) for (ll i = (m) - 1; i >= (n); --i) 
#define FORE(x, xs) for (auto &x: (xs))
#define ALL(v) v.begin(), v.end()
#define ZERO(a) memset(a,0,sizeof(a))

const int INF = 1000000009;
const int MOD = 1000000007;
const double EPS = 1e-14;
const double PI = acos(-1);

const int MAX = 1e5+1;

ll N, M, Q;
vi adj[MAX];
int v, d, c;
int colors[MAX];
int dp[11][MAX];
int main() {
  cin >> N >> M;

  REP (j, 11) REP (i, N) dp[j][i] = INF;

  REP (i, M) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  cin >> Q;
  REPR (i, Q) {
    cin >> v >> d >> colors[i];
    v--;
    dp[d][v] = i;
  }

  FORR (j, 1, 11) {
    REP  (i, N) {
      dp[j-1][i] = min(dp[j-1][i], dp[j][i]);
      REP (k, adj[i].size()) dp[j-1][adj[i][k]] = min(dp[j-1][adj[i][k]], dp[j][i]);
    }
  }

  REP (i, N) {
    int ans = dp[0][i];
    if (ans == INF) cout << 0 << endl;
    else cout << colors[ans] << endl;
  }

  return 0;
}