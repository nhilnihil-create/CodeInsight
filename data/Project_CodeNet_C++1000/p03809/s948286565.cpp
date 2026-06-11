#include <bits/stdc++.h>
#include <boost/range/irange.hpp>

using namespace std;
using namespace boost;

int64_t dfs(const vector<vector<int64_t>>& links, const vector<int64_t>& a, int64_t current, int64_t parent) {
  if (links[current].size() == 1 && parent >= 0) {
    return a[current];
  }

  int64_t s = 0;
  int64_t m = 0;
  for (auto v : links[current]) {
    if (v == parent) {
      continue;
    }
    auto tmp = dfs(links, a, v, current);
    if (tmp < 0) {
      return -1;
    }
    
    m = max(m, tmp);
    s += tmp;
  }
  
  
  
  int64_t l = a[current];
  int64_t k = s - l;
  if (k < 0 || k > l || 2 * k > s) {
    return -1;
  }
  
  if (m >= s - m) {
    if (k <= s - m) {
      return l - k;
    } else {
      return -1;
    }
  } else {
    if (k <= s / 2) {
      return l - k;
    } else {
      return -1;
    }
  }
}

main() {
  int64_t n;
  cin >> n;
  
  vector<int64_t> a(n);
  for (auto&& aa : a) {
    cin >> aa;
  }
  
  vector<vector<int64_t>> links(n);
  for (auto _ : irange(0L, n - 1)) {
    int64_t x, y;
    cin >> x >> y;
    --x;
    --y;
    links[x].push_back(y);
    links[y].push_back(x);
  }
  
  auto ret = dfs(links, a, 0, -1);
  cerr << ret << endl;
  if (ret < 0 || (ret != 0 && links[0].size() > 1)) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
  }  
}