#include "bits/stdc++.h"
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000
#define int long long 
struct edge { int from, to, cost; };

edge es[2010]; // 辺

int d[1010];   // 最短距離
int V, E;

// s番目の頂点から各頂点への最短距離を求める
bool shortest_path(int s) {
    for (int i = 0; i < V; i++) d[i] = INF2;
    d[s] = 0;
    int cnt = 0;
    int prev = d[V - 1];
    while (true) {
        bool update = false;
        for (int i = 0; i < E; i++) {
            edge e = es[i];
            if (d[e.from] != INF2 && d[e.to] > d[e.from] + e.cost) {
                d[e.to] = d[e.from] + e.cost;
                update = true;
            }
        }
        if (!update) break;
        cnt++;
        if(cnt == V) prev = d[V - 1];
        if(cnt > V * 2 && prev != d[V - 1]) {
            cout << "inf" << endl;
            return false;
        } else if(cnt > V * 2) return true;
        //prev = d[V - 1];
    }
    return true;
}

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> V >> E;
    rep(i, E) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        es[i] = {a, b, -c};
    }
    if(!shortest_path(0)) return 0;
    cout << -d[V - 1] << endl;

    return 0;
}
