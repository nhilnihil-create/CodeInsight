#include <bits/stdc++.h>
using namespace std;
struct edge_t {
  int u, v, w;
  edge_t() = default;
  edge_t(int u, int v, int w) : u(u), v(v), w(w) {}
  friend bool operator<(const edge_t &lhs, const edge_t &rhs) {
    return lhs.w < rhs.w;
  }
};
int main() {
  int n;
  cin >> n;
  vector<int>a(3*n);
  for(int &i : a)cin>>i;
  vector<int64_t> pref(n + 1), suff(n + 1);
  {
    multiset<int> s1;
    multiset<int, greater<>> s2;
    for (int i = 0; i < n; ++i) {
      s1.insert(a[i]);
      pref[0] += a[i];
    }
    for (int i = 1; i <= n; ++i) {
      pref[i] += pref[i - 1];
      pref[i] -= *s1.begin();
      s2.insert(*s1.begin());
      s2.insert(a[i + n - 1]);
      s1.erase(s1.begin());
      pref[i] += *s2.begin();
      s1.insert(*s2.begin());
      s2.erase(s2.begin());
    }
  }
  {
    multiset<int, greater<>> s1;
    multiset<int> s2;
    for (int i = 0; i < n; ++i) {
      s1.insert(a[3 * n - 1 - i]);
      suff[0] += a[3 * n - 1 - i];
    }
    for (int i = 1; i <= n; ++i) {
      suff[i] += suff[i - 1];
      suff[i] -= *s1.begin();
      s2.insert(*s1.begin());
      s2.insert(a[2 * n - i]);
      s1.erase(s1.begin());
      suff[i] += *s2.begin();
      s1.insert(*s2.begin());
      s2.erase(s2.begin());
    }
  }
  int64_t ans = numeric_limits<int64_t>::min() / 2;
  for (int i = 0; i <= n; ++i) {
    ans = max(ans, pref[i] - suff[n - i]);
  }
  cout << ans << '\n';
  return 0;
}