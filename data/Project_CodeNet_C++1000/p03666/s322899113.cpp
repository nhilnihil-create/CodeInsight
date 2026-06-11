#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  ll n, a, b, c, d;
  cin >> n >> a >> b >> c >> d;

  bool ok = false;
  for (int m = 0; m <= n - 1; m++) {
    ll lo = - d * m + c * (n - 1 - m);
    ll hi = d * (n - 1 - m) - c * m;
    if (b - a >= lo && b - a <= hi) ok = true;
  }

  if (ok) cout << "YES\n";
  else cout << "NO\n";
}
