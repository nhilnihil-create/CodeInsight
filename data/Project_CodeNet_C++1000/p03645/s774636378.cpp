#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int N,M;
vector<int> Graph[220000];
int dist[220000];

void DFS() {
  dist[0] = 0;
  queue<P> que;
  que.push(make_pair(0,0));
  while (!que.empty()) {
    P p = que.front();
    que.pop();
    if (p.S > dist[p.F]) {
      continue;
    }
    for (int i = 0; i < (int)Graph[p.F].size(); i++) {
      if (dist[Graph[p.F][i]] > p.S + 1) {
        dist[Graph[p.F][i]] = p.S + 1;
        que.push(make_pair(Graph[p.F][i],p.S+1));
      }
    }
  }
}

int main() {
  int N,M;
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    int a,b;
    cin >> a >> b;
    a--; b--;
    Graph[a].push_back(b);
    Graph[b].push_back(a);
  }

  for (int i = 0; i < N; i++) {
    dist[i] = 10000000;
  }

  DFS();

  if (dist[N-1] <= 2) {
    cout << "POSSIBLE" << endl;
  } else {
    cout << "IMPOSSIBLE" << endl;
  }
  return 0;
}