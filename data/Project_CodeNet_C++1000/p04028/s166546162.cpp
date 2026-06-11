#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll MOD = 1000000007;
const ll INF = 10000000000000;
#define all(v) v.begin(), v.end()

ll modPow(ll a, ll n) {
  if (n == 0) return 1; // 0乗にも対応する場合
  if (n == 1) return a % MOD;
  if (n % 2 == 1) return (a * modPow(a, n - 1)) % MOD;
  ll t = modPow(a, n / 2);
  return (t * t) % MOD;
}

int main(){
  ll N;
  string S;
  cin >> N >> S;
  vector<vector<ll>> dp(N,vector<ll>(N+1,0));
  rep(i,N){
    rep(j,N+1){
      if(i==0){
        if(j==0||j==1){
          dp.at(i).at(j)=j+1;
        }
      }else{
        if(j==0){
          dp.at(i).at(j)=dp.at(i-1).at(j)+dp.at(i-1).at(j+1);
        }else{
          if(j==N){
            dp.at(i).at(j)=2*dp.at(i-1).at(j-1);
          }else{
            dp.at(i).at(j)=2*dp.at(i-1).at(j-1)+dp.at(i-1).at(j+1);
          }
        }
      }
      dp.at(i).at(j)%=MOD;
    }
  }
  dp.at(N-1).at((ll)S.size())*=modPow(500000004,(ll)S.size());
  dp.at(N-1).at((ll)S.size())%=MOD;
  cout << dp.at(N-1).at((ll)S.size()) << endl;
        
}