#include <bits/stdc++.h>
#include <iterator>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {
  string s;
  std::cin >> s;

  int minv = 101;
  for (char c : s) {
    int maxv = 0;
    rep(i, s.size()) {
      int num = 0;
      while (s[i] != c && i < s.size()) {
        i++;
        num++;
      }
      maxv = max(maxv, num);
    }
    minv = min(minv, maxv);
  }

  std::cout << minv << std::endl;

  return 0;
}
