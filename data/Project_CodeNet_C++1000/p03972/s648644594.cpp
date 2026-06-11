#include <bits/stdc++.h>
using namespace std;

#define NDEBUG
#include <cassert>

typedef long long ll;
typedef long double Double;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef pair<ll,ll> llll;
typedef pair<double,double> dd;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;
typedef vector<vector<ii>> vvii;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<long double> vD;

#define sz(a)  int((a).size())
#define pb  push_back
#define FOR(var,from,to) for(int var=(from);var<=(to);++var)
#define rep(var,n)  for(int var=0;var<(n);++var)
#define rep1(var,n)  for(int var=1;var<=(n);++var)
#define repC2(vari,varj,n)  for(int vari=0;vari<(n)-1;++vari)for(int varj=vari+1;varj<(n);++varj)
#define ALL(c)  (c).begin(),(c).end()
#define RALL(c)  (c).rbegin(),(c).rend()
#define tr(i,c)  for(auto i=(c).begin(); i!=(c).end(); ++i)
#define found(s,e)  ((s).find(e)!=(s).end())
#define mset(arr,val)  memset(arr,val,sizeof(arr))
#define mid(x,y) ((x)+((y)-(x))/2)
#define IN(x,a,b) ((a)<=(x)&&(x)<=(b))
#define cons make_pair


ll gcd(ll a, ll b) { while(a) swap(a, b%=a); return b; }

const ll MOD=1000000007LL;

ll ADD(ll x, ll y) { return (x+y) % MOD; }
ll SUB(ll x, ll y) { return (x-y+MOD) % MOD; }
ll MUL(ll x, ll y) { return x*y % MOD; }
ll POW(ll x, ll e) { ll v=1; for(; e; x=MUL(x,x), e>>=1) if (e&1) v = MUL(v,x); return v; }
ll DIV(ll x, ll y) { /*assert(y%MOD!=0);*/ return MUL(x, POW(y, MOD-2)); }


ll solve(int W,int H,vi& p,vi& q) {
    sort(ALL(p));
    sort(ALL(q));


    ll ans = 0;
    ans += accumulate(ALL(p), 0LL);
    ans += accumulate(ALL(q), 0LL);

    int pL = p.size(), qL = q.size();

    vll pAcc(pL+1);
    pAcc[0] = 0;
    rep(i,pL) pAcc[i+1] = pAcc[i] + p[i];

    for (int qj: q) {
        int ix = lower_bound(ALL(p), qj) - p.begin();
        ans += pAcc[ix] + (ll)qj * (pL - ix);
    }
    return ans;
}

int main() {
    int W, H; scanf("%d%d", &W, &H);
    vi p(W);
    rep(i,W) scanf("%d", &p[i]);
    vi q(H);
    rep(i,H) scanf("%d", &q[i]);
    cout << solve(W,H,p,q) << endl;
    return 0;
}
