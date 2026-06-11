#include <bits/stdc++.h>
using namespace std;

int main() {
  char a, b, ans;
  cin >> a >> b;

  if (a == 'H') {
    if (b == 'H') {
      ans = 'H';
    } else {
      ans = 'D';
    }
  } else {
    if (b == 'H') {
      ans = 'D';
    } else {
      ans = 'H';
    }
  }
  cout << ans << endl;
}
