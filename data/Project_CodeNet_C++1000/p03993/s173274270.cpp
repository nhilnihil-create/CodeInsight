#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  rep(i, n) --a[i];

  int ans = 0;
  rep(i, n) if (i < a[i] && a[a[i]] == i) ++ans;
  cout << ans << endl;
  return 0;
}