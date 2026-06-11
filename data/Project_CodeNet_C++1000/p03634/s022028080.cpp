#include <bits/stdc++.h>
#define rep(i, n) for(long long int i = 0; i < n; i++)
#define _rep(i, m, n) for(long long int i = m; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int N = 1000000;
const ll mod = 1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

ll gcd(ll A, ll B){
    if(B == 0)return A;
    return gcd(B, A % B);
}
ll lcm(ll A, ll B){
    return A * B / gcd(A, B);
}

/*------------------------------------------------------------------*/
struct Edge{
    int to;
    ll welght;
    Edge(int t, ll w) : to(t), welght(w) { }
};
using Graph = vector<vector<Edge>>;
vector<ll> Weight;

void dfs(const Graph &G, int v, int p, ll w){
    Weight[v] = w;
    for(auto nv : G[v]){
        if(nv.to == p) continue;
        dfs(G, nv.to, v, w + nv.welght); 
    }
}

int main(){
    int n; cin >> n;
    Graph G(n);
    Weight.resize(n);

    for(int i = 0; i < n - 1; i++){
        int from, to, weight; cin >> from >> to >> weight;
        from--, to--;
        G[from].push_back(Edge(to, weight));
        G[to].push_back(Edge(from, weight));
    }
    int q, k; cin >> q >> k;
    k--;

    dfs(G, k, -1, 0);
    for(int i = 0; i < q; i++){
        int x, y; cin >> x >> y;
        x--, y--;
        cout << Weight[x] + Weight[y] << endl;
    }
}
