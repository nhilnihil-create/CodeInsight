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

void solve(int N,int M,vi& l,vi& r) {
    int sq = sqrt(M); // 316
    bool just = (sq*sq == M);

    vi a(M+2, 0);

    vi left;
    left.reserve(sq+1);

    rep(i,N){ // 3e5
        double li=l[i], ri=r[i];
#ifdef DEBUG
        fprintf(stderr, "i=%d (%g..%g)\n", i, li, ri);
#endif
        a[l[i]]++; a[r[i]+1]--;
#ifdef DEBUG
        fprintf(stderr, "  [%g %g]\n", li, ri);
#endif
        int last_lo = li;
        left.clear();
        left.pb(1);
        for (int x=2; x<=sq; ++x) { // 316 ; < 9.5e7
            int lo=ceil(li/x), hi=floor(ri/x);
            hi = min(last_lo-1, hi);
            if (lo <= hi) {
#ifdef DEBUG
                fprintf(stderr, "  [%d %d]*%d\n", lo, hi, x);
#endif
                a[lo]++; a[hi+1]--;
                left.pb(x);
                last_lo = lo;
            }
        }
        if (just && sq < last_lo) {
            a[sq]++; a[sq+1]--;
            last_lo = sq;
#ifdef DEBUG
            fprintf(stderr, "  [%d] // sq\n", sq);
#endif
        }
#ifdef DEBUG
        cerr << "left=" << left << last_lo << endl;
#endif
#if 1
        for (int x : left) {
            if (x >= last_lo) break;
#ifdef DEBUG
            fprintf(stderr, "  [%d]\n", x);
#endif
            a[x]++; a[x+1]--;
        }
#endif
        // rep(i,M+1) a[i+1] += a[i];
        // cerr << i << ") " << a << endl;
        // a.assign(M+2, 0);
    }

    rep(i,M+1) a[i+1] += a[i];

    for (int i=1; i<=M; ++i) {
        cout << a[i] << endl;
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
