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
  int n, c, k;
  cin >> n >> c >> k;

  std::vector<int> v(n);
  for (auto& el : v) {
    cin >> el;
  }

  sort(v.begin(), v.end());
  int cur = v[0];
  int cnt = 1;
  int ans = 1;
  for (int i = 1; i < n; i++) {
    if (v[i] - cur <= k && cnt + 1 <= c) {
      cnt++;
      continue;
    } else {
      cur = v[i];
      cnt = 1;
      ans++;
    }
  }
  cout << ans << endl;
}