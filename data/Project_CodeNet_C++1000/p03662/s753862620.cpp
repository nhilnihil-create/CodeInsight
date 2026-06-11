#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 1e5 + 5;

vector<int> adj [MAX_N];
int color [MAX_N];

int n;
vector<int> path1n;
void find_path (int u, int p) {
  path1n.push_back(u);
  for (int nxt : adj[u]) {
    if (nxt != p) {
      find_path(nxt, u);
    }
  }
  if (path1n.back() != n) {
    path1n.pop_back();
  }
}

void flood (int u, int c) {
  color[u] = c;
  for (int nxt : adj[u]) {
    if (color[nxt] == 0) {
      flood(nxt, c);
    }
  }
}

int main () {
  ios::sync_with_stdio(false);

  cin >> n;

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  find_path(1, 1);

  for (int i = 0; i < (int) (path1n.size() + 1) / 2; i++) {
    color[path1n[i]] = 1;
  }

  for (int i = (int) (path1n.size() + 1) / 2; i < (int) path1n.size(); i++) {
    color[path1n[i]] = -1;
  }

  for (int u : path1n) {
    flood(u, color[u]);
  }

  int cnt1 = 0, cntn = 0;
  for (int i = 1; i <= n; i++) {
    if (color[i] == 1) cnt1++;
    if (color[i] == -1) cntn++;
  }

  if (cnt1 > cntn) cout << "Fennec" << endl;
  else cout << "Snuke" << endl;
}
