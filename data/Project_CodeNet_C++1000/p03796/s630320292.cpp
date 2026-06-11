#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  ll ans = 1;
  for (ll i = 2; i <= n; i++) {
    ans = ans * i % 1000000007;
  }
  cout << ans << endl;
  return 0;
}
