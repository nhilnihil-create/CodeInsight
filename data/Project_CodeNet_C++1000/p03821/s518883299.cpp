#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  ll a[n], b[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }

  ll cnt = 0;
  ll push = 0;
  for (int i = n - 1; i >= 0; i--) {
    a[i] += cnt;
    push = a[i] % b[i];
    if (push) {
      cnt += b[i] - push;
    }
  }

  cout << cnt << endl;
  return 0;
}
