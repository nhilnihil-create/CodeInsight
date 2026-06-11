#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using pll = pair<ll, ll>;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define rrep(i, m, n) for(ll i = m; i > n; i--)
#define Rep(i, m, n) for(ll i = m; i < n; i++)
#define all(vec) vec.begin(), vec.end()
#define lmax(x, y) max<ll>(x, y)
#define lmin(x, y) min<ll>(x, y)
#define tmax(x, y, z) lmax((x), lmax((y), (z)))
#define tmin(x, y, z) lmin((x), lmin((y), (z)))
#define MINUS(a) memset(a, 0xff, sizeof(a))
#define ZERO(a) memset(a, 0, sizeof(a))
const ll INF = 1LL << 60;
const ll MM = 1000000000; const ll MOD = MM + 7; const ll MMM=9223372036854775807;//2^63 -1
#define ADD(a,b) a = (a + ll(b)) % MOD
#define MUL(a,b) a = (a * ll(b)) % MOD
ll GCD(ll x, ll y){ if(y == 0) return x; else return GCD(y, x % y);}
ll LCM(ll x, ll y){ return x / GCD(x, y) * y;}
template<class T> inline bool chmin(T& a, T b){ if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T& a, T b){ if(a < b){ a = b; return true;} return false;}
template<typename A, size_t N, typename T> void FILL(A (&array)[N], const T &val){ fill( (T*)array, (T*)(array+N), val );}
// struct edge{ ll from, to, cost; };
// struct edge{ ll to, cost; };
// using Graph = vector<vector<ll>>;  // 重み無し
// using Graph = vector<edge>;  // 辺
// using Graph = vector<vector<edge>>;  // 重み付き
ll dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
ll ddx[8] = {1, 1, 0, -1, -1, -1, 0, 1}, ddy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

const ll MAX = 510000;
ll fac[MAX], finv[MAX], inv[MAX];


void COMinit(){
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for(ll i=2; i<MAX; i++){
        fac[i] = fac[i-1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i-1] * inv[i] % MOD;
    }
}


ll nCr(ll n, ll k) { if (n < k) return 0; if (n < 0 || k < 0) return 0; return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;}
ll nHr(ll n, ll r) { if (n == 0 && r == 0) return 1; else return nCr(n + r - 1, r); }
ll nPr(ll n, ll r) { if (r < 0 || n < r) return 0; else return (fac[n] * finv[n-r]) % MOD; }


int main(){
    ll n, m; cin >> n >> m;
    if(abs(n - m) > 1){
        cout << 0 << endl;
        return 0;
    }
    COMinit();
    ll ans = fac[n]*fac[m] % MOD;
    if(n == m) MUL(ans, 2);
    cout << ans << endl;
}
