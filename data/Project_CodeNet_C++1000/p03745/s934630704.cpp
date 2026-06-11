#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  vector<int> sub;
  rep(i, n - 1) {
    if (a[i] < a[i + 1]) {
      sub.push_back(1);
    } else if (a[i] > a[i + 1]) {
      sub.push_back(-1);
    }
  }

  int ans = 1;
  if (sub.size() > 1)
    rep(i, sub.size() - 1) if (sub[i] != sub[i + 1]) ans++, i++;
  cout << ans << endl;
  return 0;
}
