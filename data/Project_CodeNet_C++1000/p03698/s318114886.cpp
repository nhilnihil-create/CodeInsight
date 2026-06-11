#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {
  string s;
  std::cin >> s;

  sort(s.begin(), s.end());
  bool ok = true;
  rep(i, s.size() - 1) {
    if (s[i] == s[i + 1]) {
      ok = false;
    }
  }

  std::cout << (ok ? "yes" : "no") << std::endl;
  return 0;
}
