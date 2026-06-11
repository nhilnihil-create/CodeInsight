#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

std::string cons_s[] = {"resare", "remaerd", "maerd", "esare"};

int main() {
  std::string s;
  std::cin >> s;
  std::reverse(s.begin(), s.end());
  bool found = true;
  while (found) {
    found = false;
    for (int i = 0; i < 4; i++) {
      int index = s.find(cons_s[i]);
      if (index == 0) {
        s.erase(0, cons_s[i].length());
        found = true;
      }
    }
    if (s.length() == 0) {
      std::cout << "YES" << "\n";
      break;
    }
  }
  if (!found) {
    std::cout << "NO" << "\n";
  }

  return 0;
}