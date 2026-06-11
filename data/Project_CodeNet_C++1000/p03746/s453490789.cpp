#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 1e5 + 5;

vector<int> adj [MAX_N];
int vis [MAX_N];

int unvis_nb (int u) {
  for (int nxt : adj[u]) {
    if (!vis[nxt]) return nxt;
  }
  return -1;
}

int main () {
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vis[1] = 1;
  vector<int> ans = {1};

  while (unvis_nb(ans.back()) != -1) {
    int nxt = unvis_nb(ans.back());
    ans.push_back(nxt);
    vis[nxt] = 1;
  }

  reverse(ans.begin(), ans.end());

  while (unvis_nb(ans.back()) != -1) {
    int nxt = unvis_nb(ans.back());
    ans.push_back(nxt);
    vis[nxt] = 1;
  }

  cout << (int) ans.size() << endl;
  for (int u : ans) {
    cout << u << " ";
  }
  cout << endl;
}
