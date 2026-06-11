#include <bits/stdc++.h>
using namespace std;

void solve() {
  string a, b;
  cin >> a >> b;
  int la = (int) a.size();
  int lb = (int) b.size();
  if(la > lb) {
    cout << "GREATER";
  }
  else if(la < lb) {
    cout << "LESS";
  }
  else {
    for (int i = 0; i < la; i++) {
      if(a[i] > b[i]) {
        cout << "GREATER";
        return;
      }
      if(a[i] < b[i]) {
        cout << "LESS";
        return;
      }
    }
    cout << "EQUAL";
  }

}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}
