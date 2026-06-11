#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (long long i = 0; i < (n); ++i)
#define repr(i, a, b) for (auto i = (a); i < (b); ++i)
#define itr(x, c) for (auto&& x : (c))
#define updatemax(t, v) ((t) = std::max((t), (v)))
#define updatemin(t, v) ((t) = std::min((t), (v)))
#define endl _endl
const char _endl = (cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout.precision(16), '\n');

void solve(long long n, std::vector<long long> a) {
  ll r1 = 0, r2 = 0, r1s = 0, r2s = 0;
  rep(i, n) {
    r1s += a[i];
    r2s += a[i];
    if (i % 2 == 0) {
      if (r1s <= 0) {
        r1 += abs(r1s - (1));
        r1s = 1;
      }
      if (r2s >= 0) {
        r2 += abs(r2s - (-1));
        r2s = -1;
      }
    } else {
      if (r2s <= 0) {
        r2 += abs(r2s - (1));
        r2s = 1;
      }
      if (r1s >= 0) {
        r1 += abs(r1s - (-1));
        r1s = -1;
      }
    }
  }
  cout << min(r1, r2) << endl;
}

int main() {
  long long n;
  scanf("%lld", &n);
  std::vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    scanf("%lld", &a[i]);
  }
  solve(n, std::move(a));
}
