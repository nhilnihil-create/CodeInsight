#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  string s;
  cin >> n >> s;
  int mn = 0, cnt = 0;
  for (char c : s) {
    if (c == '(') {
      ++cnt;
    } else {
      --cnt;
    }
    mn = min(mn, cnt);
  }
  cout << string(-mn, '(') << s << string(cnt - mn, ')') << endl;
}
