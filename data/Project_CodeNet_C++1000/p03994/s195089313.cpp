#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;
  int n, k;
  cin >> s >> k;
  n = (int) s.size();
  for (int i = 0; i < n; i++) {
    if (s[i] == 'a') {
      continue;
    }
    int x = s[i] - 'a';
    int need = 26 - x;
    if (need <= k) {
      k -= need;
      s[i] = 'a';
    }
  }
  int x = s[n - 1] - 'a';
  x = (x + k) % 26;
  s[n - 1] = (x + 'a');
  cout << s << "\n";
}
