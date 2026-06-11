#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cassert>
#include <map>
#include <set>
using namespace std;

int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, x;
  cin >> n >> x;
  std::vector<int> v(n);
  for (auto& el : v) {
    cin >> el;
  }

  auto ind = std::min_element(v.begin(), v.end()) - v.begin();
  auto ans = (int64_t)1e18;
  for (int k = 0; k < n; k++) {
    int64_t sum = 0LL;
    multiset<int> st;
    for (int i = 0; i < k; i++) {
      st.insert(v[i]);
    }
    int cur = k;
    for (int i = 0; i < n; i++) {
      st.insert(v[cur]);
      sum += *st.begin();
      st.erase(st.find(v[(cur - k + n) % n]));
      cur++;
      cur %= n;
    }
    ans = min(ans, sum + (int64_t)x * k);

  }

  cout << ans << endl;




  return 0;
}