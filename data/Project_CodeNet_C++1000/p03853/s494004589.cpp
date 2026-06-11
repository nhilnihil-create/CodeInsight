#include <iostream>
#include <string>
#include <regex>

int main() {
  std::regex re(R"(\d+\s\d+)");
  std::string s;
  while(std::getline(std::cin, s))
    if (!std::regex_match(s, re)) std::cout << s << "\n" << s << "\n";
}
