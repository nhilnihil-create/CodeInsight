#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
using namespace std;
using ll = int64_t;
#define rep(i, j, n) for (int i = j; i < (n); ++i)
#define rrep(i, j, n) for (int i = (n)-1; j <= i; --i)

template <typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T>& a) {
  os << "{";
  for (size_t i = 0; i < a.size(); ++i) os << (i > 0 ? "," : "") << a[i];
  return os << "}";
}

[[maybe_unused]] constexpr ll MOD = 1000000007;
[[maybe_unused]] constexpr int INF = 0x3f3f3f3f;
[[maybe_unused]] constexpr ll INFL = 0x3f3f3f3f3f3f3f3fLL;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
int main() {
  int n;
  cin >> n;
  ll ans = 1;
  rep(i, 0, n) {
    ll t;
    cin >> t;
    ans = lcm(ans, t);
  }
  cout << ans << endl;
  return 0;
}
