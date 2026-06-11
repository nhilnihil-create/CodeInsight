#include <iostream>
using namespace std;
typedef long long ll;

const ll mod = 1e9+7;
ll v[200005], iv[200005];

ll pow_mod(ll x, ll a) {
  ll an = 1, xx = x;
  while(a) {
    if (a&1) an = an * xx % mod;
    xx = xx * xx % mod;
    a>>=1;
  }
  return an;
}

ll ncr(ll n, ll r) {
  return v[n] * iv[n-r] % mod * iv[r] % mod;
}

int main() {
  v[0] = v[1] = 1;
  for(int i=2; i<200005; i++) {
    v[i] = v[i-1] * i % mod;
  }
  iv[200004] = pow_mod(v[200004], mod-2);
  for(int i=200003; i>=0; i--) {
    iv[i] = iv[i+1] * (i+1) % mod;
  }
  
  int h, w, a, b; cin >> h >> w >> a >> b;
  ll an = 0;
  
  for(int i=0; i<h-a; i++) {
    an += ncr(b+i-1, i) * ncr(h-i+w-b-2, h-i-1) % mod;
    an %= mod;
    //cout << b+i << " " << i << " " << h-i+w-b <<" " << h-i << endl;
  }
  cout << an << endl;
}