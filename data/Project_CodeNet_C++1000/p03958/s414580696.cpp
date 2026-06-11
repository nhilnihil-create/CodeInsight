#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using P = pair<ll, ll>;
template <class T>
using V = vector<T>;

int main() {
  int k, t;
  cin >> k >> t;

  V<int> a(t);
  rep(i, t) cin >> a[i];

  V<P> p = {{0, 0}};
  rep(i, t) p.push_back({a[i], i + 1});

  V<int> b = {0};
  int ans = 0;
  rep(i, k) {
    sort(p.rbegin(), p.rend());
    if (p[0].first == 0) break;
    if (b.back() != p[0].second) {
      b.push_back(p[0].second);
      p[0].first--;
    } else {
      if (p[1].first > 0) {
        b.push_back(p[1].second);
        p[1].first--;
      } else {
        ans++;
      }
    }
  }
  cout << ans << endl;
}
