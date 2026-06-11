#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

const int N = 1e3 + 5;

vector < vector < pair < int, int > > > adj (N);
vector < ll > d (N, LLONG_MAX);
vector < int > color (N);

void dfs (int u) {
  color[u] = 1;
  for (auto edge : adj[u]) {
    int to = edge.first, len = edge.second;
    if (d[to] == LLONG_MIN) continue;
    if (d[u] == LLONG_MIN || d[u] + len < d[to]) {
      if (color[to] == 1 || d[u] == LLONG_MIN) {
        d[to] = LLONG_MIN;
      } else {
        d[to] = d[u] + len;
      }
      dfs (to);
    }
  }
  color[u] = 2;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v, wt;
    cin >> u >> v >> wt;
    adj[u].push_back ({v, -wt});
  }

  for (int i = 1; i < N; i++) {
    sort (adj[i].begin(), adj[i].end(), [] (const pair < int, int > lhs, const pair < int, int > rhs) -> bool {
            return lhs.second < rhs.second;
          });
  }

  d[1] = 0;
  dfs (1);

  if (d[n] == LLONG_MIN) cout << "inf\n";
  else cout << -d[n] << '\n';
}
