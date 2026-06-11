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

const int N = (int)1e5;
const int DEP = 17;

int dat[N+5];
int tab[N+5][DEP+1];

int main(){
    int n; scanf("%d", &n);
    REP(i,1,n) scanf("%d", dat+i);
    dat[n+1] = (int)2e9 + 10;
    int l; scanf("%d", &l);
    //
    for(int i=1,j=2; i<=n; i++){
        for(; dat[j] - dat[i] <= l; j++);
        tab[i][0] = j-1;
    }
    // build
    REP(j,1,DEP) REP(i,1,n) tab[i][j] = tab[ tab[i][j-1] ][j-1];
    // do
    int q; scanf("%d", &q);
    FOR(xxx,q){
        int a,b; scanf("%d %d", &a, &b);
        if(a > b) swap(a,b);
        //
        int res = 0;
        REV(j,DEP,0) if(tab[a][j] < b){
            res += 1 << j;
            a = tab[a][j];
        }
        res += 1;
        // print
        printf("%d\n", res);
    }
    return 0;
}
