#include <bits/stdc++.h>
      
#define FOR(i,a,b) for( ll i = (a); i < (ll)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define YYS(x,arr) for(auto& x:arr)
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort( (x).begin(),(x).end() )
#define REVERSE(x) reverse( (x).begin(),(x).end() )
#define UNIQUE(x) (x).erase( unique( ALL( (x) ) ) , (x).end() )
#define PW(x) (1LL<<(x))
#define SZ(x) ((ll)(x).size())
#define SHOW(x) cout << #x << " = " << x << endl
#define SHOWA(x,n) for( int i = 0; i < n; i++ ){ cout << x[i] << " "; } cout << endl

#define pb emplace_back
#define fi first
#define se second
     
using namespace std;

typedef long double ld;
typedef long long int ll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<ld> vd;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vpl> gr;
typedef vector<vl> ml;
typedef vector<vd> md;
typedef vector<vi> mi;
     
const ll INF = (ll)1e9 + 10;
const ll INFLL = (ll)1e18 + 10;
const ld EPS = 1e-12;
const ll MOD = 1e9+7;
     
template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }
template<class T> inline T sq( T a ){ return a * a; }

ll in(){ ll x; scanf( "%lld" , &x ); return x; }
char yuyushiki[1000010]; string stin(){ scanf( "%s" , yuyushiki ); return yuyushiki; }

// head

int n;
ll a[100010];
vi p;

char op[100010];
ll sum[100010];

ll ans;

int main(){

  n = in();
  a[0] = in();
  op[0] = '+';
  FOR( i , 1 , n ){
    string s = stin();
    a[i] = in();
    op[i] = s[0];
    if( op[i] == '-' ){
      p.pb( i );
    }
  }
  p.pb( n );

  REP( i , n ){
    sum[i+1] = sum[i] + a[i];
  }

  ll cur = 0;
  REP( i , n ){
    if( op[i] == '-' ){
      int ne = *upper_bound( ALL(p) , i );

      ll res = cur - ( sum[ne] - sum[i] ) + ( sum[n] - sum[ne] );

      chmax( ans , res );
      
      cur -= a[i];
    } else {
      cur += a[i];
    }
  }

  chmax( ans , cur );

  cout << ans << endl;
  
  return 0;
}
