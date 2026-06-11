#include <algorithm>
#include <iostream>
#include <set>
#include <stdio.h>
#include <vector>
typedef long long ll;

int main() {
  int n;
  int m;
  std::cin >> n;
  std::vector<int> a;
  for (int i = 0; i < n; i++) {
    int num;
    std::cin >> num;
    a.push_back(num - 1);
  }
  std::vector<ll> pos(n, 0);
  for (int i = 0; i < n; i++) {
    pos[a[i]] = i;
  }

  std::set<int> f_pos;
  std::set<int> r_pos;
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ll right;
    if (f_pos.lower_bound(pos[i]) != f_pos.end()) {
      right = *f_pos.lower_bound(pos[i]) - pos[i];
    } else {
      right = n - pos[i];
    }
    ll left;
    if (r_pos.lower_bound(n - 1 - pos[i]) != r_pos.end()) {
      left = *r_pos.lower_bound(n - 1 - pos[i]) - (n - 1 - pos[i]);
    } else {
      left = pos[i] + 1;
    }
    // std::cerr << left << ", " << right << ", " << pos[i] << std::endl;

    ans += left * right * (i + 1);
    f_pos.insert(pos[i]);
    r_pos.insert(n - 1 - pos[i]);
  }
  std::cout << ans << std::endl;
}
