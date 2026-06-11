#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>

using namespace std;

struct Paint {
  int v;
  int d;
  int c;
};

const int kMaxN = 1e5 + 11;

bool used[kMaxN][12];
vector <int> g[kMaxN];
int colors[kMaxN];
bool finalized[kMaxN];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  int q;
  cin >> q;
  vector<Paint> paints(q);

  for (auto& p : paints) {
    cin >> p.v >> p.d >> p.c;
    p.v--;
  }

  std::reverse(paints.begin(), paints.end());

  for (const auto& cur : paints) {
    int from = cur.v;
    if (!used[from][cur.d]) {
      std::queue <pair<int, int>> bfs;
      bfs.emplace(from, cur.d);
      used[from][cur.d] = true;
      while (!bfs.empty()) {
        auto top = bfs.front();
        bfs.pop();
        if (!finalized[top.first]) {
          colors[top.first] = cur.c;
          finalized[top.first] = true;
        }
        if (top.second == 0) {
          continue;
        }

        for (auto to : g[top.first]) {
          if (!used[to][top.second - 1]) {
            bfs.emplace(to, top.second - 1);
            used[to][top.second - 1] = true;
          }
        }
      }
    }
  }

  for (int i = 0; i < n; i++) {
    cout << colors[i] << "\n";
  }
  cout << endl;

  return 0;
}