#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#include <set>
#include <tuple>
#define mkp make_pair
#define mkt make_tuple
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
template<class T> void chmin(T &a,const T &b){if(a>b) a=b;}
template<class T> void chmax(T &a,const T &b){if(a<b) a=b;}

void add(ll &a,ll b){
    a=(a+b)%MOD;
}

void mul(ll &a,ll b){
    a=a*b%MOD;
}

ll mod_pow(ll x,ll n){
  x%=MOD;
  ll res=1;
  while(n>0){
    if(n&1) res=res*x%MOD;
    x=x*x%MOD;
    n>>=1;
  }
  return res;
}

ll N;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin>>N;
  vector<ll> dp(2*N,0);
  for(int i=N;i<=2*N-1;i++) dp[i]=1;
  dp[N-1]=N;
  ll sum=0;
  for(int i=N-1;i<=2*N-1;i++) add(sum,dp[i]);

  for(int i=N-2;i>=0;i--){
      ll res=(N-1);
      mul(res,N-1);
      add(res,sum);
      add(res,MOD-dp[i+2]);

      dp[i]=res;
      add(sum,dp[i]);
      add(sum,MOD-dp[i+N+1]);
  }

  cout<<dp[0]<<endl;

  return 0;
}
