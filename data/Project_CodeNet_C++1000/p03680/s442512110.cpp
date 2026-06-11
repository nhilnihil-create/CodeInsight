
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long int;
using Graph = vector<vector<int>>;

int main() {
  // 頂点数と辺数
  int N;
  cin >> N;

  // グラフ入力受取 (ここでは無向グラフを想定)
  Graph G(N);
  for (int i = 0; i < N; ++i) {
    int a;
    cin >> a;
    a--;
    G[i].push_back(a);
  }

  // BFS のためのデータ構造
  vector<int> dist(N, -1);  // 全頂点を「未訪問」に初期化
  queue<int> que;

  // 初期条件 (頂点 0 を初期ノードとする)
  dist[0] = 0;
  que.push(0);  // 0 を橙色頂点にする

  // BFS 開始 (キューが空になるまで探索を行う)
  while (!que.empty()) {
    int v =
        que.front();  // キューから先頭頂点を取り出す(front()では削除されない)
    que.pop();  // 先頭を削除

    // v から辿れる頂点をすべて調べる
    for (int nv : G[v]) {
      if (dist[nv] != -1) continue;  // すでに発見済みの頂点は探索しない

      // 新たな白色頂点 nv について距離情報を更新してキューに追加する
      dist[nv] = dist[v] + 1;
      que.push(nv);

    }
  }
  cout << dist[1];
}