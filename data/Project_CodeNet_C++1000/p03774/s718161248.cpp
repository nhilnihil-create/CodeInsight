#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main(void) {
  int n, m;
  cin >> n >> m;
  vector<P> a(n);
  rep(i, n) {
    cin >> a[i].first >> a[i].second;
  }
  vector<P> c(m);
  rep(i, m) {
    cin >> c[i].first >> c[i].second;
  }

  rep(i, n) {
    int dist = 1000000000;
    int ans;
    rep(j, m) {
      int d = abs(a[i].first - c[j].first) + abs(a[i].second - c[j].second);
      if (d < dist) {
        dist = d;
        ans = j + 1;
      }
    }
    cout << ans << endl;
  }
  
  return 0;
}