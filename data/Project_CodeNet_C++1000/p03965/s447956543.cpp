#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;

  int ans = 0;
  int cnt = 0;
  for (int i = 0; i < s.size(); ++i) {
    if (cnt == 0) {
      if (s[i] == 'p') {
        --ans;
      }
      ++cnt;
    } else {
      if (s[i] == 'g') {
        ++ans;
      }
      --cnt;
    }
  }
  cout << ans << endl;
}