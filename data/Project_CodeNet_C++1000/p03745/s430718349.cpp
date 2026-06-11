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
  
  int state = 0;
  int ans = 1;
  for (int i = 1; i < n; ++i) {
    if (state == 0) {
      if (a[i] - a[i-1] > 0) state = 1;
      else if (a[i] - a[i-1] < 0) state = -1;
    } else if (state == 1) {
      if (a[i] - a[i-1] < 0) {
        ++ans;
        state = 0;
      }
    } else {
      if (a[i] - a[i-1] > 0) {
        ++ans;
        state = 0;
      }
    }
  }
  cout << ans << endl;

  return 0;
}