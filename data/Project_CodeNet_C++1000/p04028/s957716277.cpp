#include <bits/stdc++.h>
#define GET_MACRO(_1,_2,_3,_4,_5,_6,_7,_8,NAME,...) NAME
#define pr(...) cerr<< GET_MACRO(__VA_ARGS__,pr8,pr7,pr6,pr5,pr4,pr3,pr2,pr1)(__VA_ARGS__) <<endl
#define pr1(a) (#a)<<"="<<(a)<<" "
#define pr2(a,b) pr1(a)<<pr1(b)
#define pr3(a,b,c) pr1(a)<<pr2(b,c)
#define pr4(a,b,c,d) pr1(a)<<pr3(b,c,d)
#define pr5(a,b,c,d,e) pr1(a)<<pr4(b,c,d,e)
#define pr6(a,b,c,d,e,f) pr1(a)<<pr5(b,c,d,e,f)
#define pr7(a,b,c,d,e,f,g) pr1(a)<<pr6(b,c,d,e,f,g)
#define pr8(a,b,c,d,e,f,g,h) pr1(a)<<pr7(b,c,d,e,f,g,h)
using namespace std;
using Int = long long;
using _int = int;
using ll = long long;
using Double = long double;
const Int INF = (1LL<<55)+1e9; // ~ 3.6 * 1e16
const Int mod = (1e9)+7;
const Double EPS = 1e-8;
const Double PI = 6.0 * asin((Double)0.5);
using P = pair<Int,Int>;
using T = tuple<Int,Int,Int>;
template<class T> T Max(T &a,T b){return a=max(a,b);}
template<class T> T Min(T &a,T b){return a=min(a,b);}
ostream& operator<<(ostream& o,P p){return o<<"("<<p.first<<","<<p.second<<")";}
ostream& operator<<(ostream& o,T t){return o<<"("<<get<0>(t)<<","<<get<1>(t)<<","<<get<2>(t)<<")";}
istream& operator>>(istream& i,P &p){return i>>p.first>>p.second;}
ostream& operator<<(ostream& o,vector<auto> &a){Int i=0;for(auto t:a)o<<(i++?" ":"")<<t;return o;}
istream& operator>>(istream& i,vector<auto> &a){for(auto &t:a)i>>t;return i;}
void prArr(auto a,string s=" "){Int i=0;for(auto t:a)cout<<(i++?s:"")<<t;cout<<endl;}

ll mod_pow(ll x,ll n){
  ll res=1;
  while(n){
    if(n%2) res=res*x%mod;
    x=x*x%mod;
    n/=2;
  }
  return res;
}

Int inv(Int x){return mod_pow(x, mod-2);}

Int Add(_int &a,Int b){return a = (a + b)%mod;}
Int Sub(_int &a,Int b){return a = ((Int)a - b + mod)%mod;}
const Int N = 5010;
//dp[i][j] := i回打って長さがjになっている通り数
_int dp[N+1][N+1];
void DP(){
  dp[0][0] = 1;
  for(Int i=0;i<N;i++)
    for(Int j=0;j<N;j++){
      //type 0;
      Add(dp[i+1][j+1], dp[i][j]);
      
      //type 1;
      Add(dp[i+1][j+1], dp[i][j]);
      
      //type backSpace
      Add(dp[i+1][max(0LL,j-1)], dp[i][j]);
    }
}


Int solve(Int n, string str){
  DP();
  Int m = str.size();
  _int sum = dp[n][m];
  sum = sum * inv(mod_pow(2, m)) % mod;
  return sum;
}

signed main(){
  srand((unsigned)time(NULL));
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);

  Int n;
  string s;
  cin>>n;
  cin>>s;

  Int ans = solve(n, s);
  cout<<ans<<endl;

  
  return 0;
}
