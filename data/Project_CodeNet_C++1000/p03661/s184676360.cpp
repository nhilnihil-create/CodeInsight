#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
  int n; cin >> n;
  vector<ll> a(n);
  vector<ll> sum(n+1);
  sum[0] = 0;
  // [l, r) = sum(r) - sum(l)
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum[i+1] = sum[i] + a[i];
  }
  ll ans = 0xdeadbeef;
  for (int div = 1; div < n; div++) {
    ans = min(ans, abs(sum[div] - (sum[n] - sum[div])));
  }
  cout << ans << endl;
}
