#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const int MOD2 = 998244353;

struct Edge {
    ll to, cost;
    Edge(ll to, ll cost) : to(to), cost(cost) {}
};
 
typedef vector<vector<Edge> > AdjList;
AdjList graph;
 
 
vector<ll> dist;
 
bool bellman_ford(ll n, ll s) {
    dist = vector<ll>(n, LINF);
    dist[s] = 0;
    for (int i = 0; i < n; i++) {
        for (int v = 0; v < n; v++) {
            for (int k = 0; k < graph[v].size(); k++) {
                Edge e = graph[v][k];
                if (dist[v] != LINF && dist[e.to] > dist[v] + e.cost) {
                    dist[e.to] = dist[v] + e.cost;
                    if (i == n - 1) return true;
                }
            }
        }
    }
    return false;
}

void find_negative_loop(int n){
    for (int i = 0; i < n; i++) {
        for (int v = 0; v < n; v++) {
            for (int k = 0; k < graph[v].size(); k++) {
                Edge e = graph[v][k];
                if (dist[v] != LINF && dist[e.to] > dist[v] + e.cost) {
                    dist[e.to] = -LINF;
                }
            }
        }
    }
}

int main(){
    ll n, m;
    cin >> n >> m;
    graph = AdjList(n);
    rep(i, m){
        ll from, to, cost;
        cin >> from >> to >> cost;
        from--, to--;
        graph[from].push_back(Edge(to,-cost));
    }
    bellman_ford(n, 0);
    find_negative_loop(n);

    if(dist[n-1] == -LINF) cout << "inf" << endl;
    else cout << -dist[n-1]<< endl;

    return 0;
}
