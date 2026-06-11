#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {
  int n;
  string s;
  std::cin >> n >> s;

  int x = 0, maxv = 0;
  rep(i, n) {
    if (s[i] == 'I') {
      x++;
    } else {
      x--;
    }
    maxv = max(maxv, x);
  }

  std::cout << maxv << std::endl;
  return 0;
}
