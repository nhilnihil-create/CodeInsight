#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <iomanip>
#include <map>
#include <set>
#include <cmath>
#include <cstdio>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define FOR(i,m,n) for(int (i)=(m);(i)<(n);(i)++)
#define All(v) (v).begin(),(v).end()
typedef long long ll;
typedef pair<int,int> pii;

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <iomanip>
#include <map>
#include <set>
#include <cmath>
#include <cstdio>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define FOR(i,m,n) for(int (i)=(m);(i)<(n);(i)++)
#define All(v) (v).begin(),(v).end()
typedef long long ll;

//UnionFind
struct UnionFind {
    vector<ll> par;
    vector<ll> siz;

    UnionFind(ll N) : par(N),siz(N,1LL) {
        for(int i = 0; i < N; i++) par[i] = i;
    }
    int root(int x) {
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }
    void unite(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        if (rx == ry) return;
        if(siz[rx]<siz[ry])swap(rx,ry);
        siz[rx]+=siz[ry];
        par[ry] = rx;
    }
    bool same(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
    ll size(ll x){
        return siz[root(x)];
    }
};

int main(){
    int N,K,L;
    cin >> N >> K >> L;
    UnionFind load(N),rail(N);
    rep(i,K){
        int p,q;
        cin >> p >> q;
        p--;q--;
        load.unite(p,q);
    }
    rep(i,L){
        int r,s;
        cin >> r >> s;
        r--;s--;
        rail.unite(r,s);
    }
    map<pii,int> mp;
    rep(i,N){
        mp[make_pair(load.root(i),rail.root(i))]++;
    }
    rep(i,N){
        cout << mp[make_pair(load.root(i),rail.root(i))] << " ";
    }
    cout << endl;
    return 0;
}