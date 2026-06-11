#include <bits/stdc++.h>
using namespace std;

#define NDEBUG
#ifdef DEBUG
#include "../cout11.h"
#undef NDEBUG
#endif
#include <cassert>

typedef long long ll;
typedef long double Double;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef pair<ll,ll> llll;
typedef pair<double,double> dd;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;
typedef vector<vector<ii>> vvii;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<long double> vD;

#define sz(a)  int((a).size())
#define pb  push_back
#define FOR(var,from,to) for(int var=(from);var<=(to);++var)
#define rep(var,n)  for(int var=0;var<(n);++var)
#define rep1(var,n)  for(int var=1;var<=(n);++var)
#define repC2(vari,varj,n)  for(int vari=0;vari<(n)-1;++vari)for(int varj=vari+1;varj<(n);++varj)
#define ALL(c)  (c).begin(),(c).end()
#define RALL(c)  (c).rbegin(),(c).rend()
#define tr(i,c)  for(auto i=(c).begin(); i!=(c).end(); ++i)
#define found(s,e)  ((s).find(e)!=(s).end())
#define mset(arr,val)  memset(arr,val,sizeof(arr))
#define mid(x,y) ((x)+((y)-(x))/2)
#define IN(x,a,b) ((a)<=(x)&&(x)<=(b))
#define cons make_pair

// Fenwick Tree (Binary Indexed Tree, BIT)

template <typename T, int base=0>
class fenwick_tree_0 { // 0-base
 public:
    vector<T> x;
 public:
    fenwick_tree_0(int n) : x(n+base,0) { }
    void add(int k, T a) { for (; k<x.size(); k|=k+1) x[k] += a; }
    T sum(int i, int j) { // [i,j]
        if (i == base) {
            T S = 0; for (; j>=0; j=(j&(j+1))-1) S += x[j]; return S;
        } else {
            return sum(base, j) - sum(base, i-1);
        }
    }
};

template <typename T, int base=1>
class fenwick_tree_1 { // 1-base
 public:
    vector<T> x;
 public:
    fenwick_tree_1(int n) : x(n+base,0) { }
    void add(int k, T a) { for (; k<=x.size(); k+=k&-k) x[k] += a; }
    T sum(int i, int j) { // [i,j]
        if (i == base) {
            T S = 0; for (; j>0; j-=j&-j) S += x[j]; return S;
        } else {
            return sum(base, j) - sum(base, i-1);
        }
    }
};

template <typename F, typename T, int base>
class double_fenwick_tree {
public:
    F p, q;
public:
    double_fenwick_tree(int n) : p(n), q(n) { }

    void add_range(int a, int b, T w) {
        p.add(a, -w*a); p.add(b, w*b);
        q.add(a, w); q.add(b, -w);
    }
#if 0
    T sum(int i, int j) { // [i, j]
        if (i == base) {
            return p.sum(base, j) + j*q.sum(base, j);
        } else {
            return sum(base, j+1) - sum(base, i);
        }
    }
#else
    T sum(int i, int j) { // [i, j)
        if (i == base) {
            return p.sum(base, j) + j*q.sum(base, j);
        } else {
            return sum(base, j) - sum(base, i);
        }
    }
#endif
};

void solve(int N,int M,vi& l,vi& r) {
    double_fenwick_tree<fenwick_tree_0<int>, int, 0> bw(M+2);
    vvi lr(M+1);
    rep(i,N){
        int w = r[i] - l[i] + 1;
        lr[w].pb(i);
        bw.add_range(1, w+1, 1);
    }

    double_fenwick_tree<fenwick_tree_0<int>, int, 0> fw(M+2);
    rep1(d,M){
        int ans = bw.sum(d,d+1);

        for (int i: lr[d-1]) {
            // 区間[ l_i, r_i ]++
            fw.add_range(l[i], r[i]+1, 1);
        }
        for (int x=d; x<=M; x+=d) {
            ans += fw.sum(x,x+1);
        }

        cout << ans << endl;
    }
}

int main() {
    char buf[128];
    int N, M;
    // cin >> N >> M;
    scanf("%d %d", &N, &M);
    vi l(N),r(N);
    rep(i, N) {
        // cin >> l[i] >> r[i];
        scanf("%d %d", &l[i], &r[i]);
    }
    solve(N,M,l,r);
    return 0;
}
