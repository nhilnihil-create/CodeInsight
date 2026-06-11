#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int INF = 1e9;

int main() {
  ll n, mina = 0, minb = 0, suma = 0, sumb = 0;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  rep(i, n) {
    suma += a[i];
    if (i % 2 == 0) {
      if (suma <= 0) {
        mina += abs(suma) + 1;
        suma += abs(suma) + 1;
      }
    } else {
      if (suma >= 0) {
        mina += abs(suma) + 1;
        suma -= abs(suma) + 1;
      }
    }
  }

  rep(i, n) {
    sumb += a[i];
    if (i % 2 != 0) {
      if (sumb <= 0) {
        minb += abs(sumb) + 1;
        sumb += abs(sumb) + 1;
      }
    } else {
      if (sumb >= 0) {
        minb += abs(sumb) + 1;
        sumb -= abs(sumb) + 1;
      }
    }
  }

  cout << min(mina, minb) << endl;
  return 0;
}
