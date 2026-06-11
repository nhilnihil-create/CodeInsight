#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

int main() {
  int x, y;
  cin >> x >> y;
  vector<int> a = {1, 3, 5, 7, 8, 10, 12};
  vector<int> b = {4, 6, 9, 11};
  bool ans = false;
  rep(i, a.size()) {
    if (x == a.at(i)) {
      rep(j, a.size()) {
        if (y == a.at(j)) ans = true;
      }
    }
  }
  rep(i, b.size()) {
    if (x == b.at(i)) {
      rep(j, b.size()) {
        if (y == b.at(j)) ans = true;
      }
    }
  }
  if (ans == true) cout << "Yes" << endl;
  else cout << "No" << endl;
}