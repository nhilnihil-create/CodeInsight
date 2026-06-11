#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)
#define DUMP(a, n) REP(i, n) printf("%d%c", a[i], i + 1 == n ? '\n' : ' ')

const int N_MAX = 100000;

int N, K;
int a[N_MAX];

vector<int> rG[N_MAX];
int dist[N_MAX];
pair<int, int> dv[N_MAX];
int ans;

void rdfs(int v, int d) {
  dist[v] = d;
  REP(i, rG[v].size()) {
    rdfs(rG[v][i], d + 1);
  }
}

void dfs(int v, int d) {
  if (dist[v] <= d) return;
  dist[v] = d;
  if (d == 1) {
    if (a[v] != 0) {
      a[v] = 0;
      ans++;
    }
    return;
  }
  dfs(a[v], d - 1);
}

void solve() {
  ans = 0;
  if (a[0] != 0) {
    a[0] = 0;
    ans++;
  }

  FOR(i, 1, N - 1) rG[a[i]].push_back(i);
  rdfs(0, 0);

  REP(i, N) dv[i] = make_pair(dist[i], i);
  sort(dv, dv + N);

  for (int i = N - 1; i >= 0; i--) {
    int v = dv[i].second;
    if (dist[v] > K) dfs(v, K);
  }
  printf("%d\n", ans);
}

void input() {
  scanf("%d%d", &N, &K);
  REP(i, N) {
    scanf("%d", a + i);
    a[i]--;
  }
}

int main() {
  input();
  solve();
  return 0;
}
