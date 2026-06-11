#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

// template {{{  0 
// using {{{ 1
using ll = long long int;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vii = vector<pii>;
using vll = vector<pll>;
// }}} 1
// definition {{{ 1
// scaning {{{ 2
#define Scd(x) scanf("%d", &x)
#define Scd2(x,y) scanf("%d%d", &x, &y)
#define Scd3(x,y,z) scanf("%d%d%d", &x, &y, &z)
#define Scll(x) scanf("%lld", &x)
#define Scll2(x,y) scanf("%lld%lld", &x, &y)
#define Scll3(x,y,z) scanf("%lld%lld%lld", &x, &y, &z)
#define Scc(c) scanf("%c", &c);
#define Scs(s) scanf("%s", s);
#define Scstr(s) scanf("%s", &s);
// }}} 2
// constants {{{ 2
#define EPS (1e-7)
#define INF (2e9)
#define PI (acos(-1))
// }}} 2
// systems {{{ 2
#define Repe(x,y,z) for(ll x = z; x < y; x++)
#define Rep(x,y) Repe(x,y,0)
#define RRepe(x,y,z) for(ll x = y-z-1; x >= 0; x--)
#define RRep(x,y) RRepe(x,y,0)
// }}} 2
// output {{{ 2
#define YesNo(a) (a)?printf("Yes\n"):printf("No\n")
#define YESNO(a) (a)?printf("YES\n"):printf("NO\n")
// }}} 2
// }}} 1
// input {{{ 1
// }}} 1
// }}} 0

int main() {

    int N,L;
    Scd(N);
    vi x(N);
    Rep(i,N){
        Scd(x[i]);
    }
    Scd(L);

    vector<vi> pare(N,vi(20));

    int to = 1;
    Rep(from,N){
        while( to < N-1 && x[to+1] <= x[from]+L ){
            to++;
        }
        pare[from][0] = to;
    }

    RRep(from,N){
        Repe(di,20,1){
            pare[from][di] = pare[pare[from][di-1]][di-1];
        }
    }

    auto paresch = [&]( int a, int dis){
        int bi = 0;
        while( dis >= (1<<bi) ){
            if( dis & (1<<bi) ) a = pare[a][bi];
            bi++;
        }
        return a;
    };

    auto sch = [&]( int a, int b ){
        int l = 0,r = N-1,c = 1;
        // (l,r]
        while( r-l > 1 ){
            c = (r+l)/2;
            if( paresch(a,c) >= b ) r = c;
            else l = c;
        }
        return r;
    };

    int Q;
    int a,b;
    Scd(Q);
    Rep(qqi,Q){
        Scd2(a,b);
        a--,b--;
        if( a>b ) swap(a,b);
        printf ("%d\n", sch(a,b) );
    }

    return 0;
}

