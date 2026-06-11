#include <iostream>
#include <string>

int main() {
  std::string s, tmp;
  std::cin >> s;

  tmp.push_back(s[0]);
  for (int i = 1; i < s.length(); i++) {
    if (tmp.back() != s[i]) {
      tmp.push_back(s[i]);
    }
  }
  s = tmp;

  std::cout << s.length() - 1 << "\n";

  return 0;
}