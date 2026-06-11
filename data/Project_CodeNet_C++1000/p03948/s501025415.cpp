#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  ll n, t;
  cin >> n >> t;
  vector<ll> a(n, 0LL);
  vector<ll> m(n, 0LL);
  for(int i=0; i<n; i++) {
    cin >> a[i];
  }
  m[n-1] = a[n-1];
  for(int i=n-2; i>=0; i--) {
    m[i] = max(a[i], m[i+1]);
  }
  vector<ll> d(n, 0LL);
  ll dmax = -1;
  for(int i=0; i<n; i++) {
    d[i] = m[i]-a[i];
    dmax = max(dmax, d[i]);
  }
  int ans = 0;
  for(int i=0; i<n; i++) {
    if(dmax==d[i]) ans++;
  }
  cout << ans << endl;
  return 0;
}

