#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

// definition {{{ 1

// scaning {{{ 2
#define Scd(x) scanf("%d", &x)
#define Scd2(x,y) scanf("%d%d", &x, &y)
#define Scd3(x,y,z) scanf("%d%d%d", &x, &y, &z)

#define Scll(x) scanf("%llu", &x)
#define Scll2(x,y) scanf("%llu%llu", &x, &y)
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

int main() {

    int n;
    int a,b;
    int m;
    int h[100003];

    Scd3(n,a,b);
    Rep(i,n){
        Scd(m);
        h[i] = m;
    }

    sort(h,h+n);

    ll from = 0;
    ll to = 1000000000;
    ll tmp;
    ll left = 0;

    while( to - from != 1 ){
        tmp = ( from + to ) / 2;
        left = 0;
        Rep(i,n){
            left += ( max<ll>( 0 , h[i] - b*tmp ) + a - b - 1 ) / ( a - b );
        }
        if( tmp >= left ){
            to = tmp;
        }else{
            from = tmp;
        }
    }



    printf ("%lld\n", to);

    return 0;
}

