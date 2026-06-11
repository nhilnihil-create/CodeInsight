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

int main(){
  int N,A[100001]={0};
  cin>>N;
  for (int i(0);i<N;i++) {
    int a;
    cin>>a;
    A[a]++;
  }
  
  int cnt(0),tmp(0);
  for (int i(0);i<=100000;i++){
    if (A[i] != 0 && A[i] %2==0) tmp++;
    if (A[i] != 0) cnt++;
  }

  if (tmp % 2 == 1) cout << cnt - 1 << endl;
  else cout << cnt << endl;
  return 0;
}

