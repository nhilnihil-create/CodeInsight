#include <bits/stdc++.h>
using namespace std;
#define SORT(a) sort((a).begin(), (a).end())
#define RSORT(a) reverse((a).begin(), (a).end())
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
const long long INF = 1LL << 60;
// const int INF=1010101010;
using Graph = vector<vector<int>>;

#define MAX_V 100010

struct edge {
  int to;
  long long cost;
};
typedef pair<long long, int> P;  // first は最短距離, second は頂点番号

vector<edge> tree[MAX_V];
long long d[MAX_V];
int n;

// s: 開始地点の頂点
void dijkstra(int s) {
  // greater<P> を指定することで first が小さい順に取り出せるようにする
  priority_queue<P, vector<P>, greater<P>> que;
  fill(d, d + n, INF);
  d[s] = 0;
  que.push(P(0, s));

  while (!que.empty()) {
    P p = que.top();
    que.pop();
    int v = p.second;
    if (d[v] < p.first) {
      continue;
    }
    for (int i = 0; i < tree[v].size(); i++) {
      edge e = tree[v][i];
      if (d[e.to] > d[v] + e.cost) {
        d[e.to] = d[v] + e.cost;
        que.push(P(d[e.to], e.to));
      }
    }
  }
}

int main() {
  cin >> n;

  for (int i = 0; i < n - 1; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    tree[a].push_back(edge{b, c});
    tree[b].push_back(edge{a, c});
  }
  int q, k;
  cin >> q >> k;
  dijkstra(k - 1);
  for (int i = 0; i < q; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    cout << d[x] + d[y] << endl;
  }
  return 0;
}