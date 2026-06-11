#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 1e5 + 5;

vector<int> adj [MAX_N];
bool vis [MAX_N][12];
int color [MAX_N];

void paint (int v, int d, int c) {
  if (vis[v][d]) return;
  vis[v][d] = 1;
  if (color[v] == 0) color[v] = c;

  if (d != 0) {
    for (int nxt : adj[v]) {
      paint(nxt, d - 1, c);
    }
  }
}

int main () {
  ios::sync_with_stdio(false);
  
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<pair<int, pair<int, int>>> queries;
  int qc;
  cin >> qc;

  for (int i = 0; i < qc; i++) {
    int v, d, c;
    cin >> v >> d >> c;
    queries.push_back(make_pair(v, make_pair(d, c)));
  }

  reverse(queries.begin(), queries.end());
  for (auto pr : queries) {
    paint(pr.first, pr.second.first, pr.second.second);
  }

  for (int i = 1; i <= n; i++) {
    cout << color[i] << '\n';
  }
}
