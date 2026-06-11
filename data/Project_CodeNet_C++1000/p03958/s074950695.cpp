#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using P = pair<ll,ll>;
using Um = unordered_map<char,ll>;
#define fl cout<<flush;
#define endl '\n'
template <typename T> inline void prt(T v){cout<<v<<'\n';}
template <typename T> inline bool chmax(T &a, const T &b){if (a<b){a=b;return 1;}return 0;}
template <typename T> inline bool chmin(T &a, const T &b){if (a>b){a=b;return 1;}return 0;}
const ll INF=1LL<<60;
const ll MOD=1e9+7;
const ll MOD2=998244353;
const ld pi=3.14159265358979323846;
const ld eps=1e-10;

//0-indexedに注意！！
class UnionFind {
public:
    vector < ll > par; // 各元の親を表す配列
    vector < ll > siz; // 素集合のサイズを表す配列(1 で初期化)

    // Constructor,[0,sz_-1)で定義
    UnionFind(ll sz_): par(sz_), siz(sz_, 1) {
        for (ll i = 0; i < sz_; ++i) par[i] = i; // 初期では親は自分自身
    }
    void init(ll sz_) {
        par.resize(sz_);
        siz.assign(sz_, 1);
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
    bool unite(ll x, ll y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        // merge technique（データ構造をマージするテク．小を大にくっつける）
        if (siz[x] < siz[y]) swap(x, y);
        siz[x] += siz[y];
        par[y] = x;
        return true;
    }

    bool same(ll x, ll y) { // 連結判定
        return root(x) == root(y);
    }

    ll size(ll x) { // 素集合のサイズ
        return siz[root(x)];
    }
};

signed main(void){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
    ll K;
    cin >> K;
    ll T;
    cin >> T;
    vector<ll> a(T,0);
    for(ll i=0;i<T;++i)cin>>a[i];
    sort(a.rbegin(), a.rend());
    ll Max=a[0];
    if(K%2==1){
        if(Max<=K/2+1)prt(0);
        else {
            prt(2*(Max-K/2-1));
        }
    }
    else {
        if(Max<=K/2)prt(0);
        else prt(-1+2*(Max-K/2));
    }
    
fl
    return 0;
}

