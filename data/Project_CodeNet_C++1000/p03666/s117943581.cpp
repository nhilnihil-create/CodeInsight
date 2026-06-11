#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
  ll N, a, b, c, d; cin >> N >> a >> b >> c >> d;
  bool ok = false;
  for (ll i = 0; i <= N-1; i++) {
    if (i*c-(N-1-i)*d <= b-a && b-a <= i*d-(N-1-i)*c) ok = true;
  }
  if (ok) {cout << "YES" << endl;}
  else {cout << "NO" << endl;}
}