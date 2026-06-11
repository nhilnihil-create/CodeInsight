#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll n, a, b;
  cin >> n >> a >> b;
  ll ans;
  if (a > b) {
    ans = 0;
  } else if (n == 1) {
    if (a != b) {
      ans = 0;
    } else {
      ans = 1;
    }
  } else {
    ans = (b - a) * (n - 2) + 1;
  }
  cout << ans << endl;
  return 0;
}
