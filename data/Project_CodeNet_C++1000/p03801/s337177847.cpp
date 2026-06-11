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
    Scd(N);
    vector<int> a(N);
    multimap<int,int> m;
    priority_queue<int> p;
    int ind = INF;

    p.push(0);
    Rep(i,N){
        Scd(a[i]);
        m.insert( {a[i],i} );
        if( p.top() < a[i] ) ind = i;
        p.push(a[i]);
    }

    vector<ll> ans(N);

    ll cnt = 0;
    ll diff = 0;
    ll tmp = p.top();
    ll top = 0;
    while( !p.empty() ){
        top = p.top();
        if( top == 0 ) break;
        while( p.top() == top ) p.pop();


        auto it = m.find(top);
        while( it != m.end() ){
            cnt++;
            ind = min( ind,it->second );
            m.erase(it);
            it = m.find(top);
        }

        diff = top - p.top();

        // printf ("!%llu: %llu*%llu \n", top, cnt, diff );

        ans[ind] += cnt*diff;
    }

    Rep(i,N){
        printf ("%llu\n", ans[i] );
    }

    return 0;
}

