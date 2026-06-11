#include <bits/stdc++.h>
using namespace std;
int64_t INF = 1000000000000000;
int64_t MAXN = 100010;
int64_t N, Q, K, a, b, c, x, y;
vector<vector<pair<int64_t, int64_t>>> Graph(MAXN);
vector<int64_t> Color(MAXN, 0), D(MAXN, INF); // 各点を無限大にする。

void dijkstra()
{
  priority_queue<pair<int64_t, int64_t>, vector<pair<int64_t, int64_t>>, greater<pair<int64_t, int64_t>>> PQ;

  D.at(K) = 0; // 始点を0とする。
  PQ.push(make_pair(0, K));
  Color.at(K) = 1; // グレーの状態に

  while (!PQ.empty())
  {
    pair<int64_t, int64_t> f = PQ.top();
    PQ.pop();
    int64_t u = f.second; // 未決定の中で、最短経路の頂点
    Color.at(u) = 2;      // 決定済とする
    if (D.at(u) < f.first)
      continue;
    for (int i = 0; i < Graph.at(u).size(); i++)
    {
      int64_t v = Graph.at(u).at(i).first; // uからの辺の終点
      if (Color.at(v) == 2)
        continue;
      if (D.at(v) > D.at(u) + Graph.at(u).at(i).second) // uを経由した場合の距離
      {
        D.at(v) = D.at(u) + Graph.at(u).at(i).second;
        PQ.push(make_pair(D.at(v), v)); // 頂点vの暫定での距離、頂点vをペアにする
        Color.at(v) = 1;                // グレーにする
      }
    }
  }
}

int main()
{
  cin >> N;
  for (int i = 0; i < N - 1; i++)
  {
    cin >> a >> b >> c;
    Graph.at(a).push_back(make_pair(b, c));
    Graph.at(b).push_back(make_pair(a, c));
  }
  cin >> Q >> K;
  vector<pair<int64_t, int64_t>> vp(Q);
  for (int i = 0; i < Q; i++)
  {
    cin >> x >> y;
    vp.at(i) = make_pair(x, y);
  }
  dijkstra();
  for (auto p : vp)
  {
    tie(x, y) = p;
    cout << D.at(x) + D.at(y) << endl;
  }
}
