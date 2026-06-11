#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e12;
#define rep1(i, n) for (ll i=0; i<(n); i++) 
#define rep2(i, k, n) for (ll i=k; i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

typedef vector<vector<P> > Graph;

vector<ll> cost;
void dfs(const Graph &G, ll v, ll p, ll add) {
    cost[v] = add;
    // v から行ける各頂点 next_v について
    for (auto next_v : G[v]) { 
        if (next_v.first == p) continue; // next_v が探索済だったらスルー
        dfs(G, next_v.first, v, add + next_v.second); // 再帰的に探索
    }
}



int main() {
    ll n;
    cin >> n;
    Graph G(n);
    rep1(i, n-1){
        ll a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        G[a].push_back(make_pair(b, c));
        G[b].push_back(make_pair(a, c));
    }
    ll q, k;
    cin >> q >> k;
    k--;
    cost.assign(n, 0);
    dfs(G, k, -1, 0);
    rep1(i, q){
        ll x, y;
        cin >> x >> y;
        x--, y--;
        cout << cost[x]+cost[y] << endl;
    }
    //printf("%.12f", ans);
}