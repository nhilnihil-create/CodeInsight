#include<bits/stdc++.h>
using namespace std;
typedef long long unsigned int ll;

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

    int N;
    int a[103];
    Scd(N);
    Rep(i,N){
        Scd(a[i]);
    }

    sort( a,a+N );
    reverse( a,a+N );

    int cnt = 0;
    int ai = 0;
    int pre = a[ai];
    int maxser = 0;
    bool imp = false;
    for(int i = N; i > 0; i-- ){
        cnt = 0;
        while( ai < N && a[ai] == i ){
            maxser = max( a[ai] , maxser );
            cnt++;
            ai++;
        }
        if( maxser ){
            if( i == (maxser+1)/2 ){
                if( cnt != (1 + maxser%2)  ) imp = true;
                break;
            }
            if( cnt < 2  ) imp = true;
        }
        if( imp ) break;
    }
    printf ( imp ? "Impossible\n" : "Possible\n");

    return 0;
}

