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
  vector<int> id(N, -1);
  int sz = 0;
  for (int i = 0; i < N; i++) {
    if (id[i] != -1) {
      continue;
    }
    queue<int> q;
    id[i] = sz;
    q.push(i);
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      for (int u : G1[v]) {
        if (id[u] == -1) {
          id[u] = sz;
          q.push(u);
        }
      }
    }
    ++sz;
  }
  vector<int> cnt(sz, 0), res(N);
  vector<bool> used(N, false);
  for (int i = 0; i < N; i++) {
    if (used[i]) {
      continue;
    }
    vector<int> vs;
    vs.push_back(i);
    used[i] = true;
    for (int j = 0; j < vs.size(); j++) {
      int v = vs[j];
      for (int u : G2[v]) {
        if (!used[u]) {
          vs.push_back(u);
          used[u] = true;
        }
      }
    }
    for (int v : vs) {
      ++cnt[id[v]];
    }
    for (int v : vs) {
      res[v] = cnt[id[v]];
    }
    for (int v : vs) {
      --cnt[id[v]];
    }
  }
  for (int x : res) {
    cout << x << " ";
  }
  cout << endl;
  return 0;
}
