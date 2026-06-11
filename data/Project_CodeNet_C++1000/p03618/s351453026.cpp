#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin >> s;
  int n = s.length();
  vector <int> cnt(26, 0);
  for (int i = 0; i < n; i++) {
    cnt[s[i] - 'a']++;
  }
  long long ans = 1 + (long long) n * (n - 1) / 2;
  for (int x : cnt) {
    ans -= (long long) x * (x - 1) / 2;
  }
  cout << ans << endl;
  return 0;
}
