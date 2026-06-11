#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <string>
#include <set>
#include <bitset>
#include <unordered_map>

using namespace std;
using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;
template <class T>
using Vvec = vector<vector<T> >;

class Edge{
public:
    int to;
    long long cost;
    Edge(int v, long long c = 1): to(v), cost(c){}
    ~Edge(){}
    bool operator<(const Edge& e) const{return cost < e.cost;}
};

bool Bellman_Ford(std::vector<std::vector<Edge> > &edge, int N,
    int start, std::vector<long long> &dist, ll &ans)
{
    // initialize
    long long infty = 1e+16;
    dist.clear();
    for(int i=0; i<N; i++) dist.push_back(infty);
    dist[start] = 0;

    std::vector<long long> cpy(dist);

    // update
    for(int i=0; i<2*N; i++){
        for(int u=0; u<N; u++){
            if(dist[u] == infty) continue;
            for(Edge& e: edge[u]){
                if(dist[u] + e.cost < cpy[e.to]){
                    cpy[e.to] = dist[u] + e.cost;
                }
            }
        }
        for(int i=0; i<N; i++) dist[i] = cpy[i];
        if(i == N-1) ans = dist[N-1];
    }

    return false;
}

int main()
{
    int N, M;
    cin >> N >> M;
    Vvec<Edge> graph(N);
    for(int i=0; i<M; i++){
        int u, v;
        ll c;
        cin >> u >> v >> c; u--; v--;
        graph[u].emplace_back(v, -c);
    }

    ll ans = 0;
    vector<ll> dist;
    Bellman_Ford(graph, N, 0, dist, ans);
    
    if(ans == dist[N-1]) cout << -ans << endl;
    else cout << "inf\n";
}