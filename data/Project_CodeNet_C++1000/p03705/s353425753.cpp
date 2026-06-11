#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll n, a, b;
  cin >> n >> a >> b;
  if (a > b) {
    cout << 0 << endl;
    return 0;
  }
  if (n == 1) {
    if (a == b) {
      cout << 1 << endl;
    } else {
      cout << 0 << endl;
    }
    return 0;
  }

  ll mn = (n - 1) * a + b;
  ll mx = a + (n - 1) * b;

  cout << mx - mn + 1 << endl;
}