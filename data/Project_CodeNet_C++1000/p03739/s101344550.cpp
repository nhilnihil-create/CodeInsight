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




















//-----------------------------------------
int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n ;
  cin >> n ;
  vll a(n) ;
  vll sum(n,0) ;
  ll x1 = 0 ;
  ll x2 = 0 ;
  ll ans1 = 0 ;
  ll ans2 = 0 ;
  vector<char> ch1(n) ;
  vector<char> ch2(n) ;
  REP(i,n){
    cin >> a[i] ;
  }
  REP(i,n){
    if(i%2==0){
      ch1[i] = '+' ;
    }
    else{
      ch1[i] = '-' ;
    }
  }
  
  REP(i,n){
    if(i%2==1){
      ch2[i] = '+' ;
    }
    else{
      ch2[i] = '-' ;
    }
  }
  
  
  sum[0] = a[0] ;
  REP(i,n-1){
    sum[i+1] = sum[i] + a[i+1] ;
  }
  
  REP(i,n){
    int y = sum[i] ;
    y += x1 ;
    if(ch1[i]=='+'){
      if(y>0){
        continue ;
      }
      else if(y==0){
        x1++ ;
        ans1++ ;
      }
      else{
        x1 += abs(y) + 1 ;
        ans1 += abs(y) + 1 ;
      }
    }
    else{
      if(y<0){
        continue ;
      }
      else if(y==0){
        x1-- ;
        ans1++ ;
      }
      else{
        x1 -= abs(y) + 1 ;
        ans1 += abs(y) + 1 ;
      }
    }
  }



  REP(i,n){
    int y = sum[i] ;
    y += x2 ;
    if(ch2[i]=='+'){
      if(y>0){
        continue ;
      }
      else if(y==0){
        x2++ ;
        ans2++ ;
      }
      else{
        x2 += abs(y) + 1 ;
        ans2 += abs(y) + 1 ;
      }
    }
    else{
      if(y<0){
        continue ;
      }
      else if(y==0){
        x2-- ;
        ans2++ ;
      }
      else{
        x2 -= abs(y) + 1 ;
        ans2 += abs(y) + 1 ;
      }
    }
  }
  
  
  cout << min(ans1,ans2) <<endl ;
        
      
        
  
  
  
  return 0 ;
}