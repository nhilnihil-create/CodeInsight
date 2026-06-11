#include <bits/stdc++.h>
#include <vector>

using namespace std;
using ll = long long;

int main(int argc, const char *argv[]) {
  ll n, x;
  cin >> n >> x;

  vector<ll> va(n);
  for (int i = 0; i < n; ++i) {
    cin >> va[i];
  }

  ll ans = 0;
  if (va.front() > x) {
    ans += va.front() - x;
    va[0] = x;
  }

  for (int i = 1; i < va.size(); ++i) {
    ll sum = va[i] + va[i - 1];
    if (sum > x) {
      va[i] -= sum - x;
      ans += sum - x;
    }
  }

  cout << ans << '\n';
}