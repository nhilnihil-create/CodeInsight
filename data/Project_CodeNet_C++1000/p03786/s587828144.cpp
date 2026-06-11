#include <string>
#include <memory>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main() {
  std::ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;

  cin >> n;
  std::vector<int> v(n);
  std::vector<int64_t> mxs;
  for (auto& el : v) {
    cin >> el;
  }

  std::sort(v.begin(), v.end());
  int64_t cur_sum = 0;
  for (const auto& el : v) {
    mxs.push_back(max((el - 2 * cur_sum + 1) / 2, (int64_t)0));
    cur_sum += el;
  }
  int ans = 0;
  int last = n - 1;
  for (int i = n - 1; i >= 0; i--) {
    if (mxs[i] != 0) {
      last = i;
      break;
    }
  }
  int64_t mx = 0;
  for (int i = 0; i < last; i++) {
    mx = max(mx, mxs[i]);
  }
  if (mx <= v[last]) {
    ans = 1;
  }
  mx = max(mx, mxs[last]);

  for (int i = last + 1; i < n; i++) {
    if (mx <= v[i]) {
      ans++;
    }
  }

  cout << ans << endl;
}