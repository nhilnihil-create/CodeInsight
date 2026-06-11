#include "bits/stdc++.h"

#define MOD 1000000007
#define rep(i, n) for(ll i=0; i < (n); i++)
#define ALL(v) v.begin(),v.end()

using namespace std;
typedef long long int ll;
typedef vector<ll> llvec;
typedef vector<double> dvec;
typedef pair<int, int> P;


ll mod(ll a, ll mod){
  ll res = a%mod;
  if(res<0)res=res + mod;
  return res;
}

ll modpow(ll a, ll n, ll mod){
  ll res=1;
  while(n>0){
    if(n&1) res=res*a%mod;
    a=a*a%mod;
    n>>=1;
  }
  return res;
}

ll modinv(ll a, ll mod){
  return modpow(a, mod-2, mod);
}

bool is_prime(ll n){
  ll i = 2;
  if(n==1)return false;
  if(n==2)return true;
  bool res = true;
  while(i*i <n){
    if(n%i==0){
      res = false;
    }
    i = i+1;
  }

  //if(i==1)res = false;
  if(n%i==0)res=false;
  return res;
}

int N, A;
int x[51];
ll dp[51][10000];
int shift = 5000;

ll dpf(int n, int sum){
  if(dp[n][sum+shift]>=0){
    return dp[n][sum+shift];
  }else{
    if(n==1){
      dp[n][sum+shift]=0;
      if(sum==x[n]){
        dp[n][sum+shift] += 1;
      }
      if(sum == 0){
        dp[n][sum+shift] += 1;
      }
      return dp[n][sum+shift];
    }else{
      dp[n][sum + shift] = dpf(n-1, sum) + dpf(n-1, sum - x[n]);
      return dp[n][sum + shift];
    }
  }
}

void dp_reset(){
  rep(i, 51){
    rep(j, 10000){
      dp[i][j] = -100;
    }
  }
  return;
}
/******************************************
** A main function is start from here  ****
*******************************************/
int main(){
  cin >> N >> A;
  for(int i=1;i<=N;i++){
    cin >> x[i];
    x[i] -= A;
  }
  
  dp_reset();
  cout << dpf(N, 0) - 1;
  
  
  return 0;
}
