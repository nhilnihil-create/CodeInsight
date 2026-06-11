//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<int>;
using vvi = vector<vi>;

struct edge{
    int from, to;
    int64_t cost;
    edge(int a=0, int b=0, int64_t c=0LL):from(a), to(b), cost(c) {}
};

// サイズ,辺の情報,初期化の必要あり
vector<edge> es;

const int64_t INF = INT64_MAX/10LL;

// sは始点,vは頂点数
vector<int64_t> bellman(int s, int v) {
    vector<int64_t> d(v, INF);
    int E = es.size();
    d[s] = 0LL;
    int cou = 0;
    while(true) {
        bool update = false;
        bool ch = false;
        for(int i = 0; i < E; ++i) {
            edge e = es[i];
            if(d[e.from] != INF && d[e.to] > d[e.from] + e.cost) {
                d[e.to] = d[e.from] + e.cost;
                update = true;
                if(e.to == v-1) ch = true;
            }
        }
        if(!update) break;
        if(cou == 2*v) {
            if(ch) d[s] = INF;
            break;
        }
        cou++;
    }
    return d;
}



int main() {
    int n, m;
    cin >> n >> m;
    es.resize(m);
    rep(i, m) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        --a;
        --b;
        es[i] = edge(a, b, -c);
    } 

    vector<ll> d = bellman(0, n);
    if(d[0] == INF) {
        cout << "inf" << endl;
    } else {
        cout << -d[n-1] << endl;
    }
}