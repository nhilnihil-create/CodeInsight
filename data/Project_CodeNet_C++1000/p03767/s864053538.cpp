#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  int N;
  cin >> N;
  vector<ll> a(3 * N);

  for (int i{}; i < 3 * N; ++i) {
    cin >> a[i];
  }
  sort(a.begin(), a.end(), greater<int>());

  ll ans{};
  for (int i{0}; i < N; ++i) {
    ans += a[i * 2 + 1];
  }
  cout << ans << endl;
  return 0;
}
