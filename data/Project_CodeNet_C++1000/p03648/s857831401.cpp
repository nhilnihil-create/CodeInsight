#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void) {
  ll k;
  cin >> k;

  ll n = 50;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    a[i] = 51 * (k / 50) - k + 49;
  }

  int r = k % 50;
  for (int i = 0; i < r; i++) {
    a[i] += 51;
  }

  cout << n << endl;
  for (int i = 0; i < n; i++) {
    if (i) cout << " ";
    cout << a[i];
  }
  cout << endl;

  return 0;
}