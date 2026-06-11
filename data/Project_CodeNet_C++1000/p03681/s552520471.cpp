#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<string,int>;
const double PI = acos(-1);

int main() {
  ll mod = pow(10,9)+7;
  ll n,m;
  cin >> n >> m;
  ll ans;
  if(abs(n-m) > 1) ans = 0;
  else {
    ll in = 1,im = 1;
    for(ll i = 1; i <= n; i++) {
      in*=i;
      in = in%mod;
    }
    for(ll i = 1; i <= m; i++) {
      im*=i;
      im = im%mod;
    }
    if(n == m) ans = (in*im)*2%mod;
    else ans = (in*im)%mod;
  }
  cout << ans << endl;
}