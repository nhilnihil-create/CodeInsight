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

#define INTSPACE 12
char _buf[INTSPACE*1000000 + 3];

int loadint() {
    if (fgets(_buf, INTSPACE+3, stdin)==NULL) return 0;
    return atoi(_buf);
}

int loadvec(vector<int>& v, int N=-1) {
    if (N == -1) {
        N = loadint();
        if (N==0) return 0;
    }
    int bufsize = INTSPACE*N + 3;
    if (fgets(_buf, bufsize, stdin)==NULL) return 0;
    v.resize(N);

    int i=0;
    bool last = false;
    for (char *p=&_buf[0]; ;) {
        char *q = p;
        while (*q > ' ') ++q;
        if (*q == 0x0D || *q == 0x0A) last = true;
        *q = 0;
        v[i++] = atoi(p);
        if (last || i == N) break;
        p = q+1;
    }
    // assert(i <= N);
    return i;
}
void read_cr() {
    fgets(_buf, 256, stdin);
}

#define cons make_pair

ll solve(int N, vvi& a) {
    vector<vector<ll>> d(N, vector<ll>(N));
    rep(i,N) rep(j,N) d[i][j] = a[i][j];

    rep(k,N) rep(i,N) rep(j,N) d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
    rep(i,N) rep(j,N) {
        if (d[i][j] != a[i][j]) return -1;
    }

    priority_queue<pair<int, ii>> pq;
    repC2(i,j,N){
        pq.push( cons(-a[i][j], ii(i,j)) );
    }

    vvi vis(N, vi(N, 1));;
    rep(i,N) vis[i][i] = 0;

    // auto x = pq.top().second; pq.pop();
    // vis[x.first][x.second] = 1;

    set<ii> visited;

    while (!pq.empty()) {
        auto x = pq.top(); pq.pop();
        // cerr<<x<<endl;
        ll dij = -x.first, i=x.second.first, j=x.second.second;
        if (!vis[i][j]) continue;
        visited.insert(ii(i,j));
        visited.insert(ii(j,i));
        rep(k,N){
            if (k==i || k==j) continue;
            if (!found(visited,ii(i,k))) {
                // assert(d[i][k] >= dij + d[j][k]);
                if (d[i][k] == dij + d[j][k]) vis[i][k] = vis[k][i] = 0;
            }
            if (!found(visited,ii(j,k))) {
                // assert(d[j][k] >= dij + d[i][k]);
                if (d[j][k] == dij + d[i][k]) vis[j][k] = vis[k][j] = 0;
            }
        }
    }
    // cerr << vis << endl;
    ll ans = 0;
    repC2(i,j,N) ans += (ll)vis[i][j] * a[i][j];
    return ans;
}

int main() {
    int N = loadint();
    vvi a(N, vi(N));
    rep(i,N) loadvec(a[i], N);
    cout << solve(N,a) << endl;
    // cout << (solve(N,a) ? "Yes":"No") << endl;
    return 0;
}
