#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(int argc, const char *argv[]) {
  ll n;
  cin >> n;

  map<int, int> cnts;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    cnts[a]++;
  }

  if (n % 2 == 1 && cnts[0] > 1) {
    cout << 0 << '\n';
    return 0;
  }

  for (auto &p : cnts) {
    if (p.second > 2) {
      cout << 0 << '\n';
      return 0;
    }
  }

  ll md = 1e9 + 7;
  ll ans = 1;
  for (int i = 0; i < n / 2; ++i) {
    ans = ans * 2 % md;
  }

  cout << ans << '\n';
}