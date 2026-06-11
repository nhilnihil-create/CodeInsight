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

// {{{ BinaryIndexedTree

// {{{実装
struct BIT{
    vector<int> data;
    int leng;
    BIT( int n ){
        init(n);
    }
    void init(int n){
        leng = n;
        data.assign(n,0);
        for(int i = 0; i < n; i++ ){
            data[i] = 0;
        }
    }
    int sum(int i){
        int s = 0;
        for( ; i>0; i -= i & -i ){
            s += data[i];
        }
        return s;
    }
    void add(int i, int x){
        for( ; i<=leng ; i += i & -i ){
            data[i] += x;
        }
    }
};
// }}}

// {{{ 説明
/*
BIT.data[1,n] : data
BIT.leng : quantity of data
BIT.init(n) : YES
BIT.sum(a) : sum of data[1,a]
BIT.add(i,x) : add data[i] with x
*/
// }}}

// }}}

int main() {

    int N,K;
    Scd2(N,K);

    vl a(N);
    vl s(N+1,0);
    vl sc(N+1,0);
    Rep(i,N){
        Scll(a[i]);
        a[i] -= K;
        s[i+1] += s[i] + a[i];
        sc[i+1] = s[i+1];
    }

    sort(sc.begin(),sc.end());

    map<ll,int> zatu;

    int ii = 1;
    Rep(i,N+1){
        if( zatu.find(sc[i]) == zatu.end() ) zatu[sc[i]] = ii++;
    }

    ll ans = 0;

    BIT b(N+334);
    Repe(i,N+1,0){
        // printf("%lld -> %d\n", s[i], zatu[s[i]]);
        ans += b.sum(zatu[s[i]]);
        b.add(zatu[s[i]],1);
    }

    printf ("%lld\n", ans );

    return 0;
}

