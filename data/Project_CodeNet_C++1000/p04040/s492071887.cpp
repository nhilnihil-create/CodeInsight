//
/*==========================================================*/
/*    Template ver 2017-0720    |    Created by JollyBee    */
/* DOMINUS pascit me, et nihil mihi deerit (Psalmorum 23:1) */
/*==========================================================*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<pii> vii;
const double EPS=(double)1e-9;
const double PI=(double)acos(-1.0);
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define FOR(i,n) for(int i=0;i<n;i++)
#define REPP(i,l,r,c) for(int i=l;i<=r;i+=c)
#define REP(i,l,r) REPP(i,l,r,1)
#define FORD(i,n) for(int i=n-1;i>=0;i--)
#define REVV(i,l,r,c) for(int i=l;i>=r;i-=c)
#define REV(i,l,r) REVV(i,l,r,1)
//random
int irand(int lo, int hi){
    return (((double)rand())/(RAND_MAX+1.0)) * (hi-lo+1) + lo;
}
//ll to string
string toString(ll x) {
    stringstream ss;
    ss << x;
    return ss.str();
}
//string to ll
ll toNumber(string S) {
    ll ret;
    sscanf(S.c_str(),"%lld",&ret);
    return ret;
}
// std::fill(start, end, value);
// for(auto it: DS){}

const int INF=(int)2e9;
const ll MOD=(ll)1e9+7;
/*==========================================================*/
/*                     END OF TEMPLATE                      */
/* DOMINUS pascit me, et nihil mihi deerit (Psalmorum 23:1) */
/*==========================================================*/

ll fast(ll a, ll p){
    if(p == 0) return (ll)1;
    ll res = fast(a, p>>1);
    res = (res * res) % MOD;
    if(p&1) res = (res * a) % MOD;
    return res;
}

const int N = (int)1e5;

pll fact[2*N+5];

int start(){
    fact[0] = mp((ll)1, (ll)1);
    REP(i,1,2*N){
        fact[i].fi = (fact[i-1].fi * (ll)i) % MOD;
        fact[i].se = fast(fact[i].fi, MOD-2);
    }
    return 0;
}

ll nCk(int n, int k){
    ll num = fact[n].fi;
    ll denum = (fact[n-k].se * fact[k].se) % MOD;
    return (num * denum) % MOD;
}

int main(){
    start();
    int h,w,a,b; scanf("%d %d %d %d", &h, &w, &a, &b);
    //
    ll res = 0;
    REP(i,b+1,w){
        ll reta = nCk(h-a-1 + i-1, i-1);
        ll retb = nCk(a-1 + w-i, a-1);
        res += (reta * retb) % MOD;
    }
    printf("%lld\n", res % MOD);
    return 0;
}
