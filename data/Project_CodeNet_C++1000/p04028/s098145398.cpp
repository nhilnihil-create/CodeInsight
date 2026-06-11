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

const int N = (int)5e3;

ll fast(ll a, ll p){
    if(p == 0) return (ll)1;
    ll res = fast(a, p>>1);
    res = (res * res) % MOD;
    if(p&1) res = (res * a) % MOD;
    return res;
}

ll dp[2][N+5];

char s[N+5];
int main(){
    // input
    int n; scanf("%d", &n);
    scanf("%s", s); int len = strlen(s);
    //
    REP(j,0,N) dp[0][j] = 0; dp[0][0] = 1;
    //
    REP(i,1,n){
        int idx = i % 2;
        int prev = (i-1) % 2;
        //
        REP(j,0,N){
            ll& res = dp[idx][j];  res = 0;
            if(j >  0) res += 2 * dp[prev][j-1];
            if(j == 0) res += dp[prev][j-0];
            if(j <  N) res += dp[prev][j+1];
            res %= MOD;
        }
    }
    //
    ll res = (dp[n%2][len] * fast(2, (MOD-2) * (ll)len)) % MOD;
    printf("%lld\n", res);
    return 0;
}
