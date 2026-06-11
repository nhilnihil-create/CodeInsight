#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n, a, b;
  cin >> n >> a >> b;
  if (a > b) {
    cout << 0 << endl;
  } else if (n == 1) {
    if (a == b) cout << 1 << endl;
    else cout << 0 << endl;
  } else if (n == 2) {
    cout << 1 << endl;
  } else {
    ll s_min = (n-1LL) * a + b;
    ll s_max = (n-1LL) * b + a;
    ll ans = s_max - s_min + 1;
    cout << ans << endl;
  }
  return 0;
}