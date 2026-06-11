#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
struct UnionFind {
    vector<int> par;
    vector<int> rank;
    vector<ll> Size;
    UnionFind(int n = 1) {
        init(n);
    }

    void init(int n = 1) {
        par.resize(n + 1); rank.resize(n + 1), Size.resize(n + 1);
        for (int i = 0; i <= n; ++i) par[i] = i, rank[i] = 0, Size[i] = 1;
    }

    int root(int x) {
        if (par[x] == x) {
            return x;
        }
        else {
            int r = root(par[x]);
            return par[x] = r;
        }
    }

    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    bool merge(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) swap(x, y);
        if (rank[x] == rank[y]) ++rank[x];
        par[y] = x;
        Size[x] += Size[y];
        return true;
    }

    ll size(int x){
        return Size[par[x]];
    }
};


int main() {
    //cout.precision(10);
    UnionFind uni(200010);
    UnionFind bi(200010);
    ll n, m;
    cin >> n >> m;
    ll ans = 0;
    ll one = 0;
    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        uni.merge(u, v);
        bi.merge(u + 100000, v);
        bi.merge(u, v + 100000);
    }
    ll roop = 0;
    ll simple = 0;
    for(int i = 1; i <= n; i++){
        if(uni.root(i) != i){
            continue;
        }
        if(uni.size(i) == 1){
            one++;
            continue;
        }
        if(bi.issame(i, i + 100000)){
            roop++;
        } else {
            simple++;
        }
        //cout << i << " " << uni.size(i) << " " << now << endl;
        //ans = ans - uni.size(i) * uni.size(i) + now;
    }
    ans += (roop + simple) * (roop + simple) + simple * simple;
    for(ll i = n - one + 1; i <= n; i++){
        ans += 2 * i - 1;
    }
    cout << ans << endl;
    return 0;
}
