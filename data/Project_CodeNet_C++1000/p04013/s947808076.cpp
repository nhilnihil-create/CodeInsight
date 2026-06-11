#include <bits/stdc++.h>
//----***やべーやつら***----
using namespace std;
#define int long long

//----***型定義***----
using ll = long long;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
typedef long double ld;
typedef pair<int,int> P;

//----***Like a Pythonista***----
#define REP(ii,jj,nn) for (ll ii=jj;ii<(nn);ii++)
#define RREP(ii,nn,jj) for (ll ii = nn; jj<ii;ii--)
#define each(i,...) for (auto&& i:__VA_ARGS__)
#define ALL(vec) (vec).begin(),(vec).end()
#define sum(...) accumulate(ALL(__VA_ARGS__),0LL)
#define dsum(...) accumulate(ALL(__VA_ARGS__),0.0L)
#define vec(type,name,...) vector<type> name(__VA_ARGS__)
template<class T> inline auto max(const T& a){ return *max_element(ALL(a)); }
template<class T> inline auto min(const T& a){ return *min_element(ALL(a)); }
inline ll gcd(ll a,ll b){if(b == 0) return a;return  gcd(b,a%b);}
inline ll lcm(ll a,ll b){ll g = gcd(a,b);return a / g * b;}

//----***定数***----
#define MOD 1000000007
#define INF 10*10
#define EPS 1e-9

//----***パーツ***----
#define fr first
#define se second

//----***入出力***---
#define print(out) cout<< out  << "\n";
#define debug(var)  do{std::cerr << #var << " ↓ "<<"\n";view(var);}while(0);
#define dbg cerr<<"🥺🥺🥺🥺🥺🥺"<<endl;
template<typename T> void view(T e){std::cout << e << std::endl;}
template<typename T> void view(const std::vector<T>& v){for(const auto& e : v){ std::cout << e << " "; } std::cout << std::endl;}
template<typename T> void view(const std::vector<std::vector<T> >& vv){ for(const auto& v : vv){ view(v); } }

signed main(){
  int N,A;cin>>N>>A;
  int ans=0;
  vector<int> v(N);
  REP(i,0,N){cin>>v[i];}

  vector<vector<vector<int>>> dp(N+5,vector<vector<int>>(N+5,vector<int>(N*50+10,0)));

  dp[0][0][0]=1;
  REP(j,1,N+1)REP(k,0,N+1)REP(s,0,N*50+10){
    int elem=0;
    if(j>0&&v[j-1]>s){
      elem=dp[j-1][k][s];
    }
    else if (j>0&&k>0&&v[j-1]<=s){
      elem=dp[j-1][k-1][s-v[j-1]]+dp[j-1][k][s];
    }
    dp[j][k][s]=elem;
  } 
  ans=0;
  REP(k,1,N+1){
    ans+=dp[N][k][k*A];
  }
  print(ans)

}
