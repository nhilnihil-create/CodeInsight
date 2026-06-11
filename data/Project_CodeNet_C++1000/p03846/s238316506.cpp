#include <bits/stdc++.h>

#include <boost/range/adaptors.hpp>
#include <boost/range/irange.hpp>

using namespace std;
using namespace boost;
using namespace boost::adaptors;

main() {
  int64_t n;
  cin >> n;

  vector<int64_t> b(n);
  for (auto i : irange(0L, n)) {
    int64_t a;
    cin >> a;
    ++b[a];
  }

  for (auto i : irange(0L, n)) {
    if ((i + n) % 2 == 0) {
      if (b[i] != 0) {
        cout << 0 << endl;
        return 0;
      }
    } else if (i == 0) {
      if (b[i] != 1) {
        cout << 0 << endl;
        return 0;
      }
    } else {
      if (b[i] != 2) {
        cout << 0 << endl;
        return 0;
      }
    }
  }

  int64_t p = 1;
  constexpr auto M = 1000000007;

  for (auto _ : irange(0L, n / 2)) {
    p *= 2;
    p %= M;
  }

  cout << p << endl;
}