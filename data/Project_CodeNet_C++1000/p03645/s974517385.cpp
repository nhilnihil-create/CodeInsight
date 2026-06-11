//グラフ
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int V, E;
    cin >> V >> E;
 
    vector<vector<int>> G(V);
    for (int i = 0; i < E; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back({b});
        G[b].push_back({a});
    }
    vector<int> dist(V, -1);
    queue<int> q;
    dist[0]=0;
    q.push(0);
    while (!q.empty()) {
        int v = q.front(); // キューから先頭頂点を取り出す
        q.pop();

        // v から辿れる頂点をすべて調べる
        for (int nv : G[v]) {
            if (dist[nv] != -1) continue; // すでに発見済みの頂点は探索しない

            // 新たな白色頂点 nv について距離情報を更新してキューに追加する
            dist[nv] = dist[v] + 1;
            q.push(nv);
        }
    }

    if(dist[V-1]==2){
        cout << "POSSIBLE" << endl;
    }
    else{
        cout << "IMPOSSIBLE" << endl;
    }
}
