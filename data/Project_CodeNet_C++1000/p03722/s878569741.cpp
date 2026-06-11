#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;

struct Edge{
    ll from, to, cost;
};

using Edges = vector<Edge>;

bool bellman_ford(Edges &Es, int V, int s, vector<ll>& dis){
    dis.resize(V,LINF);
    dis[s] = 0;
    int cnt = 0;
    while(cnt < V){
        bool end = true;
        for(auto e: Es){
            if(dis[e.from] != LINF && dis[e.from]+e.cost < dis[e.to]){
                dis[e.to] = dis[e.from] + e.cost;
                end = false;
            }
        }
        if(end) return false;
        cnt++;
    }
    return (cnt==V);
}

bool bellman2(Edges &Es, int V, int s, vector<ll>& dis, vector<bool>& negative){
    int cnt = 0;
    while(cnt <= V){
        for(auto e: Es){
            if(negative[e.from] == true) negative[e.to] = true;//値の更新が起きなくても負経路に入ることあり
            if(dis[e.from] != LINF && dis[e.from]+e.cost < dis[e.to]){
                dis[e.to] = dis[e.from] + e.cost;
                negative[e.to] = true;
            }
        }
        cnt++;
    }
    return (negative[V-1]);
}

int main() {
    int N,M; cin >> N >> M;

    Edges Es(M);
    REP(i,M){
        int a,b,c; cin >> a >> b >> c;
        a--;b--;
        Es[i] = {a,b,-c};
    }

    vector<ll> dis;
    bellman_ford(Es, N, 0, dis);
    
    vector<bool> negative(N,false);
    if(bellman2(Es, N, 0, dis, negative)) cout << "inf" << endl;
    else  cout << -dis[N-1] << endl;

    




    return 0;
}