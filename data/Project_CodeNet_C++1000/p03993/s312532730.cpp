#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int n, ans;

int main() {
  cin >> n;
  vector<int> a(n);
  rep (i, n) {
    cin >> a[i];
  }
  ans = 0;
  rep (i, n) {
    if (a[a[i]-1] == i+1) ans++;
  }
  cout << ans/2 << endl;
  return 0;
}
