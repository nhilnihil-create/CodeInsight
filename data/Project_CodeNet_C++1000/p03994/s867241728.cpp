#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int k;
  cin >> k;

  for (int i = 0; i < s.size(); ++i) {
    int d = (26 - (s[i] - 'a')) % 26;
    if (d == 0)
      continue;
    if (d <= k) {
      s[i] = 'a';
      k -= d;
    }
  }
  if (k > 0)
    s.back() = 'a' + (s.back() - 'a' + (k % 26)) % 26;

  cout << s << endl;
}