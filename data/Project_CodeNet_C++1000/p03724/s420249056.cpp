#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
  ll N, M; cin >> N >> M;
  map<ll,ll> leg;
  for (ll i = 0; i < M; i++) {
    ll x, y; cin >> x >> y;
    leg[x]++; leg[y]++;
  }
  bool ok = true;
  for (ll i = 1; i <= 1e5; i++) {
    if (leg[i]%2 == 1) ok = false;
  }
  if (ok) {cout << "YES" << endl;}
  else {cout << "NO" << endl;}
}