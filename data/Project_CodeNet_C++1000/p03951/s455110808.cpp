#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {
  int n;
  string s, t;
  std::cin >> n >> s >> t;

  int length = 0;
  rep(i, n) {
    if (s.substr(i) == t.substr(0, n - i)) {
      length = n + i;
      break;
    }
    length = n * 2;
  }

  std::cout << length << std::endl;

  return 0;
}
