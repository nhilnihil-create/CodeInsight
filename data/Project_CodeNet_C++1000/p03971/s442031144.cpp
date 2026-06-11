#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {
  int n, a, b;
  string s;
  std::cin >> n >> a >> b;
  std::cin >> s;

  int passed = 0;
  int b_rank = 0;

  rep(i, n) {
    if (s[i] == 'a') {
      if (passed < a + b) {
        std::cout << "Yes" << std::endl;
        passed++;
      } else {
        std::cout << "No" << std::endl;
      }
    } else if (s[i] == 'b') {
      b_rank++;
      if (passed < a + b && b_rank <= b) {
        std::cout << "Yes" << std::endl;
        passed++;
      } else {
        std::cout << "No" << std::endl;
      }
    } else {
      std::cout << "No" << std::endl;
    }
  }
  return 0;
}
