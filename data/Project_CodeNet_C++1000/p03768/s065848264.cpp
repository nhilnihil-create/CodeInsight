#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <iomanip>
#include <functional>
#include <cassert>
#include <bitset>

using namespace std;

typedef long long ll;

const int N = 1e5 + 7;
const int K = 11;
vector <int> g[N];
int mem[N][K];

void go(int u, int x, int c) {
  if (mem[u][x]) return;
  mem[u][x] = c;
  if (x > 0) {
    go(u, x - 1, c);
    for (auto v : g[u]) {
      go(v, x - 1, c);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int q;
  cin >> q;
  vector <int> v(q), d(q), c(q);
  for (int i = 0; i < q; ++i) cin >> v[i] >> d[i] >> c[i];
  for (int i = q - 1; i >= 0; --i) {
    go(v[i] - 1, d[i], c[i]);
  }
  for (int i = 0; i < n; ++i) {
    cout << mem[i][0] << '\n';
  }
}
