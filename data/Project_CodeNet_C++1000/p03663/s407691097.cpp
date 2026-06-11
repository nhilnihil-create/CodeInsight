#include <bits/stdc++.h>
using namespace std;

int len = 0;
string n;
void solve();

int main() {
  solve();
  cout << "! " << n << endl;
  return 0;
}

void solve() {
  auto send = [](string s) {
    cout << "? " << s << endl;
    string res;
    cin >> res;
    return res == "Y";
  };
  // search digit
  while (++len < 10)
    if (!send("1" + string(len, '0'))) break;
  // 10^(len) pattern
  if (len == 10) {
    len = 0;
    while (++len)
      if (send(string(len, '9'))) {
        n = "1" + string(len - 1, '0');
        return;
      }
  }
  // binary search
  for (int i = 1; i <= len; ++i) {
    int l = -(i != 1), r = 9;
    while (r - l > 1) {
      int mid = (l + r) / 2;
      if (send(n + (char)('0' + mid) + string(18 - i, '9')))
        r = mid;
      else
        l = mid;
    }
    n += '0' + r;
  }
}