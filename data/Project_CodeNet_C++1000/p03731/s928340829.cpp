#include <bits/stdc++.h>

#include <boost/range/adaptors.hpp>
#include <boost/range/irange.hpp>

using namespace std;
using namespace boost;
using namespace boost::adaptors;

main() {
  int64_t n, T;
  cin >> n >> T;

  int64_t ans = n * T;
  int64_t e;
  for (auto i : irange(0L, n)) {
    int64_t t;
    cin >> t;

    if (i > 0 && t < e) {
      ans -= (e - t);
    }
    e = t + T;
  }

  cout << ans << endl;
}