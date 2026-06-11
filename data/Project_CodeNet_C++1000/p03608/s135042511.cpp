#include <bits/stdc++.h>

using namespace std ;
typedef long long ll;
typedef string str;
typedef pair<int, int> pii;
typedef vector<int> vint;
typedef vector<double> vdou ;
typedef vector<ll> vll;
typedef vector<vint> vvint;
typedef vector<str> vstr;
typedef pair<ll,ll> pll ;
typedef vector<pii> vpii ;
typedef vector<pll> vpll ;

#define REP(i, n) for (ll (i) = 0; (i) < (ll)(n); i++) 
#define FOR(i, a, b) for(ll (i) = a; (i) < (ll)b; i++)
#define ALL(v) (v).begin(),(v).end()
#define MOD 1000000007
#define CHI 1000000000000000003
#define NIL -1
#define FI first
#define SE second
#define MP make_pair
#define PB push_back
#define SZ(x)  (ll)x.size()
#define SP(x)  setprecision((ll)x)

const int INF = 1e9;
const ll LINF = 1e18;
const double EPS = 1e-9;
const double PI = M_PI;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
ll gcd(ll a, ll b) {return b ? gcd(b, a % b) : a;} //最大公約数
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;} //最小公倍数

void yes(){
  cout <<"Yes"<<endl ;
}
void no(){
  cout <<"No"<<endl ;
}
//-----------------------------------------


const int MAX_V = 300 ;

int d[MAX_V][MAX_V] ;
int n ;

void war(){
  for(int k=0;k<n;k++){
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        d[i][j] = min(d[i][j],d[i][k] + d[k][j]) ;
      }
    }
  }
}






//-----------------------------------------
int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  int m, r ;
  cin >> n >> m >> r ;
  vint num(r) ;
  REP(i,r){
    int a ;
    cin >> a ;
    num[i] = a-1 ;
  }
  
  REP(i,n){
    REP(j,n){
      d[i][j] = INF ;
    }
  }
  REP(i,n){
    d[i][i] = 0 ;
  }
  
  REP(i,m){
    int b, c, e ;
    cin >> b >> c >> e ;
    d[b-1][c-1] = e ;
    d[c-1][b-1] = e ;
  }
  
  war() ;
  
  sort(ALL(num)) ;
  
  ll ans = INF ;
  
  do{
    ll tmp = 0 ;
    REP(i,r-1){
      tmp += d[num[i]][num[i+1]] ;
    }
    ans = min(tmp,ans) ;
  }
  while(next_permutation(ALL(num))) ;
  
  cout << ans <<endl ;
    
  
  
  return 0 ;
}

