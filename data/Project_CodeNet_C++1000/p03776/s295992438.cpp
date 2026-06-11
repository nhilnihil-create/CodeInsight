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

ll gcd( ll a, ll b ){
    if( a<b ) swap(a,b);
    ll c;
    while( a%b ){
        c = b;
        b = a%b;
        a = c;
    }
    return b;
}

ll comb( ll n, ll r ){
    if( n<r ) swap(n,r);
    ll up = 1;
    ll lw = 1;
    ll di;
    Rep(i,r){
        up *= (n-i);
        lw *= (r-i);
        di = gcd(up,lw);
        up /= di;
        lw /= di;
    }
    return up/lw;
}

int main() {

    int N,A,B;
    Scd3(N,A,B);

    vl v(N);
    Rep(i,N) Scll(v[i]);

    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());

    double ans = 0.0;
    Rep(i,A) ans += v[i];
    ans /= A;

    ll mul = 0;
    bool uni = true;
    Rep(i,A) uni = uni && v[i] == v[0];
    ll cnt = 0;
    ll low = 0;
    Rep(i,N){
        if( v[i] == v[A-1] ){
            cnt++;
            if( i < A ) low++;
        }
    }

    mul += comb(cnt,low);
    if( uni ){
        Repe(i,B-A+1,1){
            if( v[A+i-1] != v[A-1] ) break;
            mul += comb(cnt,low+i);
        }
    }

    printf ("%.9lf\n", ans );
    printf ("%lld\n", mul );

    return 0;
}

