#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
#include <set>

int main() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  std::vector<int64_t> cnt(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  long long sum = std::accumulate(a.begin(), a.end(), 0LL);
  std::vector<int> od(n);
  std::iota(od.begin(), od.end(), 0);
  std::sort(od.begin(), od.end(), [&](int i, int j) { return a[i] > a[j]; });
  std::set<int> s, t;
  for (int i = 0; i < n; ++i) s.insert(i);
  for (int i = 0, j = 0; i < n; i = j) {
    for (j = i; j < n && a[od[i]] == a[od[j]]; ++j) {
      t.insert(od[j]);
      s.erase(od[j]);
    }
    if (!s.empty() && *s.begin() < *t.begin()) {
      int dist = a[od[i]] - a[od[j]]; 
      cnt[*t.begin()] += 1LL * dist * t.size();
      sum -= 1LL * dist * t.size();
    } else {
      cnt[*t.begin()] += sum;
      break;
    }
  }
  for (int i = 0; i < n; ++i) std::cout << cnt[i] << "\n";
}
