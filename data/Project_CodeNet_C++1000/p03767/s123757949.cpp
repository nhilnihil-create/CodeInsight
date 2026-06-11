#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int64_t> a(n * 3);
  rep(i, n * 3) cin >> a.at(i);

  sort(a.begin(), a.end());
  reverse(a.begin(), a.end());

  int64_t ans = 0;
  for (int i = 1; i < n * 2; i += 2) {
    ans += a.at(i);
  }
  cout << ans << endl;
  return 0;
}