#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;
    ans += r - l + 1;
  }
  cout << ans << endl;
}