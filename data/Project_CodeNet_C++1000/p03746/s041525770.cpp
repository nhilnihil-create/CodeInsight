#include <iostream>
#include <iomanip>
#include <string>
#include <stack>
#include <vector>
#include <complex>
#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
#include <iterator>
#include <map>
#include <set>
#include <queue>
#include <list>
#include <regex>
#include <limits>
#include <time.h>
#include <cstdint>
using namespace std;
using pii  = pair<int,int>;
using ll=long long;
using ld=long double;
#define pb push_back
#define mp make_pair
#define sc second
#define fr first
#define stpr setprecision
#define cYES cout<<"YES"<<endl
#define cNO cout<<"NO"<<endl
#define cYes cout<<"Yes"<<endl
#define cNo cout<<"No"<<endl
#define rep(i,n) for(ll i=0;i<(n);++i)
#define Rep(i,a,b) for(ll i=(a);i<(b);++i)
#define rrep(i,n) for(ll i=n-1;i>=0;i--)
#define rRep(i,a,b) for(ll i=a;i>=b;i--)
#define crep(i) for(char i='a';i<='z';++i)
#define psortsecond(A,N) sort(A,A+N,[](const pii &a, const pii &b){return a.second<b.second;});
#define ALL(x) (x).begin(),(x).end()
#define debug(v) cout<<#v<<":";for(auto x:v){cout<<x<<' ';}cout<<endl;
#define endl '\n'
int ctoi(const char c){
  if('0' <= c && c <= '9') return (c-'0');
  return -1;
}
ll gcd(ll a,ll b){return (b == 0 ? a : gcd(b, a%b));}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}
constexpr ll MOD=1000000007;
constexpr ll INF=1000000011;
constexpr ll MOD2=998244353;
constexpr ll LINF = 1001002003004005006ll;
constexpr ld EPS=10e-8;
template <class T, class U> inline bool chmax(T& lhs, const U& rhs) { if (lhs < rhs) { lhs = rhs; return 1; } return 0; }
template <class T, class U> inline bool chmin(T& lhs, const U& rhs) { if (lhs > rhs) { lhs = rhs; return 1; } return 0; }
template<typename T> istream& operator>>(istream& is,vector<T>& v){for(auto&& x:v)is >> x;return is;}
template<typename T,typename U> istream& operator>>(istream& is, pair<T,U>& p){ is >> p.first; is >> p.second; return is;}
template<typename T,typename U> ostream& operator>>(ostream& os, const pair<T,U>& p){ os << p.first << ' ' << p.second; return os;}
template<class T> ostream& operator<<(ostream& os, vector<T>& v){
  for(auto i=begin(v); i != end(v); ++i){
    if(i !=begin(v)) os << ' ';
    os << *i;
  }
  return os;
}

ll N,M;
vector<vector<ll>> E(100007);
ll  Ch[100007],Pre[100007],C[100007];
ll Z=0;

vector<ll>  V,F; 
int main(){
  cin >> N >>M;
  rep(i,M){
    ll A,B;
    cin >> A >> B;
    E[A].pb(B);
    E[B].pb(A);
  }
  V.pb(1);
  V.pb(E[1][0]);
  C[1]=1;
  C[E[1][0]]=1;
  while(1){
    ll Z=0;
    ll key=V[V.size()-1];
    rep(i,E[key].size()){
      if(C[E[key][i]]==0){
        V.pb(E[key][i]);
        C[E[key][i]]=1;
        Z=1;
        break;
      }
    }
    if(Z==0){
      break;
    }
  }
  ll key =V[0];
  while(1){
    ll Z=0;
    rep(i,E[key].size()){
      if(C[E[key][i]]==0){
        F.pb(E[key][i]);
        C[E[key][i]]=1;
        key=F[F.size()-1];
        Z=1;
        break;
      }
    }
    if(Z==0){
      break;
    }
  }
  cout << F.size()+V.size() << endl;
  reverse(ALL(F));
  if(F.size()>0){
    cout << F << " ";
  }
  cout << V << endl;
}
