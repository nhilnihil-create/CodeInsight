#include <bits/stdc++.h>
using namespace std;
#define int long long

int N, K;
vector<int> G[2020];

void rec(int v, int p, int curdepth, vector<int> &depth) {
  depth[v] = curdepth;
  for (auto nv : G[v]) {
    if (nv == p) continue;
    rec(nv, v, curdepth + 1, depth);
  }
}

signed main() {
  cin >> N >> K;
  for (int i = 0; i < N - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  int ans = 1e18;
  vector<int> depth(N);
  if (K % 2 == 0) {
    for (int i = 0; i < N; i++) {
      rec(i, -1, 0, depth);
      int num = 0;
      for (int i = 0; i < N; i++)
        if (depth[i] > K / 2) num++;
      ans = min(ans, num);
    }

  } else {
    for (int u = 0; u < N; u++) {
      for (auto v : G[u]) {
        depth[v] = 0;
        rec(u, v, 0, depth);
        rec(v, u, 0, depth);
        int num = 0;
        for (int i = 0; i < N; i++)
          if (depth[i] > K / 2) num++;
        ans = min(ans, num);
      }
    }
  }

  cout << ans << endl;
  return 0;
}
