#include <iostream>
#include <string>

int main() {
  std::string s;
  std::cin >> s;
  s[5] = s[13] = ' ';
  std::cout << s << "\n";
  return 0;
}