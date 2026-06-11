#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define rep(i, n) for (long long i = (long long)(0); i < (long long)(n); ++i)
#define reps(i, n) for (long long i = (long long)(1); i <= (long long)(n); ++i)
#define rrep(i, n) for (long long i = ((long long)(n)-1); i >= 0; i--)
#define rreps(i, n) for (long long i = ((long long)(n)); i > 0; i--)
#define irep(i, m, n) for (long long i = (long long)(m); i < (long long)(n); ++i)
#define ireps(i, m, n) for (long long i = (long long)(m); i <= (long long)(n); ++i)
#define SORT(v, n) sort(v, v + n);
#define REVERSE(v, n) reverse(v, v+n);
#define vsort(v) sort(v.begin(), v.end());
#define all(v) v.begin(), v.end()
#define mp(n, m) make_pair(n, m);
#define cout(d) cout<<d<<endl;
#define coutd(d) cout<<std::setprecision(10)<<d<<endl;
#define cinline(n) getline(cin,n);
#define replace_all(s, b, a) replace(s.begin(),s.end(), b, a);
#define PI (acos(-1))
#define FILL(v, n, x) fill(v, v + n, x);
#define sz(x) long long(x.size())

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vs = vector<string>;
using vpll = vector<pair<ll, ll>>;
using vtp = vector<tuple<ll,ll,ll>>;
using vb = vector<bool>;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const ll INF = 1e9;
const ll MOD = 1e9+7;
const ll LINF = 1e18;

ll modpow(ll a, ll n) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % MOD;
    (a *= a) %= MOD;
    n >>= 1;
  }
  return res;
}

const ll maxf = 10000000;
ll fact[maxf+5];
ll ifact[maxf+5];

void fact_init(){
  fact[0] = 1;
  for(ll i=1; i<=maxf; i++) fact[i] = (fact[i-1] * i) % MOD;
  ifact[maxf]=modpow(fact[maxf],MOD-2);
  for(ll i=maxf; i>=1; i--) ifact[i-1] = (ifact[i] * i) % MOD;
}

ll comb(ll n, ll r){
  if(n<r || n<0 || r<0) return 0;
  if(fact[0] == 0) fact_init();
  return ((fact[n] * ifact[n-r]) % MOD * ifact[r]) % MOD;
}

ll naive_comb(ll n, ll r){
  ll res = 1;
  for (ll i = n; i > n - r; i--) res = res * i % MOD;
  for (ll i = 1; i <= r; i++) res = (res * modpow(i, MOD-2)) % MOD;
  return res;
}

signed main()
{
  cin.tie( 0 ); ios::sync_with_stdio( false );
  ll n; cin>>n;
  vll a(n+1);
  map<ll,ll> m;
  ll x;
  rep(i,n+1){
    cin>>a[i];
    m[a[i]]++;
    if(m[a[i]]==2) x=a[i];
  }
  
  ll l,r;
  bool flg=false;
  rep(i,n+1){
    if(a[i]==x){
      if(!flg){
        flg=true;
        l=i;
      }else{
        r=i;
      }
    }
  }
  
  rep(i,n+1){
    // n+1個からi個選ぶ方法は comb(n+1,i+1) 通り（このiは0始まりなので+1）
    // この中から1組ある同じ値によってできる組合せの重複を排除する
    // 重複ができる場合を考える
    // 1組の同じ値の左側、右側をそれぞれl,rとすると
    // 選ぶi個のうち1個がl,rのいずれかで、残りのi-1個はlより左の要素、またはrより右側の要素から選ぶ場合が重複する場合となる
    // よって、(i,l,rは0始まりなので) comb(l+n-r,i) が重複がある通り数となるのでこれを全体から引く
    ll ans=(comb(n+1,i+1)-comb(l+n-r,i)+MOD)%MOD;
    // cout<<l+n-r<<' '<<i+1<<' '<<comb(n+1,i+1)<<' '<<comb(l+n-r,i)<<' '<<ans<<endl;
    cout<<ans<<endl;
  }
  
}