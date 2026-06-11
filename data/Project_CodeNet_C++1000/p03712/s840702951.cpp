#include <bits/stdc++.h>
using namespace std;

void solve() {
  int r,c;
  cin >> r >> c;
  char a[r][c];
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < c + 2; i++) {
    cout << "#";
  }
  cout << "\n";
  for (int i = 0; i < r; i++) {
    cout << "#";
    for (int j = 0; j < c; j++) {
      cout << a[i][j];
    }
    cout<< "#" << '\n';
  }
  for (int i = 0; i < c + 2; i++) {
    cout << "#";
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
 }
