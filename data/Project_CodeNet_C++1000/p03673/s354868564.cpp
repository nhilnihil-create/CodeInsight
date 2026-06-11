#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)

using namespace std;

using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  vector<int> res;
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0) {
      res.push_back(a.at(i));
    } else {
      res.insert(res.begin(), a.at(i));
    }
  }
  if (n % 2 == 1) {
    reverse(res.begin(), res.end());
  }
  rep(i, n) {
    cout << res.at(i);
    if (i != n - 1) {
      cout << " ";
    }
  }
  cout << endl;
  return 0;
}
