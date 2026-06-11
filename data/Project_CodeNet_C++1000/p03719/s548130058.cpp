#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  string ans = "No";
  if (c >= a) {
    if (c <= b) {
      ans = "Yes";
    }
  }
  cout << ans << endl;
}