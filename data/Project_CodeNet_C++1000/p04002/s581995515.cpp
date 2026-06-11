#include <bits/stdc++.h>
using namespace std;

#define NDEBUG
#ifdef DEBUG
#include "../cout11.h"
#undef NDEBUG
#endif
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

ll gcd(ll a, ll b) { while(a) swap(a, b%=a); return b; }

const ll MOD=1000000007LL;

ll ADD(ll x, ll y) { return (x+y) % MOD; }
ll SUB(ll x, ll y) { return (x-y+MOD) % MOD; }
ll MUL(ll x, ll y) { return x*y % MOD; }
ll POW(ll x, ll e) { ll v=1; for(; e; x=MUL(x,x), e>>=1) if (e&1) v = MUL(v,x); return v; }
ll DIV(ll x, ll y) { /*assert(y%MOD!=0);*/ return MUL(x, POW(y, MOD-2)); }
// ll comb(ll n, ll k) { ll v=1; for(ll i=1; i<=k; i++) v = DIV(MUL(v, n-i+1),i); return v; }
//

vector<ll> solve(int H,int W,int N,vi& a,vi& b) {
    set<ii> ab;
    rep(i,N) ab.insert( ii(a[i],b[i]) );
    // cerr << "ab:" << ab << endl;

    set<ii> locs;
    rep(i,N){
        for (int dx=-2; dx<=0; ++dx)
        for (int dy=-2; dy<=0; ++dy){
            int x = a[i]+dx, y = b[i]+dy;
            if (IN(x, 0, H-3) && IN(y, 0, W-3)) {
                locs.insert( ii(x,y) ); // 9 x 1e5
            }
        }
    }

    vector<ll> ans(10, 0LL);
    ans[0] = (ll)(H-2)*(W-2) - locs.size();
    for (ii loc : locs) { // 9e5
        // cerr << loc << " : ";
        int cnt = 0;
        rep(i,3) rep(j,3) { // 9
            int x=loc.first+i, y=loc.second+j;
            if (found(ab, ii(x,y))) ++cnt;
        }
        // cerr << cnt << endl;
        ans[cnt]++;
    }
    return ans;
}

int main() {
    int H,W,N; cin >>H>>W>>N;
    vi a(N),b(N);
    rep(i,N) { cin >> a[i] >> b[i]; a[i]--; b[i]--; }
    vector<ll> ans = solve(H,W,N,a,b);
    rep(i,10){
        cout << ans[i] << endl;
    }
    return 0;
}
