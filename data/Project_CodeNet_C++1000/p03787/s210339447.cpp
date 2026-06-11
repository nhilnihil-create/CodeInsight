#include <algorithm>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>
using namespace std;
using ll = long long;

int main() {
  int N, M;
  while (cin >> N >> M) {
    vector<vector<int>> G(N);
    for (int i = 0; i < M; i++) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      G[a].push_back(b);
      G[b].push_back(a);
    }
    vector<int> depth(N, -1);
    function<pair<int, int>(int, int, int)> dfs = [&](int v, int p, int d) {
      depth[v] = d;
      int cnt = 1;
      bool oddloop = false;
      for (int u : G[v]) {
        if (u == p) continue;
        if (depth[u] != -1) {
          oddloop |= (d - depth[u]) % 2 == 0;
        } else {
          auto ch = dfs(u, v, d + 1);
          cnt += ch.first;
          oddloop |= ch.second;
        }
      }
      return make_pair(cnt, oddloop);
    };
    ll sum = 0, oddloop = 0, trivial = 0;
    for (int i = 0; i < N; i++) {
      if (depth[i] != -1) continue;
      auto res = dfs(i, -1, 0);
      if (res.first == 1) continue;
      sum += res.first;
      if (res.second) {
        ++oddloop;
      } else {
        ++trivial;
      }
    }
    ll res = 1ll * N * N - sum * sum;
    res += 2 * (oddloop + trivial) * (oddloop + trivial) -
           2 * oddloop * (oddloop + trivial) + oddloop * oddloop;
    cout << res << endl;
  }
  return 0;
}
