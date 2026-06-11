#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll mod = 1000000007;
int main() {
  int n; cin >> n;
  ll res = 1;
  ll cnt = 0;
  ll pos = -1;
  vector<ll> fact(n+1, 1);
  for (int i = 1; i <= n; i++) fact[i] = (fact[i-1] * i) % mod;
  while (n--) {
    ll x; cin >> x; cnt++;
    if (n && x == pos + 1) {
      (res *= cnt--) %= mod;
    } else if (!n) {
      (res *= fact[cnt]) %= mod;
    } else {
      pos += 2;
    }
  }
  cout << res << endl;
}