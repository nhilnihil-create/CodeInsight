#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
using P = pair<int,int>;
class UnionFind {
public:
    vector <ll> par; // 各元の親を表す配列
    vector <ll> siz; // 素集合のサイズを表す配列(1 で初期化)
    
    // Constructor
    UnionFind(ll sz_): par(sz_), siz(sz_, 1LL) {
        for (ll i = 0; i < sz_; ++i) par[i] = i; // 初期では親は自分自身
    }
    void init(ll sz_) {
        par.resize(sz_);
        siz.assign(sz_, 1LL);  // resize だとなぜか初期化されなかった
        for (ll i = 0; i < sz_; ++i) par[i] = i; // 初期では親は自分自身
    }
    
    // Member Function
    // Find
    ll root(ll x) { // 根の検索
        while (par[x] != x) {
            x = par[x] = par[par[x]]; // x の親の親を x の親とする
        }
        return x;
    }
    
    // Union(Unite, Merge)
    bool merge(ll x, ll y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        // merge technique（データ構造をマージするテク．小を大にくっつける）
        if (siz[x] < siz[y]) swap(x, y);
        siz[x] += siz[y];
        par[y] = x;
        return true;
    }
    
    bool issame(ll x, ll y) { // 連結判定
        return root(x) == root(y);
    }
    
    ll size(ll x) { // 素集合のサイズ
        return siz[root(x)];
    }
};
int main(void) {
    int x, y; cin >> x >> y;
    UnionFind uf(13);
    uf.merge(1,3); uf.merge(3,5); uf.merge(5,7); uf.merge(7,8); uf.merge(8,10); uf.merge(10,12); uf.merge(12,1);
    uf.merge(4,6); uf.merge(9,11); uf.merge(11,4);
    if(uf.issame(x, y)) cout << "Yes";
    else cout << "No";
}
