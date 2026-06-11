#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(a) (a).begin(),(a).end()
using namespace std;
using ll = long long;
using P = pair<int,ll>;
vector<vector<P>> tree(100010);
vector<ll> depth(100010);

void dfs(int v,int p,ll d){
    depth[v] = d;
    for(auto e : tree[v]){
        if(e.first == p) continue;
        dfs(e.first, v, d+e.second);
    }
}

int main(){
    int n; cin >> n;
    for(int i = 0;i<n-1;++i){
        int a, b;ll c; cin >> a >> b >> c;
        a--;b--;
        tree[a].push_back({b,c});
        tree[b].push_back({a,c});
    }
    int q,k; cin >> q >> k;
    k--;
    dfs(k,-1,0ll);
    rep(i,q){
        int x,y; cin >> x >> y;
        x--;y--;
        cout << depth[x]+depth[y] << endl;
    }
}
