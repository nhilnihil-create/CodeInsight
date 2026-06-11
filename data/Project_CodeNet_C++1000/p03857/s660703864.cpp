#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define rrep(i,n) for(int i=(n)-1; i>=0; i--)
#define FOR(i,a,b) for(int i=(a); i<(b); i++)
#define RFOR(i,a,b) for(int i=(b-1); i>=(a); i--)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );
#define pb push_back
using ll = long long;
using D = double;
using LD = long double;
using P = pair<int, int>;
const int mod = 1e9+7;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

struct UnionFind {
    vector<int> par;

    UnionFind(int sz) {
        par.assign(sz, -1);
    }

    bool merge(int x, int y) {
        x = root(x), y = root(y);
        if(x == y) return (false);
        if(par[x] > par[y]) swap(x, y);
        par[x] += par[y];
        par[y] = x;
        return (true);
    }

    int root(int k) {
        if(par[k] < 0) return (k);
        return (par[k] = root(par[k]));
    }

    int size(int k) {
        return (-par[root(k)]);
    }

    bool same(int x, int y) {
        return root(x) == root(y);
    }
};

int main(){
    int n,k,l; cin >> n >> k >> l;
    UnionFind ur(n), ut(n);
    rep(i,k){
        int p,q; cin >> p >> q; p--; q--;
        ur.merge(p,q);
    }
    rep(i,l){
        int r,s; cin >> r >> s; r--; s--;
        ut.merge(r,s);
    }
    map<P, int> mp;
    rep(i,n) mp[P(ur.root(i), ut.root(i))]++;
    rep(i,n) printf("%d%c", mp[P(ur.root(i), ut.root(i))], i == n-1 ? '\n' : ' ');
}
