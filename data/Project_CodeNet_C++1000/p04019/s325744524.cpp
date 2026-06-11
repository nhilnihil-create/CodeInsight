#include <iostream>
#include <set>
#include <string>

int main(int argc, char *argv[]) {
  std::string s;
  std::cin >> s;
  std::set<char> c;
  for (auto &i : s)
    c.insert(i);
  if (c.find('N') != c.end() && c.find('S') != c.end() && c.size() == 2)
    std::cout << "Yes" << std::endl;
  else if (c.find('E') != c.end() && c.find('W') != c.end() && c.size() == 2)
    std::cout << "Yes" << std::endl;
  else if (c.size() == 4)
    std::cout << "Yes" << std::endl;
  else
    std::cout << "No" << std::endl;
}
