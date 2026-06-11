#include <bits/stdc++.h>
//typedef
//-------------------------#include <bits/stdc++.h>
 
const double pi = 3.141592653589793238462643383279;
 
 
using namespace std;
 
//conversion
//------------------------------------------
inline int toInt(string s) { int v; istringstream sin(s); sin >> v; return v; }
template<class T> inline string toString(T x) { ostringstream sout; sout << x; return sout.str(); }
inline int readInt() { int x; scanf("%d", &x); return x; }
 
//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<long long, long long> PLL;
typedef pair<int, PII> TIII;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;
 
 
//container util
 
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define SQ(a) ((a)*(a))
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
 
 
//repetition
//------------------------------------------
#define FOR(i,s,n) for(int i=s;i<(int)n;++i)
#define REP(i,n) FOR(i,0,n)
#define MOD 1000000007
 
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
 
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const double EPS = 1E-8;
 
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
 
class UnionFind {
public:
    vector <int> par; 
    vector <int> siz; 

    UnionFind(int sz_): par(sz_), siz(sz_, 1) {
        for (ll i = 0; i < sz_; ++i) par[i] = i;
    }
    void init(int sz_) {
        par.resize(sz_);
        siz.assign(sz_, 1LL);
        for (ll i = 0; i < sz_; ++i) par[i] = i;
    }
 
    int root(int x) { 
        while (par[x] != x) {
            x = par[x] = par[par[x]];
        }
        return x;
    }
 
    bool merge(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (siz[x] < siz[y]) swap(x, y);
        siz[x] += siz[y];
        par[y] = x;
        return true;
    }
 
    bool issame(int x, int y) { 
        return root(x) == root(y);
    }
 
    int size(int x) { 
        return siz[root(x)];
    }
};
 
 
ll modPow(ll x, ll n, ll mod = MOD){
    ll res = 1;
    while(n){
        if(n&1) res = (res * x)%mod;
 
        res %= mod;
        x = x * x %mod;
        n >>= 1;
    }
    return res;
}
 
#define SIEVE_SIZE 5000000+10
bool sieve[SIEVE_SIZE];
void makeSieve(){
    for(int i=0; i<SIEVE_SIZE; ++i) sieve[i] = true;
    sieve[0] = sieve[1] = false;
    for(int i=2; i*i<SIEVE_SIZE; ++i) if(sieve[i]) for(int j=2; i*j<SIEVE_SIZE; ++j) sieve[i*j] = false;
}
 
bool isprime(ll n){
    if(n == 0 || n == 1) return false;
    for(ll i=2; i*i<=n; ++i) if(n%i==0) return false;
    return true;
}
 
const int MAX = 2000010;
long long fac[MAX], finv[MAX], inv[MAX];
 
// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
 
// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
 
long long extGCD(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long d = extGCD(b, a%b, y, x);
    y -= a/b * x;
    return d;
}
// 負の数にも対応した mod (a = -11 とかでも OK) 
inline long long mod(long long a, long long m) {
    return (a % m + m) % m;
}
 
// 逆元計算 (ここでは a と m が互いに素であることが必要)
long long modinv(long long a, long long m) {
    long long x, y;
    extGCD(a, m, x, y);
    return mod(x, m); // 気持ち的には x % m だが、x が負かもしれないので
}
ll GCD(ll a, ll b){
    
    if(b == 0) return a;
    return GCD(b, a%b);
}

typedef vector<ll> vec;
typedef vector<vec> mat;

mat mul(mat &A, mat &B) {
    mat C(A.size(), vec((int)B[0].size()));
    for(int i=0; i<A.size(); ++i){
        for(int k=0; k<B.size(); ++k){
            for(int j=0; j<B[0].size(); ++j){
                C[i][j] = (C[i][j] + A[i][k] * B[k][j] %MOD) % MOD;
            }
        }
    }
    return C;
}
mat matPow(mat A, ll n) {
    mat B(A.size(), vec((int)A.size()));
 
    for(int i=0; i<A.size(); ++i){
        B[i][i] = 1;
    }
 
    while(n > 0) {
        if(n & 1) B = mul(B, A);
        A = mul(A, A);
        n >>= 1;
    }
    return B;
}

map<ll,ll> prime_factor(ll n) {
  map<ll,ll> res;
  for(ll i=2; i*i <= n; i++) {
      while(n%i == 0) {
          res[i]++;
          n /= i;
      }
  }

  if(n != 1) res[n] = 1;
  return res;
}


set<int> st[100010];
bool odd[100010];
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(12);
    
    int N,M; cin>>N>>M;
    vector<int> x(N);
    REP(i,N)cin>>x[i];

    map<int, int> mp;
    REP(i,N){
        mp[x[i]]++;
        st[x[i]%M].insert(x[i]);
    }
    REP(i,N){
        if(mp[x[i]]%2 == 1) odd[x[i]] = true;
    }

    int ans = 0;
    for(int i=1; i<=M/2; i++){

        if(M%2 == 0 && i == M/2){
            int num=0;
            for(auto e: st[i]){
                num += mp[e];
            }
            ans += num/2;
        }else{
            //cout << i << endl;
        // i, M-iのマッチング
        vector<int> is;
        vector<int> mis;
        for(auto e: st[i]){
            if(odd[e]) is.push_back(e);
        }
        for(auto e: st[M-i]){
            if(odd[e]) mis.push_back(e);
        }

        //奇数個どうしを消す
        for(int j=0; j<min(mis.size(), is.size()); j++){
            mp[mis[j]]--;
            mp[is[j]]--;

            //cout << mis[j] << " " << is[j] << endl; 
            ans++;
        }

        
        
        vector<int> a, b;
        for(int e: st[i]){
            if(mp[e]%2 != 0){
                a.push_back(e);

            }
        }
        for(int e: st[i]){
                if(mp[e]%2 == 1){
                    for(int j=0; j<mp[e]-1; j++){
                        a.push_back(e);
                    }
                }else{
                    for(int j=0; j<mp[e]; j++){
                        a.push_back(e);
                    }
                }
            
        }
        for(int e: st[M-i]){
            if(mp[e]%2 != 0){
                b.push_back(e);

            }
        }
        for(int e: st[M-i]){

                if(mp[e]%2 == 1){
                    for(int j=0; j<mp[e]-1; j++){
                        b.push_back(e);
                    }
                }else{
                    for(int j=0; j<mp[e]; j++){
                        b.push_back(e);
                    }
                }
            
        }
        for(int j=0; j<min(a.size(), b.size()); j++){
            mp[a[j]]--;
            mp[b[j]]--;

            ans++;
        }

        for(int e: st[i]){
            ans += mp[e]/2;
        }
        for(int e: st[M-i]){
            ans += mp[e]/2;
        }
        }

        //cout << i << " " << ans << endl;
    }

    {
        int num = 0;
        for(auto e: st[0]) num += mp[e];
        ans += num/2;
    }
    cout << ans << endl;
    return 0;
}