#include <bits/stdc++.h>
#include <boost/range/irange.hpp>

using namespace std;
using namespace boost;

main() {
  int64_t n, m;
  cin >> n >> m;
  
  vector<int64_t> a(n);
  for (auto&& aa : a) {
    cin >> aa;
  }

  int64_t loop = 0;
  vector<int64_t> e(m + 1);
  int64_t prev = a[0];
  for (auto i : irange(1L, n)) {
    auto aa = a[i];
    if (a[i] < prev) {
      ++loop;
      e[aa] += a[i] + m - prev;
    } else {
      e[aa] += a[i] - prev;
    }
    prev = aa;
  }
  
  int64_t c = 0;
  int64_t p = 0;
  int64_t l = numeric_limits<int64_t>::min(), l_i = 0;
  for (auto i : irange(1L, m + 1)) {
    if ((a.front() < i && i <= a.back())) {
      p += loop + 1;
    } else if ((a.front() < a.back()) || (a.back() <= a.front() && a.front() < i) || (i <= a.back() && a.back() <= a.front())) {
      p += loop;
    } else {
      p += loop - 1;
    }
    if (p > l) {
      l = p;
      l_i = i;
    }
    p -= e[i];
  }
  
  cerr << l_i << endl;
  
  prev = a[0];
  int64_t ans = 0;
  for (auto i : irange(1L, n)) {
    auto aa = a[i];
    if (prev <= aa) {
      if (prev < l_i && l_i <= aa) {
        ans += 1 + aa - l_i;
      } else {
        ans += aa - prev;
      }
    } else {
      if (prev < l_i) {
        ans += 1 + (aa + m - l_i);
      } else if (l_i <= aa) {
        ans += 1 + (aa - l_i);
      } else {
        ans += aa + m - prev;
      }
    }
    prev = aa;    
  }
  cout << ans << endl;
}