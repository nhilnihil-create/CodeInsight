#include <iostream>
#include <string>

int main() {
  std::string s;
  std::cin >> s;
  if (s.size() <=3) {
    std::cout << "No" << std::endl;
  } else {
    if (s[0] == 'Y' && s[1] == 'A' && s[2] == 'K' && s[3] == 'I') {
      std::cout << "Yes" << std::endl;
    } else {
      std::cout << "No" << std::endl;
    }
  }
  return 0;
}
