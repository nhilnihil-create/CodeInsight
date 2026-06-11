#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> a(3 * n);
  rep(i, 3 * n) cin >> a[i];
  sort(a.begin(), a.end());
  ll ans = 0;
  for(int i = 0; i < n; i++) {
    int idx = a.size() - 2 * (i + 1);
    ans += a[idx];
  } 
  cout << ans << endl;
  return 0;
}
