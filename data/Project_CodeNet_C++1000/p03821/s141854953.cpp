#include <iostream>

using namespace std;

typedef long long ll;

const int MAX_N = 1e5 + 5;

ll a [MAX_N], b [MAX_N];

ll cfrac (ll p, ll q) {
  return (p + q - 1) / q;
}

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }

  ll cur = 0;
  for (int i = n - 1; i >= 0; i--) {
    ll k = cfrac(a[i] + cur, b[i]);
    cur = k * b[i] - a[i];
  }
  cout << cur << endl;
}
