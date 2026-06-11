//marico el que lo lea
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <stdlib.h>
#include <assert.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> ii;

void fastIO() {
	std::ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}

#define FOR(i,f,t) for(int i=f; i<(int)t; i++)
#define FORR(i,f,t) for(int i=f; i>(int)t; i--)
#define FORE(i,c) for(auto i = (c).begin(); i != (c).end(); i++)
#define pb push_back
#define all(obj) obj.begin(), obj.end()
#define ms(obj, val) memset(obj, val, sizeof(obj))
#define ms2(obj, val, sz) memset(obj, val, sizeof(obj[0])*sz)

#define fst first
#define snd second

template<typename T, typename U> inline void mnze(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void mxze(T &x, U y) { if(x < y) x = y; }

void _scan( int &x ) { scanf("%d",&x); }
void _scan( long long &x ) { scanf("%lld",&x); }
void _scan( double &x ) { scanf("%lf",&x); }
void _scan( char &x ) { scanf(" %c",&x); }
void _scan( char *x ) { scanf("%s",x); }
void scan() {}
template<typename T, typename... U>
void scan( T& head, U&... tail ) { _scan(head); scan(tail...);}

template<typename T> void _dbg(const char* sdbg, T h) { cerr<<sdbg<<"="<<h<<"\n"; }
template<typename T, typename... U> void _dbg(const char* sdbg, T h, U... t) {
	while(*sdbg != ',')cerr<<*sdbg++; cerr<<"="<<h<<","; _dbg(sdbg+1, t...);
}

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#define debugv(x) {{cerr <<#x <<" = "; FORE(_i, (x)) cerr <<*_i <<", "; cerr <<"\n"; }}
#define debuga(x, sz) {{cerr <<#x <<" = "; FOR(_i, 0, sz) cerr << x[_i] <<", "; cerr <<"\n"; }}
#else
#define debug(...) (__VA_ARGS__)
#define debugv(x)
#define debuga(x, sz)
#define cerr if(0)cout
#endif

///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////


struct BIT{
    int N;
    vll a;
    void init(int n){
        a.resize(n+2,0);
        N = n;
    }
    void upd(int p, int val){
        for(++p; p <= N; p += p & -p)
            a[p] += val;
    }

    // sum[0,p]
    ll sum(int p){
        int ret = 0;
        for(++p; p; p -= p & -p)
            ret += a[p];
        return ret;
    }

    void range_upd(int l, int r, int v){
        upd(l, v);
        upd(r+1,-v);
        //debug(l,r);
    }
    ll point_query(int p){
        return sum(p);
    }
};

struct query{
    int l, r;
    bool operator<(const query &o)const{
        return r-l < o.r-o.l;
    }
};

const int MAXN = 3e5+5;

BIT bit;
query q[MAXN];
int N, M;

int main(){
    scan(N,M);
    bit.init(M+1);
    FOR(i,0,N) scan(q[i].l, q[i].r);
    sort(q, q+N);
    int qi=0;
    FOR(d,1,M+1){
        while(qi<N && q[qi].r-q[qi].l+1 < d){
            bit.range_upd(q[qi].l, q[qi].r, 1);
            qi++;
        }
        //debug(d,qi);
        int ret = N-qi;
        for(int i=0; i<=M; i+=d){
            //debug(i, bit.point_query(i));
            ret += bit.point_query(i);
        }
        printf("%d\n",ret);
    }
    
}
