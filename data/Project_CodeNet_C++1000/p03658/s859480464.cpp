#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> l(n);
  rep(i, n) cin >> l.at(i);

  sort(l.begin(), l.end());
  reverse(l.begin(), l.end());

  int ans = 0;
  rep(i, k) ans += l.at(i);
  cout << ans << endl;
  return 0;
}