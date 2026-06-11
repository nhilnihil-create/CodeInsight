#include <bits/stdc++.h>
using namespace std;

void solve() {
  int a, b, c;
  cin >> a >> b >> c;
  if (c >= a && c <= b) {
    cout << "Yes";
  }
  else {
    cout << "No";
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}

