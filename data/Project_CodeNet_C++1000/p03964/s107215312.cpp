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

int N;
ll T[10000], A[10000];
ll dp[10000];


/****************************************
** A main function starts from here  ****
*****************************************/
int main(){
  cin >> N;
  rep(i, N){
    cin >> T[i+1] >> A[i+1];
  }

  ll a=1;
  ll t = 1;
  ll total = a+t;
  for(int n=1;n<=N;n++){
    ll fact = max((a+A[n]-1)/A[n], (t+T[n]-1)/T[n]);
    a = fact * A[n];
    t = fact * T[n];
    total = a + t;
    //cout << total << endl;
  }
  cout << total;
  return 0;
}
