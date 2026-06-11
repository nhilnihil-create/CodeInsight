#include <bits/stdc++.h>

int main(void)
{
  std::string a, b, c;
  std::cin >> a >> b >> c;

  std::string ans;
  char now_str = 'a';
  size_t A = 0;
  size_t B = 0;
  size_t C = 0;

  while (true) {
    if (now_str == 'a') {
      if (A == a.size()) {
        ans = "A";
        break;
      }

      now_str = a.at(A);
      A++;
    }
    else if (now_str == 'b') {
      if (B == b.size()) {
        ans = "B";
        break;
      }

      now_str = b.at(B);
      B++;
    }
    else {
      if (C == c.size()) {
        ans = "C";
        break;
      }

      now_str = c.at(C);
      C++;
    }
  }

  std::cout << ans << std::endl;

  return 0;
}