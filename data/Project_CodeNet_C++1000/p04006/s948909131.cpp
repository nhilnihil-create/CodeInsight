#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ll N, x; cin >> N >> x;
  ll a[N], b[N];
  ll res = 0;
  for (ll i = 0; i < N; i++) {
    cin >> a[i]; b[i] = a[i]; res += b[i];
  }
  for (ll k = 1; k < N; k++) {
    for (ll i = 0; i < N; i++) {
      if (i-k >= 0) {b[i] = min(a[i-k],b[i]);}
      else {b[i] = min(a[i+N-k],b[i]);}
    }
    ll num = x*k;
    for (ll i = 0; i < N; i++) {num += b[i];}
    res = min(num,res);
  }
  cout << res << endl;
}