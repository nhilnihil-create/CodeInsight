#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define pa(x,n) for(ll i=0;i<n;i++){cout<<(x[i])<<" \n"[i==n-1];};
#define pb push_back
#define fi first
#define be begin()
#define en end()
#define se second

using ll = long long;
using namespace std;
using pint = pair<int,int>;
using pll = pair<ll,ll>;
const int INFint = 1e9;
const ll INFll = 1e18;
ll MOD=1e9+7;

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a; } //最大公約数
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

int main(){
  ll H,W;
  cin>>H>>W;
  if (H%3 == 0 || W % 3==0){
    cout << 0 << endl;
    return 0;
  }
  ll ans(1e18);
  for (int i(1);i<H;i++){
    ll tmp = i*W;
    ll tmp2,tmp3;
    if (W%2==0){
      tmp2 = (H-i)*(W/2);
      tmp3 = (H-i)*(W/2);
    }else{
      tmp2 = (H-i)*(W-1)/2;
      tmp3 = (H-i)*(W+1)/2;
    }
    ll maxi = max(tmp,max(tmp2,tmp3));
    ll mini = min(tmp,min(tmp2,tmp3));
    ans = min(ans,maxi - mini);
    //cout << ans << endl;
  }
  for (int i(1);i<W;i++){
    ll tmp = i*H,tmp2,tmp3;
    if (H%2==0){
      tmp2 = (W-i)*(H/2);
      tmp3 = (W-i)*(H/2);
    }else{
      tmp2 = (W-i)*(H-1)/2;
      tmp3 = (W-i)*(H+1)/2;
    }
    ll maxi = max(tmp,max(tmp2,tmp3));
    ll mini = min(tmp,min(tmp2,tmp3));
    ans = min(ans,maxi - mini);
  }
  ans = min(ans,min(H,W));
  cout << ans << endl;
  return 0;
}

