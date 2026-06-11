#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

#define MOD 1000000007
#define INF 1000000007
#define REP(i, N) for (int i = 0; i < N; ++i)
#define REP1(i, N) for (int i = 1; i <= N; ++i)
#define RREP(i, N) for (int i = N - 1; i >= 0; --i)
#define ALL(a) a.begin(), a.end()

vector<int> G[100000];
int n, m;
int v[100000], d[100000], c[100000];
int dp[100000][11];

void dfs(int cur, int dist, int cnt) {
  dp[cur][dist] = cnt;
  if (dist == 0) return;
  if (dp[cur][dist - 1] == -1) {
    dfs(cur, dist - 1, cnt);
  }
  REP(i, G[cur].size()) {
    int nxt = G[cur][i];
    if (dp[nxt][dist - 1] == -1) {
      dfs(nxt, dist - 1, cnt);
    }
  }
}

int main() {
  cin >> n >> m;
  REP(i, m) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  int q;
  cin >> q;
  REP(i, q) {
    cin >> v[i] >> d[i] >> c[i];
    v[i]--;
  }
  REP(i, n) REP(j, 11) dp[i][j] = -1;
  RREP(i, q) {
    if (dp[v[i]][d[i]] == -1) dfs(v[i], d[i], i);
  }
  REP(i, n) cout << (dp[i][0] == -1 ? 0 : c[dp[i][0]]) << endl;
  return 0;
}