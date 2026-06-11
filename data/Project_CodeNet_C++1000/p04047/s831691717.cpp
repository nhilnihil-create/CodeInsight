#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
  ll N; cin >> N;
  vector<ll> a;
  for (ll i = 0; i < 2*N; i++) {
    ll x; cin >> x; a.push_back(x);
  }
  sort(a.begin(), a.end());
  ll res = 0;
  for (ll i = 0; i < N; i++) {
    res += a[2*i];
  }
  cout << res << endl;
}