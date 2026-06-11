#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;

int main() {
  int N;
  cin >> N;

  int ans = 0;
  rep(_, N) {
    int l, r;
    cin >> l >> r;
    ans += (r - l + 1);
  }
  cout << ans << endl;
  return 0;
}