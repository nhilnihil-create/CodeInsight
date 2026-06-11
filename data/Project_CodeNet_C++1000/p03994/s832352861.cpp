#include <bits/stdc++.h>
using namespace std;

int main(void) {
  string s;
  long long K;
  cin >> s >> K;
  for (int i = 0; i < s.length(); i++) {
    int index = s[i] - 'a';
    if (index == 0) continue;
    if (26 - index <= K) {
      K -= 26 - index;
      s[i] = 'a';
    }
  }
  s[s.length() - 1] += K % 26;
  s[s.length() - 1] = (s[s.length() - 1] - 'a') % 26 + 'a';
  cout << s << endl;
  return 0;
}