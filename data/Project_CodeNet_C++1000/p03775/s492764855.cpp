#include <cmath>
#include <iostream>

using namespace std;
using ll = long long;

ll F(ll a, ll b) {
  auto len = [](auto x) { return to_string(x).length(); };
  return max(len(a), len(b));
}

int main() {
  ll N, ans{11};
  cin >> N;
  for (ll a = 1, n = floor(sqrt(N)); a <= n; ++a) {
    if (N % a) continue;
    ans = min(ans, F(a, N / a));
  }
  cout << ans << endl;
}
