#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

const ll mod = 1e9 + 7;
ll fact[100005];
ll ans;
int main() {
  int n;
  cin >> n;
   ll last = 0;
  vector<ll> l;
  ll k = 1;
  fact[0] = 1;
  for(ll i = 1; i <= n + 1; i++) fact[i] = fact[i-1] * i % mod;

  for(int i = 0; i < n - 1; i++) {
    ll x;
    cin >> x;
    if(x >= 2 * k - 1) k++;
    else {
      // cout << x <<"  "<<2 * k - 1 << endl;
      l.push_back(k);
      last++;
    }
  }
  reverse(l.begin(),l.end());
  ll x;
  cin >> x;

  if(l.size() == 0) cout << fact[n] << endl;
  else {
    ll tmp = l[0] * fact[n-last] % mod;
    //  cout << l[0] <<"  "<<n - last << endl;
    for(ll i = 1; i < l.size(); i++) {
      tmp = l[i] * tmp % mod;
    }
    cout << tmp << endl;
  }
}
  
