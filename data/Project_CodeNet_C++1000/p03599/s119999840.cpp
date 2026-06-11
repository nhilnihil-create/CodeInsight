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

const ll INF = 1e15;
const ll MOD = 1e9+7;
const ll LINF = 1e18;


signed main()
{
  cin.tie( 0 ); ios::sync_with_stdio( false );
  ll a,b,c,d,e,f; cin>>a>>b>>c>>d>>e>>f;
  double noudo=-1;
  vll ans(2);
  for(ll x=0; x<=30; x++){
    for(ll y=0; y<=30; y++){
      ll water=(a*x+b*y)*100;
      if(water>f || water==0) continue;
      ll rem=f-water;
      for(ll s=0; c*s<=rem; s++){
        for(ll t=0; d*t<=rem; t++){
          ll sugar=c*s+d*t;
          if(sugar>rem) continue;
          if(sugar<=water/100*e){
            if(chmax(noudo, 100.0*sugar/(water+sugar))){
              // cout<<s<<' '<<t<<endl;
              ans[0]=water+sugar, ans[1]=sugar;
            }
          }
        }
      }
    }
  }
  cout<<ans[0]<<" "<<ans[1]<<endl;
}