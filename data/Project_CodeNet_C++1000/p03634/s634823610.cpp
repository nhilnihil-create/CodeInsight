#include <iostream>
#include <vector>

using namespace std;

#define ll long long

struct edge {
  int to;
  ll cost;
};

vector<edge> tree[100010];
ll cost_k[100010];

void dfs(int v, int par, ll dist) {
  cost_k[v] = dist;

  for (int i = 0; i < (int)tree[v].size(); i++) {
    if (tree[v][i].to == par)continue;
    dfs(tree[v][i].to, v, dist + tree[v][i].cost);
  }
}

int main(void) {
  int N;
  cin >> N;

  for (int i = 0; i < N - 1; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    tree[a].push_back({ b, c });
    tree[b].push_back({ a, c });
  }
  int Q, K;
  cin >> Q >> K;
  K--;

  dfs(K, -1, 0);

  for (int i = 0; i < Q; i++) {
    int x, y;
    cin >> x >> y;
    x--; y--;
    cout << cost_k[x] + cost_k[y] << endl;
  }
}
