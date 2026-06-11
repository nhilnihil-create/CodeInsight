#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <numeric>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <stack>
#include <math.h>
#include <string.h>
#include <map>
#include <set>
#include <bitset>
#include <queue>


#define ln cout<<'\n'
#define ll long long
#define ld long double
#define rep(i, n) for(int i = 0; i < (n); ++i)
//ASCII a=97, A=65
// int H[N]; rep(i,N) scanf("%d", &H[i]);
// int max_x = *std::max_element(x.begin(), x.end());
// int min_y = *std::min_element(y.begin(), y.end());
// sort(vec.begin(), vec.end()); std::greater<>()
// reverse(vec.begin(), vec.end());
// scanf("%s",s);
// printf("%d\n",end-start+1);
// ceil (a + (b - 1)) / b

using namespace std;
using Edge = pair<int, int>;
using Graph = vector<vector<Edge>>;
using pll = pair<long long, long long>;

template<class T> inline bool chmax(T& a, T b){ if(a < b) { a=b; return 1; }return 0;}
template<class T> inline bool chmin(T& a, T b){ if(a > b) { a=b; return 1; }return 0;}

int GCD(int a, int b) { return b ? GCD(b, a%b) : a; }
const long long INF = 1LL << 60;
const int MOD = 1000000007;

struct UnionFind {
    vector<int> par;
    UnionFind(int n) : par(n, -1) { }
    void init(int n) { par.assign(n, -1); }
    
    int rt(int x) {
        if (par[x] < 0) return x;
        else return par[x] = rt(par[x]);
    }
    
    bool issame(int x, int y) {
        return rt(x) == rt(y);
    }
    
    bool unite(int x, int y) {
        x = rt(x);
        y = rt(y);
        if (x == y)  return false;
        
        if (par[x] > par[y]) swap(x, y);
        par[x] += par[y];
        par[y] = x;
        return true;
    }
    
    int size(int x) {
        return -par[rt(x)];
    }
};

int main() {
    int N, M, L; cin >> N >> M >> L;
    UnionFind uf_tr(N), uf_rd(N);
    rep (i, M) {
        int a, b; cin >> a >> b, --a, --b;
        uf_tr.unite(a, b);
    }
    rep (i, L) {
        int a, b; cin >> a >> b, --a, --b;
        uf_rd.unite(a, b);
    }
    
    map < pair<int, int>, int> mp;
    rep (i, N) {
        pair<int, int> p(uf_tr.rt(i), uf_rd.rt(i));
        mp[p]++;
    }
    rep (i, N) {
        pair<int, int> p(uf_tr.rt(i), uf_rd.rt(i));
        cout << mp[p] << " ";
    }
}

