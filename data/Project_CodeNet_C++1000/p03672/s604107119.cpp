#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {
  string s;
  std::cin >> s;

  bool ok = false;
  while (!ok) {
    s.pop_back();
    int n = s.size();
    if (n % 2 != 0) {
      continue;
    }
    if (s.substr(0, n / 2) == s.substr(n / 2, n / 2)) {
      ok = true;
    }
  }

  std::cout << s.size() << std::endl;
  return 0;
}
