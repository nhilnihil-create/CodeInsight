#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

int main() {
  std::string s;
  std::cin >> s;

  std::cout << s.front() << s.length() - 2 << s.back() << std::endl;

  return 0;
}