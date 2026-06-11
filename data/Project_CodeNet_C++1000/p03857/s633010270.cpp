#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> T;
const long long INF = 1LL<<60;
// const int MOD = 1000000000+7;
#define rev(s) (string((s).rbegin(), (s).rend()))
// cout << fixed << setprecision(10) << ans << endl; 有効桁数指定
// *min_element(c + l, c + r) *max_element(c + l, c + r) 配列の中のmin-max
// int dx[8]={1,1,0,-1,-1,-1,0,1};
// int dy[8]={0,1,1,1,0,-1,-1,-1};
// int dx[4]={1,0,-1,0};
// int dy[4]={0,1,0,-1};
// ~ は、-1の時だけfalse

// UnionFind tree(n);  と宣言

class UnionFind {
public:
    vector <ll> par; // 各元の親を表す配列
    vector <ll> siz; // 素集合のサイズを表す配列(1 で初期化)

    // Constructor
    UnionFind(ll sz_): par(sz_), siz(sz_, 1LL) {
        for (ll i = 0; i < sz_; ++i) par[i] = i; // 初期では親は自分自身
    }
    void init(ll sz_) {
        siz.assign(sz_, 1LL);  // assign: 再代入
        par.resize(sz_);  // resize: 再確保
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

map<P,int> ma;

int main () {

    int n,k,l;cin>>n>>k>>l;

    UnionFind tree1(n);
    UnionFind tree2(n);

    rep(i,k) {
        ll p,q;cin>>p>>q;
        p--;q--;
        if (!tree1.issame(p,q)) tree1.merge(p,q);
    }

    rep(i,l) {
        ll p,q;cin>>p>>q;
        p--;q--;
        if (!tree2.issame(p,q)) tree2.merge(p,q);
    }

    for (ll i =0;i<n;i++) {
        ma[P(tree1.root(i),tree2.root(i))]++;
    }

    for (ll i=0;i<n;i++) {
        cout<<ma[P(tree1.root(i),tree2.root(i))]<<" ";
        if (i==n-1) cout<<endl;
    }

}