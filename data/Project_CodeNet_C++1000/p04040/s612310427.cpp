#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const ll mod = 1000000007;

// 階乗逆元
ll inv_mod(ll n,ll mod){
  ll a = n%mod,b = mod-2,ret=1;
  while(b>0){
    if(b&1) ret = (ret*a)%mod;
    a = (a*a)%mod;
    b >>= 1;
  }
  return ret;
}

ll comb(ll x,ll y, ll z){
  return (((x*y)%mod)*z)%mod;
}

int main(){
  ll H,W,A,B;
  cin >> H >> W >> A >> B;
  vector<ll> x(H+W-2),invx(H+W-2);
  x[0] = 1;
  invx[0] = 1;
  // 0 ~ H+W-3までの階乗を計算しておく
  for(int i=1;i<H+W-2;i++){
    x[i] = (x[i-1]*i)%mod;
    invx[i] = inv_mod(x[i],mod);
  }
  ll ret = 0;
  for(int i=B;i<W;i++){
    int c = H-A-1;
    int d = A-1;
    ret += (comb(x[i+c],invx[i],invx[c]) * comb(x[W-1-i+d],invx[W-1-i],invx[d])) % mod;
  }
  cout << ret%mod << endl;
  return 0;
}
