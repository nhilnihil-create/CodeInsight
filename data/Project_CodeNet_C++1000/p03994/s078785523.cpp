#include <bits/stdc++.h>
using namespace std;

string s;
int k, n;

int main() {
  cin >> s >> k;
  n = s.size();
  for (int i = 0; i < n; ++i) {
    int now = (26 - (s[i] - 'a')) % 26;
    if (k >= now) {
      k -= now;
      s[i] = 'a';
    }
    if (i == n - 1) s[i] = (s[i] - 'a' + k) % 26 + 'a';
  }
  cout << s << endl;
  return 0;
}