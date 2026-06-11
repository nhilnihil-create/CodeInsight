#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>
using namespace std;
using ll = long long;

vector<int> solve(const vector<vector<int>> &G) {
  const int N = G.size();
  vector<int> id(N, -1);
  int sz = 0;
  for (int i = 0; i < N; i++) {
    if (id[i] != -1) {
      continue;
    }
    queue<int> q;
    q.push(i);
    id[i] = sz;
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      for (int u : G[v]) {
        if (id[u] == -1) {
          q.push(u);
          id[u] = sz;
        }
      }
    }
    ++sz;
  }
  return id;
}

int main() {
  int N, K, L;
  cin >> N >> K >> L;
  vector<vector<int>> G1(N), G2(N);
  for (int i = 0; i < K; i++) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    G1[a].push_back(b);
    G1[b].push_back(a);
  }
  for (int i = 0; i < L; i++) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    G2[a].push_back(b);
    G2[b].push_back(a);
  }
  vector<int> id1 = solve(G1);
  vector<int> id2 = solve(G2);
  map<pair<int, int>, int> cnt;
  for (int i = 0; i < N; i++) {
    ++cnt[make_pair(id1[i], id2[i])];
  }
  for (int i = 0; i < N; i++) {
    cout << cnt[make_pair(id1[i], id2[i])] << " ";
  }
  cout << endl;
  return 0;
}
