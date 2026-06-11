#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;
  vector<vector<int>> G(N);
  for (int i = 0; i < N - 1; i++) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  vector<bool> used(N);
  queue<int> f, s;
  f.push(0);
  s.push(N - 1);
  used[0] = used[N - 1] = true;
  int fennec = 0, snuke = 0;
  while (!f.empty() || !s.empty()) {
    queue<int> nf, ns;
    while (!f.empty()) {
      int v = f.front(); f.pop();
      for (int u: G[v]) {
        if (!used[u]) {
          ++fennec;
          used[u] = true;
          nf.push(u);
        }
      }
    }
    while (!s.empty()) {
      int v = s.front(); s.pop();
      for (int u: G[v]) {
        if (!used[u]) {
          ++snuke;
          used[u] = true;
          ns.push(u);
        }
      }
    }
    f = nf;
    s = ns;
  }
  cout << (fennec > snuke ? "Fennec" : "Snuke") << endl;
  return 0;
}
