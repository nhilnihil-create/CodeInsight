/**
 *   @FileName	a.cpp
 *   @Author	kanpurin
 *   @Created	2020.08.12 03:04:53
**/

#include "bits/stdc++.h" 
using namespace std; 
typedef long long ll;


struct edge { int to, cost; };
long long LLINF = 1e18 + 1;


void bellman_ford(int s, const std::vector< std::vector< edge > > &G, std::vector< long long > &d) {
    const int V = G.size();
    d = std::vector< long long >(V, LLINF);
    d[s] = 0;
    bool update = true;
    int i = 0;
    while (update)
    {
        update = false;
        for (int j = 0; j < V; j++)
        {
            for (const edge &e : G[j])
            {
                if (d[j] != -LLINF && d[j] != LLINF && d[j] + e.cost < d[e.to]) {
                    d[e.to] = d[j] + e.cost;
                    if (i == V - 1) {
                        d[e.to] = -LLINF;
                    }
                    update = true;
                }
                else if (d[j] == -LLINF && d[e.to] != -LLINF) {
                    d[e.to] = -LLINF;
                    update = true;
                }
            }
        }
        if (i < V - 1) i++;
    }
}
int main() {
    int n,m;cin >> n >> m;
    vector<vector<edge>> g(n);
    for (int i = 0; i < m; i++) {
        int a,b,c;cin >> a >> b >> c;
        a--;b--;
        g[a].push_back({b,-c});
    }
    vector<ll> d;
    bellman_ford(0,g,d);
    if (d[n-1] == -LLINF) {
        puts("inf");
    }
    else {
        cout << -d[n-1] << endl;
    }
    return 0;
}
