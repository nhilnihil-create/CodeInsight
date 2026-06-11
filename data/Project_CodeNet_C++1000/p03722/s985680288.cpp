/**
 * ベルマンフォード法
 *  - 概要
 *      - 開始ノードから任意のノードへの最短距離を計算
 *      - へんの重みに負の値がある場合へ対応可能
 *      - 閉路判定可能
 *  - 時間計算量
 *      - O( EV )
 *  - 探索対象
 *      - グラフ (vector)
*/

#include "bits/stdc++.h"
#define REP(i, a, b) for (int i = a; i < b; i++)
using namespace std;
typedef long long ll;

const ll LLINF = 1e18;
const ll NODE_SIZE = 10101;

ll V;  //グラフのノードの数
ll E;  //グラフの辺の数
vector<pair<ll, ll>> edge[NODE_SIZE];   //<ノード, 距離>
ll d[NODE_SIZE];   //始点ノードからノードiへの最短距離
ll start;  //開始ノード番号

bool bellmanford(){
    REP(i,0,V) d[i]=LLINF;
    d[start]=0;

    REP(cnt,0,V){
        REP(from,0,V){
            for(auto e : edge[from]){
                if (d[from]!=LLINF && d[e.first] > d[from] + e.second) {  //移動した後のコストが小さいと、頂点のコストを更新
                    d[e.first] = d[from] + e.second;
                    if (cnt == V-1 && e.first==V-1) {   //頂点の数と同じ回数ループすると、負の閉路があるのでループをぬける
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

int main(){
    cin >> V >> E;
    ll A,B,cost;
    REP(i,0,E) {
        cin >> A >> B >> cost;
        A--;B--;
        edge[A].emplace_back(B, -cost);
    }

    start = 0;

    if(bellmanford()){
        cout << -d[V-1] << endl;
    }else{
        cout << "inf" << endl;
    }
}