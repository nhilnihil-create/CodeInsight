#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
  ll N; cin >> N;
  ll a[N];
  ll sum = 0; 
  bool ok = true;
  for (ll i = 0; i < N; i++) {
    cin >> a[i]; sum+=a[i];
  }
  if (sum % (N*(N+1)/2) != 0) {
    cout << "NO" << endl; return 0;
  }
  ll K = sum/(N*(N+1)/2);
  ll c[N];
  for (ll i = 0; i < N; i++) {
    ll x = a[(i+1)%N]-a[i];
    if (K < x || (K-x)%N != 0) {
      cout << "NO" << endl; return 0;
    }
    c[i] = (K-x)/N;
  }
  ll A = 0;
  for (ll i = 0; i < N; i++) {
    A += (N-i)*c[i];
  }
  if (A != a[0]) {
    cout << "NO" << endl; return 0;
  }
  cout << "YES" << endl;
}
