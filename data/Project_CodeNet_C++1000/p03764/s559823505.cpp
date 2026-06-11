#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

// definition {{{ 1

// scaning {{{ 2
#define Scd(x) scanf("%d", &x)
#define Scd2(x,y) scanf("%d%d", &x, &y)
#define Scd3(x,y,z) scanf("%d%d%d", &x, &y, &z)

#define Scll(x) scanf("%lld", &x)
#define Scll2(x,y) scanf("%lld%lld", &x, &y)
#define Scll3(x,y,z) scanf("%llu%llu%llu", &x, &y, &z)

#define Scc(c) scanf("%c", &c);
#define Scs(s) scanf("%s", s);
#define Scstr(s) scanf("%s", &s);
// }}} 2

// constants {{{ 2
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
// }}} 2

// systems {{{ 2
#define Rep(x,y) for(int x = 0; x < y; x++)
#define Repe(x,y,z) for(int x = z; x < y; x++)
// }}} 2

// output {{{ 2
#define YesNo(a) (a)?printf("Yes\n"):printf("No\n");
// }}} 2

// }}} 1
long long int mod = 1000000007;

int main() {

    ll N,M;
    Scll2(N,M);

    vector<ll> x(N),y(M);

    Rep(i,N){
        Scll(x[i]);
    }
    Rep(i,M){
        Scll(y[i]);
    }

    sort(x.begin(),x.end());
    sort(y.begin(),y.end());

    ll ansx = 0;
    ll ansy = 0;
    ll ans = 0;
    N--,M--;

    Rep(i,N){
        ansx += ( x[i+1] - x[i] ) * (N-i)*(i+1);
        ansx %= mod;
    }
    Rep(i,M){
        ansy += ( y[i+1] - y[i] ) * (M-i)*(i+1);
        ansy %= mod;
    }


    printf ("%lld\n", ans = ansx * ansy % mod );


    return 0;
}

