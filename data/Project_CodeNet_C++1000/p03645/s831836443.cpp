#include <bits/stdc++.h>
using namespace std;
int main() {
  int N,M,a,b;
  cin >> N;
  vector<int> G[N];
  for (cin >> M; M; M--) {
    cin >> a >> b;
    G[--a].push_back(--b);
    G[b].push_back(a);
  }
  queue<int> q;
  int d[N];
  vector<bool> visited(N);
  for (q.push(0), d[0] = 0, visited[0] = true; !q.empty(); q.pop()) {
    for (int v : G[q.front()]) {
      if (!visited[v]) {
        visited[v] = true;
        q.push(v);
        d[v] = d[q.front()]+1;
      }
    }
  }
  if (d[N-1] == 2) {
    cout << "POSSIBLE";
  } else {
    cout << "IMPOSSIBLE";
  }
}