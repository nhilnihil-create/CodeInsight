#include<iostream>
#include<iomanip>
#include<cstdio>

#include<vector>
#include<queue>
#include<set>
#include<map>
#include<string>

#include<algorithm>
#include<cmath>
#include<numeric>

using namespace std;
typedef long long ll;
template <class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return 1;} return 0;}
template <class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return 1;} return 0;}

struct edge {
    ll from, to, cost;
    edge() {}
    edge(ll f, ll t, ll c) {
        from = f; to = t; cost = c;
    } 
};

edge es[2000];

ll d[1000];
int V,E;

//s番目の頂点から各頂点への最短距離を求める
bool bellman_ford(int s){
    for (int i = 0; i < V; i++) d[i] = 1e18;
    d[s] = 0;
    int cnt = 0;
    for (int i = 0; i < V; i++) {
        cnt++;
        bool updated = false;
        for (int j = 0; j < E; j++) {
            edge &e = es[j];
            if (d[e.to] > d[e.from] + e.cost) {
                d[e.to] = d[e.from] + e.cost;
                if (i == V-1) return true;
                updated = true;
            }
        }
        if (!updated) return false;
    } 
}

int main() {

    cin >> V >> E; 
    for (int i = 0; i < E; i++) {
        ll a, b, c; cin >> a >> b >> c;
        es[i] = edge(a-1,b-1,-1 * c);
    }
    bool closed = bellman_ford(0);


    vector<bool> negative(V,false);
    for (int loop = 0; loop < V; loop++) {
        for (int i = 0; i < E; i++) {
            if (d[es[i].from] == 1e18) continue;
            if (d[es[i].to] > d[es[i].from] + es[i].cost) {
                d[es[i].to] = d[es[i].from] + es[i].cost;
                negative[es[i].to] = true;
            }
            if (negative[es[i].from]) negative[es[i].to] = true;
        }
    }

    if (negative[V-1]) {
        cout << "inf" << endl;
    } else {
        cout << -1*d[V-1] << endl;
    }








}
