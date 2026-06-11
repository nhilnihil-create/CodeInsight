#include <bits/stdc++.h>
template<class T> inline bool chmin(T&a, T b){if(a > b){a = b; return true;}else{return false;}}
template<class T> inline bool chmax(T&a, T b){if(a < b){a = b; return true;}else{return false;}}
#define ll long long
#define double long double
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
#define mod (ll)(1e9+7)
#define inf (ll)(3e18+7)
#define pi (double) acos(-1.0)
#define P pair<int,int>
#define PiP pair<int,pair<int,int>>
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
using namespace std;

struct edge{
    ll to, cost;
};

using Graph = vector<vector<edge>>;
vector<ll> dis(100010);

void dfs(const Graph &G, ll v, ll p, ll d) { 
    dis[v] = d;
	for (auto nv : G[v]) {
		if (nv.to == p)continue;
		dfs(G, nv.to, v, d + nv.cost);
	}
}


int main() {
    int n;
    cin >> n;
    Graph G(n);
    rep(i, n-1){
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        G[a].push_back({b, c});
        G[b].push_back({a, c});
    }
    ll q, k;
    cin >> q >> k; k--;
    dfs(G, k, -1, 0);
    rep(i, q){
        int x, y;
        cin >> x >> y;
        x--; y--;
        cout << dis[x] + dis[y] << endl;
    }
}
