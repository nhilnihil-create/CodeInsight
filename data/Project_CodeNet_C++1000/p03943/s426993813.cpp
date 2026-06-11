#include <bits/stdc++.h>
using namespace std;


void solve() {
  int a[3];
  int sum = 0;
  for (int i = 0; i < 3; i++) {
    cin >> a[i];
    sum += a[i];
  }
  for (int i = 0; i < 3; i++) {
    if(sum - a[i] == a[i]) {
      cout << "Yes";
      return;
    }
  }
  cout << "No";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}
