#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n, p;
  cin >> n >> p;
  int odd = 0, evn = 0;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if (a & 1) {
      odd++;
    } else {
      evn++;
    }
  }

  ll ans;
  if (p) {
    if (!odd) {
      ans = 0;
    } else {
      ans = 1LL << (n - 1);
    };
  } else {
    if (!odd) {
      ans = 1LL << n;
    } else {
      ans = 1LL << (n - 1);
    }
  }

  cout << ans << endl;
  return 0;
}
