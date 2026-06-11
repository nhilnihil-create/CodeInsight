#include <bits/stdc++.h>
#define ll long long
#define MODV 1000000007
#define INF INT_MAX // 2147483647
#define INFLL LLONG_MAX // 9223372036854775807
#define rep(i, n) for(ll i=0, i##_len=(ll)(n); i<i##_len; i++)
#define repf(i, n) for(ll i=1, i##_len=(ll)(n+1); i<i##_len; i++)
#define per(i, n) for(ll i=((ll)(n))-1; i>=0; i--)
#define perf(i, n) for(ll i=((ll)(n)); i>0; i--)
#define all(v) v.begin(), v.end()
#define endl "\n"
#define vi vector<ll>
#define vvi vector<vector<ll>>
#define Yes() cout << "Yes" << endl
#define YES() cout << "YES" << endl
#define No() cout << "No" << endl
#define NO() cout << "NO" << endl
#define Init() std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout<<fixed<<setprecision(15);
template<class T>bool chmax(T &a, const T &b){ if(a<b){ a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b){ if(b<a){ a=b; return 1; } return 0; }
using namespace std;

class UnionFind {
public:
    vector<long long> parent;
    long long n;
    UnionFind(long long x) :parent(x, -1), n(x){}
    bool unite(long long x, long long y){
        x = find(x); y = find(y);
        if (x == y) return false;
        if (size(x) < size(y)) swap(x, y);
        parent[x] += parent[y]; parent[y] = x;
        return true; }
    bool same(long long x, long long y){ return find(x) == find(y); }
    long long find(long long x){ return parent[x] < 0 ? x : parent[x] = find(parent[x]); }
    long long size(long long x){ return -parent[find(x)]; }
};

int main(){
    Init();
    UnionFind uf(13);
    uf.unite(1, 3);    
    uf.unite(1, 5);    
    uf.unite(1, 7);    
    uf.unite(1, 8);    
    uf.unite(1, 10);    
    uf.unite(1, 12);    
    uf.unite(4, 6);    
    uf.unite(4, 9);    
    uf.unite(4, 11);
    ll x, y; cin >> x >> y;
    (uf.same(x, y)) ? Yes() : No();

}