#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  int k;
  cin >> s >> k;
  int n = s.size();
  for (int i = 0; i + 1 < n; i++) {
    int c = 'z' - s[i];
    c++;
    if (c <= k && c != 26) {
      k -= c;
      s[i] = 'a';
    }
  }

  if (0 < k) {
    int c = 'z' - s.back();
    c++;
    if (c <= k) {
      k -= c;
      s.back() = 'a';
      if (0 < k) {
        k %= 26;
        s.back() = (char)('a' + k);
      }
    } else {
      s.back() = (char)(s.back() + k);
    }
  }
  cout << s << endl;

  return 0;
}