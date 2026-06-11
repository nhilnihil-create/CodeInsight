#include <bits/stdc++.h>
using namespace std;

// ----------- define --------------
#define int long long
#define vi vector<int>
#define vc vector<char>
#define ii pair<int,int>
#define fi first
#define sc second
#define stoi stoll
#define all(x) (x).begin(),(x).end()
#define get_bit(x, k) ((x >> k) & 1)
// ---------------------------------

struct edge {
  int u, v, w;
  edge() {}
  edge(int u, int v, int w):
    u(u), v(v), w(w) {}
};

bool chmax(int &a, int b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}

void MAIN() {
  int n, m;
  cin >> n >> m;
  vector<edge> edges(m);
  for (auto &i : edges) {
    cin >> i.u >> i.v >> i.w;
  }
  vector<int> dis(n + 1, -1e15);
  dis[1] = 0;
  for (int i = 1; i < n; i++)
  for (auto &j : edges) {
    if (dis[j.u] != -1e15) {
      chmax(dis[j.v], dis[j.u] + j.w);
    }
  }
  vector<int> tmp(all(dis));
  for (int i = 1; i < n; i++)
  for (auto &j : edges) {
    if (tmp[j.u] != -1e15) {
      chmax(tmp[j.v], tmp[j.u] + j.w);
    }
  }
  if (dis[n] == tmp[n]) cout << dis[n] << '\n';
  else cout << "inf" << '\n';
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) MAIN();
}
