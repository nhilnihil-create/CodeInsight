#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  string ans;
  if (a == 1 && b != 1) {
    ans = "Alice";
  }
  else if (a != 1 && b == 1) {
    ans = "Bob";
  }
  else if (a > b) {
    ans = "Alice";
  }
  else if (a < b) {
    ans = "Bob";
  }
  else {
    ans = "Draw";
  }
  cout << ans << endl;
}
