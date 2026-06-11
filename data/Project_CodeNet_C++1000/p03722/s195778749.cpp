#include<bits/stdc++.h>

using namespace std;

#define MAX_N 1001
#define INF 1e16
#define ll long long
struct edge {
    int from; //出発点
    int to;   //到達点
    ll cost; //移動コスト
};

vector<bool> v;
vector<vector<int>> g;
bool dfs(int nowv,int tv){
    // nowvからtvにいけるかどうか調べる
    if(nowv==tv)return true;
    for(int i=0;i<g[nowv].size();i++){
        int next = g[nowv][i];
        if(v[next])continue;
        v[next] = 1;
        if(dfs(next,tv))return true;
        v[next] = 0;
    }
    return false;
}
int main()
{
    int N; //頂点の数
    int M; //辺の数
    int S; //始点
    int G; //終点
    
    vector<edge> edges; //移動の情報を保存する

    cin >> N;
    cin >> M;
    vector<ll> d(N,INF);
    g.resize(N);
    S = 0;
    G = N-1;
    v.resize(N);

    d[S] = 0; //始点を0にする

    for (int i = 0; i < M; i++) {
        struct edge add;
        cin >> add.from;
        cin >> add.to;
        cin >> add.cost;
        add.from--;
        add.to--;
        add.cost *= -1;
        edges.push_back(add);
        g[add.from].push_back(add.to);
    }

    vector<int> inf;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {

            struct edge e = edges[j];

            if (d[e.to] > d[e.from] + e.cost) {  //移動した後のコストが大きいと、頂点のコストを更新
                d[e.to] = d[e.from] + e.cost;
                if (i == N-1) {         //頂点の数と同じ回数ループすると、負の閉路があるのでループをぬける
                    inf.push_back(e.from);
                    break;
                } 
            }
        }
    }
    bool ok = 0;
    for(auto x:inf){
        // xからゴールにいけるかどうかを調べる
        v[x] = 1;
        if(dfs(x,G))ok = 1;
        v[x] = 0;
    }
    if(ok)cout << "inf" << endl;
    else cout << -d[G] << endl;
}
