/*
 * ・方針
 * 1. ボタン a を押すと、ボタン b が光るという関係を、
 *    a -> b の有向グラフと捉える
 * 2. 有向グラフをBFSして、頂点2への経路 (ボタン2を光らせるために必要な手順) を探索
 *    ※ 経路が発見できなかった場合 -1 を格納させると、そのまま 出力できて便利
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> A(N+1);
    vector<vector<int> > G(N+1);
    for(int i = 1; i <= N; i++){
        cin >> A[i];
        G[i].push_back(A[i]);
    }

    // BFS のためのデータ構造
    vector<int> dist(N+1, -1); // 全頂点を「未訪問」に初期化
    queue<int> que;

    // 初期条件 (頂点 1 を初期ノードとする)
    dist[1] = 0;
    que.push(1); // 1 を橙色頂点にする

    // BFS 開始 (キューが空になるまで探索を行う)
    while (!que.empty()) {
        int v = que.front(); // キューから先頭頂点を取り出す
        que.pop();

        // v から辿れる頂点をすべて調べる
        for (int nv : G[v]) {
            if (dist[nv] != -1) continue; // すでに発見済みの頂点は探索しない

            // 新たな白色頂点 nv について距離情報を更新してキューに追加する
            dist[nv] = dist[v] + 1;
            que.push(nv);
        }
    }

    // 結果出力 (各頂点の頂点 1 からの距離を見る)
//    for (int v = 1; v <= N; ++v) cout << v << ": " << dist[v] << endl;

    cout << dist[2] << endl;
}