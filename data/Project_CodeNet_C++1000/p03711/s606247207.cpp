#include <bits/stdc++.h>
using namespace std;

void solve() {
  int x, y;
  cin >> x >> y;
  int a[3][7]= {{1, 3, 5, 7, 8, 10, 12}, {4, 6, 9, 11,0,0,0}, {2,0,0,0,0,0,0}};
  vector<int>ans(3);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 7; j++) {
      if(a[i][j] == x || a[i][j] == y) {
        ans[i]++;
      }
    }
  }
  for (auto x : ans) {
    if(x == 2) {
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
