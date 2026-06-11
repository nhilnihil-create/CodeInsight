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

const int OFFS = 2;

set<pii> dat;
ll res[15];

int main(){
    FOR(i,13) res[i] = (ll)0;
    dat.clear();
    //
    int h,w,n; scanf("%d %d %d", &h, &w, &n);
    res[0] = (ll)(h-2) * (ll)(w-2);
    FOR(xxx,n){
        int subs[5][5];
        int a,b; scanf("%d %d", &a, &b);
        REP(i,a-2,a+2) REP(j,b-2,b+2){
            subs[i-a+OFFS][j-b+OFFS] = (dat.find(mp(i,j)) != dat.end());
        }
        REP(i,a-1,a+1) REP(j,b-1,b+1){
            if(i-1 < 1 || h < i+1) continue;
            if(j-1 < 1 || w < j+1) continue;
            //
            int cnt = 0;
            REP(ix,i-1,i+1) REP(jx,j-1,j+1){
                cnt += subs[ix-a+OFFS][jx-b+OFFS];
            }
            res[cnt  ] -= 1;
            res[cnt+1] += 1;
        }
        dat.insert(mp(a,b));
    }
    FOR(i,10) printf("%lld\n", res[i]);
    return 0;
}
