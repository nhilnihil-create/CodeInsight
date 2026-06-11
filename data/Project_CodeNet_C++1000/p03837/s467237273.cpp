#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()

typedef long long ll;

const int N = 100, INF = 1e9;
int a[N][N];

void solve() {
  int n, m; cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      a[i][j] = INF;
    a[i][i] = 0;
  }
  vector<pair<pair<int, int> , int> > edges;
  for (int i = 0; i < m; i++) {
    int v, u, c; cin >> v >> u >> c; v--, u--;
    edges.push_back({{v, u}, c});
    a[v][u] = a[u][v] = c;
  }
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
  }
  int badedges = 0;
  for (auto e : edges) {
    int v = e.first.first, u = e.first.second, c = e.second;
    int flag = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (a[i][v] + c + a[u][j] == a[i][j])
          flag = 1;
      }
    }
    if (!flag) badedges++;
  }
  cout << badedges;
}

// CHECK LIMITS (n <= 10^5)
// CHECK CORNER CASES (n == 1)

int main() {
  ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);
  cout.setf(ios::fixed), cout.precision(20);
  //cout << 1.0 * clock() / CLOCKS_PER_SEC << endl;
  solve();
}
