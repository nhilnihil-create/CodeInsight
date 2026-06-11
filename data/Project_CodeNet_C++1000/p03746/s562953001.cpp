#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

using P = pair<int, int>;

// Hamiltom Path
int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int>> graph(N, vector<int>());
  for (int i = 0; i < M; i++) {
    int A, B;
    cin >> A >> B;
    A--;
    B--;
    graph[A].push_back(B);
    graph[B].push_back(A);
  }
  deque<P> q;
  int u = 0;
  int v = graph[0][0];
  q.push_front(make_pair(u, v));
  vector<int> visited(N, 0);
  visited[u] = 1;
  visited[v] = 1;
  while (true) {
    bool flag = false;
    for (int i = 0; i < graph[u].size(); i++) {
      int uu = graph[u][i];
      if (visited[uu] == 0) {
        q.push_front(make_pair(uu, u));
        u = uu;
        visited[u] = 1;
        flag = true;
        break;
      }
    }
    for (int j = 0; j < graph[v].size(); j++) {
      int vv = graph[v][j];
      if (visited[vv] == 0) {
        q.push_back(make_pair(v, vv));
        v = vv;
        visited[v] = 1;
        flag = true;
        break;
      }
    }
    if (!flag) break;
  }
  cout << q.size() + 1 << endl;
  auto init = q.front();
  cout << init.first + 1 << ' ';
  while (q.size() != 0) {
    auto x = q.front();
    q.pop_front();
    cout << x.second + 1 << ' ';
  }
  cout << endl;
  return 0;
}
