#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

//参考: https://pyteyon.hatenablog.com/entry/2019/03/11/200000
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
        siz.assign(sz_, 1LL);
        for (ll i = 0; i < sz_; ++i) par[i] = i; // 初期では親は自分自身
    }

    // Member Function
    // Find
    ll find(ll x) { // 根の検索
        while (par[x] != x) {
            x = par[x] = par[par[x]]; // x の親の親を x の親とする
        }
        return x;
    }

    // Union(Unite, Merge)
    bool unite(ll x, ll y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;
        // merge technique（データ構造をマージするテク．小を大にくっつける）
        if (siz[x] < siz[y]) swap(x, y);
        siz[x] += siz[y];
        par[y] = x;
        return true;
    }

    bool issame(ll x, ll y) { // 連結判定
        return find(x) == find(y);
    }

    ll size(ll x) { // 素集合のサイズ
        return siz[find(x)];
    }
};

int main() {
    int x, y;
    cin >> x >> y;
    
    UnionFind uf(13);
    uf.unite(1,3);
    uf.unite(3,5);
    uf.unite(5,7);
    uf.unite(7,8);
    uf.unite(8,10);
    uf.unite(10,12);

    uf.unite(4,6);
    uf.unite(6,9);
    uf.unite(9,11);
    
    if (uf.issame(x,y))cout << "Yes" << endl;
    else cout << "No" << endl;

}