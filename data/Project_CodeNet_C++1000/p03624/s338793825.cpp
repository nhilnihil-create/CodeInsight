#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {
  string s;
  std::cin >> s;

  char alphab = 'a';
  bool ok = false;

  rep(i, 26) {
    bool dup = false;
    rep(j, s.size()) {
      if (alphab + i == s[j]) {
        dup = true;
        break;
      }
    }
    if (!dup) {
      ok = true;
      alphab += i;
      break;
    }
  }

  if (ok) {
    std::cout << alphab << std::endl;
  } else {
    std::cout << "None" << std::endl;
  }
  return 0;
}
