#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
#include<algorithm>//next_permutation
#define rep(i,n) for (int i = 0;i < (n);i++)
#define all(v) v.begin(),v.end()
#define dec(n) cout << fixed << setprecision(n);
#define large "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define small "abcdefghijklmnopqrstuvwxyz"
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using vl = vector<ll>;
using vvl = vector<vl>;

ll gcd(ll a,ll b){
  if(b == 0) return a;
  return gcd(b , a % b);
}

const ll MOD = 998244353;
const ll MAX = 200001;

ll mod(ll a){
  return a % MOD;
}

ll lcm(ll a,ll b){
  return (a*b)/gcd(a,b);
}

ll fac[MAX], finv[MAX], inv[MAX];

void nCrprep() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (ll i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

ll nCr(ll n, ll r){
    if (n < r) return 0;
    if (n < 0 || r < 0) return 0;
    return fac[n] * (finv[r] * finv[n - r] % MOD) % MOD;
}

ll nCrcheep(ll n,ll r){
  if(r == 0) return 1;
  else if(r == 1) return n;
  else return nCrcheep(n-1,r-1)*n/r;
}

int main(){
  ll n,p; cin >> n >> p; ll cnt1 = 0; ll cnt0 = 0;
  ll cnt = 0;
  
  rep(i,n){
    ll x; cin >> x; 
    if(x % 2 == 0) cnt0++;
    else cnt1++;
  }
  
  nCrprep();
  
  if(p == 0){
    for(ll i=0; i <= cnt1; i+=2){
      cnt += nCrcheep(cnt1,i);
    }
  }
  else{
    for(ll i=1; i <= cnt1; i+=2){
      cnt += nCrcheep(cnt1,i);
    }
  }
  ll power = 1;
  rep(i,cnt0){
    power *= 2;
  }
  cout << cnt*power  << endl;
  
  
}