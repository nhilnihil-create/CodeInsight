#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define _GLIBCXX_DEBUG
#define rep(i, V) for (int i = 0; i < V; i++)
#define repr(i, V) for (int i = V-1; i >= 0; i--)
#define repval(i, a, V) for (int i = a; i < V ; i++)
#define all(x) x.begin(), x.end()
#define ld long double
#define eps 0.0000000001
#define mod 1000000007
#define inf 1e16
#define vec vector
#define each(i, mp) for(auto& i:mp)

int nmax = 1e5;
using edge = struct{int to; ll cost;};
vector<vector<edge>> tree(nmax);
vector<ll> depth(nmax, 0);

void dfs(int v, int p, ll d){
    depth[v] = d;
    for (auto e: tree[v]){
        if (e.to == p) continue;
        dfs(e.to, v, d + e.cost);
    }
}

int main(){
    int n;
    cin >> n;
    int a,b;
    ll c;
    rep(i, n-1){
        cin >> a >> b >> c;
        a--, b--;
        tree[a].push_back({b,c});
        tree[b].push_back({a,c});
    }

    int q, k;
    cin >> q >> k;
    k--;
    dfs(k, -1, 0);
    
    int x, y;
    rep(i, q){
        cin >> x >> y;
        x--, y--;
        cout << depth[x] + depth[y] << endl;
    }
}