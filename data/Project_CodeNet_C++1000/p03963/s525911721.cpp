#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(int argc, const char *argv[]) {
  int n, k;
  cin >> n >> k;

  ll ans = k;
  for (int i = 0; i < n - 1; ++i) {
    ans *= k - 1;
  }

  cout << ans << '\n';
}