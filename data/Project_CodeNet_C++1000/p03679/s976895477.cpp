#include <bits/stdc++.h>
using namespace std;

int main() {
  int X, A, B;
  cin >> X >> A >> B;
  string ans;
  if (B-A<=0) {
    ans = "delicious";
  }
  else if (B-A<=X) {
    ans = "safe";
  }
  else {
    ans = "dangerous";
  }
  cout << ans << endl;
}
