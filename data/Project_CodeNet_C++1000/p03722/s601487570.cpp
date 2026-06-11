#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

typedef struct {
    int from;
    int to;
    ll cost;
} edge;


//負の閉路がない時にはtrueを返し、dにsからの最短距離を格納する
//負の経路が存在する時にはfalseを返す
bool bellman_ford(vector<edge> G, int n, int s, ll *d) {
    ll INF = -100000000000000;
    for (int i = 0; i < n; i++)
        d[i] = INF;
    d[s] = 0;

    for (int i = 0; i < 2*n; i++) {
        bool check = false;
        for (int j = 0; j < G.size(); j++) {
            edge e = G[j];
            int u = e.from, v = e.to;
            ll c = e.cost;

            if (d[u] != INF && d[v] < d[u] + c) {
                d[v] = d[u] + c;
                if (v == n-1)
                    check = true;
            }
        }
        if (i >= n && check)
            return false;
    }
    return true;
}

int main() {
    int n, m;   cin >> n >> m;
    vector<edge> G;

    for (int i = 0; i < m; i++) {
        int a, b;   ll c;
        cin >> a >> b >> c;

        edge es = {a-1, b-1, c};
        G.push_back(es);
    }


    ll *d = new ll[n];
    if (bellman_ford(G, n, 0, d)) {
        cout << d[n-1] << endl;
    }
    else 
        cout << "inf" << endl;

    return 0;
}