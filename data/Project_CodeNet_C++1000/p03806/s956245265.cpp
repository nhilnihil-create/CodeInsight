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

const ll INF = 1e9+10;
const ll MOD = 1e9+7;
const ll LINF = 1e18;

ll dp[45][505][505]; // i番目まででma=j, mb=k とするときの最小値

signed main()
{
  cin.tie( 0 ); ios::sync_with_stdio( false );
  
  ll n,ma,mb; cin>>n>>ma>>mb;
  
  vll a(n), b(n), c(n);
  rep(i,n) cin>>a[i]>>b[i]>>c[i];
  
  rep(i,n+1) rep(j,505) rep(k,505) dp[i][j][k]=LINF;
  dp[0][0][0]=0;
  
  rep(i,n){
    for(ll j=0; j<=400; j++){
      for(ll k=0; k<=400; k++){
        if(dp[i][j][k]==LINF) continue;
        chmin(dp[i+1][j][k], dp[i][j][k]);
        chmin(dp[i+1][j+a[i]][k+b[i]], dp[i][j][k]+c[i]);
        // cout<<i<<' '<<j<<' '<<k<<' '<<dp[i+1][j+a[i]][k+b[i]]<<endl;
      }
    }
  }
  
  ll ans=LINF;
  for(ll i=1; i*ma<=400; i++){
    if(dp[n][i*ma][i*mb]==-1) continue;
    chmin(ans, dp[n][i*ma][i*mb]);
  }
  if(ans==LINF) cout<<-1<<endl;
  else cout<<ans<<endl;
}