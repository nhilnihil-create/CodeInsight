#include <bits/stdc++.h>
using namespace std;

long long n;
string s;

int main() {
  cin >> s;
  n = s.size();
  long long res = n - 1;
  for (int i = 0; i < 26; ++i) {
    long long now = 0;
    for (int j = 0; j < n; ++j)
      if (i != s[j] - 'a') {
        long long cnt = 0;
        while (j < n && s[j] - 'a' != i) ++cnt, ++j;
        now = max(now, cnt);
      }
    res = min(res, now);
  }
  cout << res << endl;
  return 0;
}
