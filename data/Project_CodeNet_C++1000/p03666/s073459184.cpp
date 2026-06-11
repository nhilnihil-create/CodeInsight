#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(int argc, const char *argv[]) {
  ll n, a, b, c, d;
  cin >> n >> a >> b >> c >> d;

  bool ans = false;
  for (int i = 0; i < n && !ans; ++i) {
    ll min_s = -d * i + c * (n - 1 - i);
    ll max_s = -c * i + d * (n - 1 - i);
    ll diff = a - b;
    if (min_s <= diff && max_s >= diff) {
      ans = true;
    }
  }

  cout << (ans ? "YES" : "NO") << '\n';
}