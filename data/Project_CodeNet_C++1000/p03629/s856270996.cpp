#include <bits/stdc++.h>
using namespace std;

constexpr int inf = 1001001001;

int to_vertex(char c, int idx) {
  return 26 * idx + (c - 'a');
}

char to_char(int v) {
  return (char)(v % 26 + 'a');
}

int main() {
  string A;
  cin >> A;

  A += '*';
  reverse(A.begin(), A.end());

  int g = 26 * A.size();
  vector<vector<int>> G(g + 1);

  vector<int> pre(26);
  for (int i = 1; i < A.size(); ++i) {
    int v = to_vertex(A[i], i);
    for (char c = 'a'; c <= 'z'; ++c) {
      int u = to_vertex(c, pre[c - 'a']);
      G[u].push_back(v);
      // cerr << "(" << c << ", " << pre[c - 'a'] << ") -> (" << A[i] << ", " << i << ")" << endl;
    }
    pre[A[i] - 'a'] = i;
  }

  for (int c = 'a'; c <= 'z'; ++c) {
    int u = to_vertex(c, pre[c - 'a']);
    G[u].push_back(g);
  }

  queue<int> q;
  vector<int> d(g + 1, inf), p(g + 1, -1);
  for (int i = 0; i < 26; ++i) {
    q.push(i);
    d[i] = 0;
  }

  while (!q.empty()) {
    int from = q.front();
    q.pop();

    for (auto &to : G[from]) {
      if (d[to] < d[from] + 1) continue;

      if (d[to] > d[from] + 1) {
        d[to] = d[from] + 1;
        q.push(to);
      }
      if (p[to] == -1 || p[to] % 26 > from % 26) p[to] = from;
    }
  }

  string ans;
  for (int v = p[g]; v != -1; v = p[v]) {
    ans += to_char(v);
  }

  cout << ans << endl;
}
