#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define pa(x,n) for(ll i=0;i<n;i++){cout<<(x[i])<<" \n"[i==n-1];};
#define pb push_back

using ll = long long;
using namespace std;
using pint = pair<int,int>;
using pll = pair<ll,ll>;
const int INFint = 1e9;
const ll INFll = 1e18;
ll MOD=1e9+7;

ll gcd(ll a, ll b) { return __gcd(a,b); } //最大公約数
ll lcm(ll a, ll b) { return a/gcd(a,b)*b; } //最大公倍数

// aのn乗をMODで割りながら計算する
ll modpow(ll a, ll n) {
  long long res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % MOD;
    a = a * a % MOD;
    n >>= 1; // right shift
  }
  return res;
}

// MODを法としたaの逆元を計算する
ll modinv(ll a) {
  return modpow(a, MOD - 2);
}
const int MAX = (int)1e6;
long long fac[MAX], finv[MAX], inv[MAX];
// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
     for (int i = 2; i < MAX; i++){
         fac[i] = fac[i - 1] * i % MOD;
         inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
         finv[i] = finv[i - 1] * inv[i] % MOD;
     }
 }
 // 二項係数計算
 long long COM(int n, int k){  //nCkの計算をする
     if (n < k) return 0;
     if (n < 0 || k < 0) return 0;
     return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
 }
 //main関数にCOMinit();を忘れない

int main(){
  ll n,a,b,x[100000];
  cin>>n>>a>>b;
  for (int i(0);i<n;i++) cin>>x[i];
  ll ans(0);
  int now(x[0]);
  for (int i(1);i<n;i++){
    int next = x[i];
    if (a*(next - now) > b){
      ans += b;
    }else{
      ans += a*(next - now);
    }
    now = next;
  }
  cout << ans << endl;
  return 0;
}

