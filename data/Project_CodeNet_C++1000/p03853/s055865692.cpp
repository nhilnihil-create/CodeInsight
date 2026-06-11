#include <iostream>
int main() {
  std::string s;
  std::cin >> s >> s;
  while(std::cin >> s) std::cout << s << "\n" << s << "\n";
}
