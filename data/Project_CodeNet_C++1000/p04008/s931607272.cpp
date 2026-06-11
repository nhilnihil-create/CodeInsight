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
const int INF = 1 << 25;

int main() {
  int N, K;
  while (cin >> N >> K) {
    vector<vector<int>> G(N), rG(N);
    for (int i = 0; i < N; i++) {
      int a;
      cin >> a;
      --a;
      G[i].push_back(a);
      rG[a].push_back(i);
    }
    vector<int> dist(N, INF);
    dist[0] = 0;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      for (int u : rG[v]) {
        if (dist[v] + 1 < dist[u]) {
          dist[u] = dist[v] + 1;
          q.push(u);
        }
      }
    }
    auto comp = [&](int a, int b) {
      if (dist[a] != dist[b]) {
        return dist[a] > dist[b];
      }
      return a > b;
    };
    set<int, decltype(comp)> S(comp);
    for (int i = 1; i < N; i++) {
      S.insert(i);
    }
    int res = 0;
    if (G[0][0] != 0) {
      ++res;
    }
    while (!S.empty() && dist[*S.begin()] > K) {
      int v = *S.begin();
      for (int i = 0; i < K - 1; i++) {
        v = G[v][0];
      }
      queue<int> q;
      q.push(v);
      while (!q.empty()) {
        int v = q.front();
        q.pop();
        S.erase(v);
        for (int u : rG[v]) {
          if (S.count(u)) {
            q.push(u);
          }
        }
      }
      ++res;
    }
    cout << res << endl;
  }
  return 0;
}
