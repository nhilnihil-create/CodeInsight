#include <algorithm>
#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {
  string s;
  std::cin >> s;

  string a;
  rep(i, s.size()) {
    if (s[i] == 'B') {
      if (!a.empty()) {
        a.pop_back();
      }
    } else {
      a += s[i];
    }
  }

  std::cout << a << std::endl;
  return 0;
}
