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
#define YESNO(a) (a)?printf("YES\n"):printf("NO\n");
// }}} 2

// }}} 1

int main() {

    int N;
    Scd(N);
    ll A,B,C,D;

    Scll2(A,B);
    Scll2(C,D);
    
    bool ans = false;
    ll L,R;
    Rep(i,N){
        R = A+i*(C+D) - C*(N-1);
        L = A+i*(C+D) - D*(N-1);
        if( L <= B && B <= R ) ans = true;
    }
  
    YESNO(ans);
    
}

