#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()

typedef long long ll;

const int N = 3e6;

void solve() {
  int n; cin >> n;
  vector<ll> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
  ll suf = 0;
  for (int i = n - 1; i >= 0; i--) {
    a[i] += suf;
    ll mult = (a[i] + b[i] - 1) / b[i];
    ll need = mult * b[i] - a[i];
    suf += need;
  }
  cout << suf;
}

// CHECK LIMITS (n <= 10^5)
// CHECK CORNER CASES (n == 1)

int main() {
  ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);
  cout.setf(ios::fixed), cout.precision(20);
  //cout << 1.0 * clock() / CLOCKS_PER_SEC << endl;
  solve();
}
