#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()

typedef long long ll;

const int N = 2e5;
vector<int> edges[N];
int n, diam;
vector<int> dst;
vector<int> d[N];

vector<int> bfs(int s) {
  dst = vector<int>(n, -1); dst[s] = 0; queue<int> q; q.push(s);
  while (!q.empty()) {
    int v = q.front(); q.pop();
    for (int u : edges[v]) {
      if (dst[u] == -1) {
        q.push(u); dst[u] = dst[v] + 1;
      }
    }
  }
  return dst;
}

void solve() {
  cin >> n >> diam;
  for (int i = 0; i < n - 1; i++) {
    int v, u; cin >> v >> u; v--, u--;
    edges[v].push_back(u); edges[u].push_back(v);
  }
  int ans = n;
  for (int v = 0; v < n; v++) {
    d[v] = bfs(v);
    int res = 0;
    for (int u = 0; u < n; u++) {
      if (d[v][u] > diam / 2)
        res++;
    }
    ans = min(ans, res);
  }
  for (int v = 0; v < n; v++) {
    for (int u : edges[v]) {
      int res = 0;
      for (int k = 0; k < n; k++) {
        if (min(d[v][k], d[u][k]) > (diam - 1) / 2)
          res++;
      }
      ans = min(ans, res);
    }
  }
  cout << ans;
}

// CHECK LIMITS (n <= 10^5)
// CHECK CORNER CASES (n == 1)

int main() {
  ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);
  cout.setf(ios::fixed), cout.precision(20);
  //cout << 1.0 * clock() / CLOCKS_PER_SEC << endl;
  solve();
}
